#include "InventoryUtils.h"

#include <wrapper/versions/1_18_1/net/minecraft/core/Registry.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/Block.h>

#include <utils/strutils.h>
std::vector<jclass> InventoryUtils::findBlocksEndingWith(const std::vector<std::string>& targets) {

	std::vector<jclass> result{};
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		auto env = JNI::get_env();
		auto& r = V1_18_1::Registry::static_obj();
		auto block_registry = r.BLOCK.get();
		auto iterator = block_registry.iterator();
		while (iterator.hasNext()) {
			auto next = iterator.next();
			//	V1_18_1::Block block = next.object_instance;
			auto rl = block_registry.getKey(next);
			auto path = rl.getPath().toString();
			std::cout << "Path : " << path << std::endl;
			for (auto& target : targets)
			{
				if (strutil::ends_with(path, target))
				{
					(void)env->PushLocalFrame(5);
					auto klass = (jclass)env->NewGlobalRef(env->GetObjectClass(next.object_instance));
					(void)env->PopLocalFrame(nullptr);
					std::lock_guard lock{ JNI::_refs_to_delete_mutex };
					JNI::_refs_to_delete.push_back(klass);
					result.push_back(klass);
				}
			}
		}
	}
	return result;
}