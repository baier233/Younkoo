#include "HookManager.h"
#include <hotspot/java_hook.h>
#include <jni/types/Env.hpp>
#include <hotspot/classes/compile_task.h>
#include <utils/Pattern.h>
static std::vector<java_hotspot::method*> methods_being_hooked;
static std::vector<java_hotspot::method*> methodes_dont_compile;
static std::vector<java_hotspot::instance_klass*> klasses_dont_compile;
static void detour_invoke_compiler_on_method(java_hotspot::compile_task* task);
static void detour_do_analysis(void** ciMethodBlocks);
static bool detour_ok_to_inline(void* inlinetree,
	void* callee_method,
	void* jvms,
	void* profile,
	bool* should_delay);
static TitanHook<decltype(&detour_invoke_compiler_on_method)> _invoke_compiler_on_method_hook;
static TitanHook<decltype(&detour_do_analysis)> _do_analysis_hook;
static TitanHook<decltype(&detour_ok_to_inline)> _ok_to_inline_hook;

void HookManager::clean() {
	for (auto ptr : methods_being_hooked)
	{
		auto method = reinterpret_cast<java_hotspot::method*>(ptr);
		method->remove_all_break_points();
	}
	JavaHook::JVM::clean();
	_invoke_compiler_on_method_hook.RemoveHook();
	_do_analysis_hook.RemoveHook();
	_ok_to_inline_hook.RemoveHook();
}

static void detour_invoke_compiler_on_method(java_hotspot::compile_task* task) {
	//TODO : hook ok_to_inline to improve performance
	auto method = task->get_method();
	auto holder = method->get_const_method()->get_constants()->get_pool_holder();
	//std::cout << "Compiling method :" << method->get_name() << std::endl;
	for (auto pMethod : methodes_dont_compile)
	{
		if (method == pMethod)
		{
			//std::cout << "Force break compile of " << static_cast<java_hotspot::instance_klass*>(current_pool_holder)->get_name()->to_string() << std::endl;
			return;
		}
	}

	for (auto pMethod : methods_being_hooked)
	{
		if (method == pMethod)
		{
			//std::cout << "Force break compile of " << static_cast<java_hotspot::instance_klass*>(current_pool_holder)->get_name()->to_string() << std::endl;
			return;
		}
	}

	for (auto klass : klasses_dont_compile)
	{
		if (klass == holder)
		{
			//std::cout << "Force break compile of " << static_cast<java_hotspot::instance_klass*>(current_pool_holder)->get_name()->to_string() << std::endl;
			return;
		}
	}

	_invoke_compiler_on_method_hook.GetOrignalFunc()(task);
}
void detour_do_analysis(void** ciMethodBlocks)
{
	static VMStructEntry* _metadata_entry = JVMWrappers::find_type_fields("ciMetadata").value().get()[
		"_metadata"];
	auto method = *reinterpret_cast<java_hotspot::method**>(*reinterpret_cast<uint8_t**>(ciMethodBlocks) + _metadata_entry->offset);
	//std::cout << method->get_name() << std::endl;
	for (auto pMethod : methods_being_hooked)
	{
		if (method == pMethod)
		{
			std::cout << "Force break analysis of " << pMethod->get_name() << std::endl;

			return;
		}
	}

	//std::cout << "loading method's code :" << method->get_name() << " " + method->get_signature() << std::endl;
	_do_analysis_hook.GetOrignalFunc()(ciMethodBlocks);
}
constexpr bool DONT_INLINE = false;
bool detour_ok_to_inline(void* inlinetree, void* callee_method, void* jvms, void* profile, bool* should_delay)
{
	static VMStructEntry* _metadata_entry = JVMWrappers::find_type_fields("ciMetadata").value().get()[
		"_metadata"];
	auto method = *reinterpret_cast<java_hotspot::method**>(reinterpret_cast<uint8_t*>(callee_method) + _metadata_entry->offset);
	for (auto pMethod : methods_being_hooked)
	{
		if (method == pMethod)
		{
			std::cout << "Force break inling of " << pMethod->get_name() << std::endl;

			return DONT_INLINE;
		}
	}
	return _ok_to_inline_hook.GetOrignalFunc()(inlinetree, callee_method, jvms, profile, should_delay);
}
/*
FakePDB/signatures_find:
   * address  : 0x1801d0480
   * name     : ?do_analysis@ciMethodBlocks@@AEAAXXZ
   * signature: 48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 41 54 41 55 41 56 41 57 48 8B EC 48 81 EC 80 00 00 00 48 8B 19

FakePDB/signatures_find:
   * address  : 0x1801ceec0
   * name     : ?load_code@ciMethod@@AEAAXXZ
   * signature: 40 53 41 56 48 83 EC 38 65 48 8B 04 25 58 00 00 00

   FakePDB/signatures_find:
   * address  : 0x180125c90
   * name     : ?ok_to_inline@InlineTree@@QEAA_NPEAVciMethod@@PEAVJVMState@@AEAVciCallProfile@@AEA_N@Z
   * signature: 48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 81 EC 90 00 00 00 45 8B 70 24
*/

//we can only hook ok_to_inline,but for some reasons i am going to 
static void hook_invoke_compiler_on_method() {
	auto jvm = (uintptr_t)GetModuleHandleA("jvm.dll");

	//CompileBroker::invoke_compiler_on_method(CompileTask *task)
	auto pinvoke_compiler_on_method = (void*)CUtil_Pattern::Find(jvm, "48 89 5C 24 10 48 89 74 24 18 48 89 7C 24 20 55 41 54 41 55 41 56 41 57 48 8D AC 24 80 FA FF FF 48 81 EC 80 06 00 00 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 70 05 00 00 33 D2");// this function will call    __dyn_tls_on_demand_init and doing something like NtCurrentTeb()->ThreadLocalStoragePointer + (unsigned int)TlsIndex);
	if (!pinvoke_compiler_on_method)
	{
		MessageBox(0, L"Failed to get the address of invoke_compiler_on_method", 0, 0);
	}

	auto pdo_analysis = (void*)CUtil_Pattern::Find(jvm, "48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 41 54 41 55 41 56 41 57 48 8B EC 48 81 EC 80 00 00 00 48 8B 19");
	if (!pdo_analysis)
	{
		MessageBox(0, L"Failed to get the address of do_analysis", 0, 0);
	}

	auto pok_to_inline = (void*)CUtil_Pattern::Find(jvm, "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 81 EC 90 00 00 00 45 8B 70 24");
	if (!pok_to_inline)
	{
		MessageBox(0, L"Failed to get the address of ok_to_inline", 0, 0);
	}

	if (pinvoke_compiler_on_method)
	{
		_invoke_compiler_on_method_hook.InitHook(pinvoke_compiler_on_method, detour_invoke_compiler_on_method);
		_invoke_compiler_on_method_hook.SetHook();
	}
	if (pdo_analysis)
	{
		_ok_to_inline_hook.InitHook(pok_to_inline, detour_ok_to_inline);
		_ok_to_inline_hook.SetHook();

	}
	else {


		_do_analysis_hook.InitHook(pdo_analysis, detour_do_analysis);
		_do_analysis_hook.SetHook();
	}



}
#include "hooks/RenderSystemHook.h"
#include "hooks/BedRendererHook.h"
#include "hooks/ClientPacketListenerHook.h"
#include "hooks/LevelHook.h"
void HookManager::setup()
{
	JavaHook::JVM::Init(JNI::get_env());

	hook_invoke_compiler_on_method();

	hooks.push_back(std::make_shared<GameRendererHook>());
	hooks.push_back(std::make_shared<ClientPacketListenerHook>());
	hooks.push_back(std::make_shared<LevelHook>());
	//hooks.push_back(std::make_shared<BedRendererHook>());


}

void HookManager::handle()
{
	for (auto& hook : hooks)
	{

		hook->hook(HookManagerData{ methods_being_hooked,  methodes_dont_compile,klasses_dont_compile });
	}
}
