#pragma once
#include "../jvm/jni/Wrapper.hpp"
#include <map>


std::map<std::string, std::string> ClassNameMap;
std::map<std::string, std::string> MethodNameMap;
std::map<std::string, std::string> FieldNameMap;
namespace maps
{
	BEGIN_KLASS_DEF(Object, "java/lang/Object")
	END_KLASS_DEF()

	BEGIN_KLASS_DEF(String, "java/lang/String")
	String create(const char* str)
	{
		return String(JNI::get_env()->NewStringUTF(str));
	}


	std::string to_string()
	{
		jstring str_obj = (jstring)(jobject)object_instance;
		jsize utf8_size = JNI::get_env()->GetStringUTFLength(str_obj);
		jsize size = JNI::get_env()->GetStringLength(str_obj);

		std::string str(utf8_size, '\0');
		JNI::get_env()->GetStringUTFRegion(str_obj, 0, size, str.data());
		return str;
	}
	END_KLASS_DEF()

	BEGIN_KLASS_DEF(Collection, "java/util/Collection")
		JNI::Method<JNI::Array<Object>> toArray{ "toArray" ,*this };
	END_KLASS_DEF()

	BEGIN_KLASS_DEF_EX(List, "java/util/List", Collection)
	END_KLASS_DEF()


	template<class>
	std::string get_method_name_absolute(std::string methodName) {

	}

	BEGIN_KLASS_DEF(Entity, ClassNameMap["net.minecraft.client.entity.Entity"])
		JNI::Method<String > getName{"e_", *this };
	END_KLASS_DEF()
		BEGIN_KLASS_DEF_EX(EntityLivingBase, "pr", Entity)
		JNI::Method<jfloat> getHealth{"e_", *this };
	END_KLASS_DEF()

	BEGIN_KLASS_DEF_EX(EntityPlayer, "wn", EntityLivingBase)
	END_KLASS_DEF()

	BEGIN_KLASS_DEF_EX(EntityPlayerSP, "bew", EntityPlayer)
		JNI::Method<void, JNI::NOT_STATIC, String> sendChatMessage{  "e", *this };
		JNI::Method<String,  JNI::NOT_STATIC> getClientBrand{ "e",* this};
	END_KLASS_DEF()


	BEGIN_KLASS_DEF(World, "adm")
		JNI::Field<List> playerEntities{ "j" ,*this };
	END_KLASS_DEF()

	BEGIN_KLASS_DEF_EX(WorldClient, "bdb", World)
	END_KLASS_DEF()

	BEGIN_KLASS_DEF(Minecraft, "ave")
		JNI::Field<Minecraft,JNI::STATIC> theMinecraft{ "S",  *this };
		JNI::Field<jint> displayWidth{  "d" ,*this };
		JNI::Field<EntityPlayerSP> thePlayer{"h", *this };
		JNI::Field<WorldClient > theWorld{ "f" ,*this };

		JNI::Method<void,  JNI::NOT_STATIC> clickMouse{ "aw",*this };
		JNI::Method<void, JNI::NOT_STATIC, jint, jint> resize{ "a",*this };
	END_KLASS_DEF()
}