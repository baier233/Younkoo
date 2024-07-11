#pragma once

#include <SDK.hpp>
#include <wrapper/java/lang/String.h>

BEGIN_1_20_1
BEGIN_KLASS_DEF(ResourceLocation, return SRGParser::get().getObfuscatedClassName("net/minecraft/resources/ResourceLocation"))
JNI::Field<jchar, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/resources/ResourceLocation"), "NAMESPACE_SEPARATOR")
)> NAMESPACE_SEPARATOR{ *this};/* C */

JNI::Field<String, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/resources/ResourceLocation"), "DEFAULT_NAMESPACE")
)> DEFAULT_NAMESPACE{ *this};/* Ljava/lang/String; */

JNI::Field<String, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/resources/ResourceLocation"), "REALMS_NAMESPACE")
)> REALMS_NAMESPACE{ *this};/* Ljava/lang/String; */

JNI::Field<String, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/resources/ResourceLocation"), "namespace")
)> namespace_ResourceLocation{ *this};/* Ljava/lang/String; */

JNI::Field<String, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/resources/ResourceLocation"), "path")
)> path{ *this};/* Ljava/lang/String; */

JNI::Method<ResourceLocation, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "tryParse", "(Ljava/lang/String;)Lnet/minecraft/resources/ResourceLocation;").first
),String> tryParse{ *this};

JNI::Method<ResourceLocation, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "tryBuild", "(Ljava/lang/String;Ljava/lang/String;)Lnet/minecraft/resources/ResourceLocation;").first
),String,String> tryBuild{ *this};

JNI::Method<JNI::Array<String>, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "decompose", "(Ljava/lang/String;C)[Ljava/lang/String;").first
),String,jchar> decompose{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "getPath", "()Ljava/lang/String;").first
)> getPath{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "getNamespace", "()Ljava/lang/String;").first
)> getNamespace{ *this};

JNI::Method<ResourceLocation, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "withPath", "(Ljava/lang/String;)Lnet/minecraft/resources/ResourceLocation;").first
),String> withPath{ *this};

JNI::Method<ResourceLocation, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "withPrefix", "(Ljava/lang/String;)Lnet/minecraft/resources/ResourceLocation;").first
),String> withPrefix{ *this};

JNI::Method<ResourceLocation, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "withSuffix", "(Ljava/lang/String;)Lnet/minecraft/resources/ResourceLocation;").first
),String> withSuffix{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "toString", "()Ljava/lang/String;").first
)> toString{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "hashCode", "()I").first
)> hashCode{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "compareTo", "(Lnet/minecraft/resources/ResourceLocation;)I").first
),ResourceLocation> compareTo{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "compareNamespaced", "(Lnet/minecraft/resources/ResourceLocation;)I").first
),ResourceLocation> compareNamespaced{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "toDebugFileName", "()Ljava/lang/String;").first
)> toDebugFileName{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "toLanguageKey", "()Ljava/lang/String;").first
)> toLanguageKey{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "toShortLanguageKey", "()Ljava/lang/String;").first
)> toShortLanguageKey{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "toLanguageKey", "(Ljava/lang/String;)Ljava/lang/String;").first
),String> toLanguageKey{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "toLanguageKey", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;").first
),String,String> toLanguageKey{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "isAllowedInResourceLocation", "(C)Z").first
),jchar> isAllowedInResourceLocation{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "isValidPath", "(Ljava/lang/String;)Z").first
),String> isValidPath{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "isValidNamespace", "(Ljava/lang/String;)Z").first
),String> isValidNamespace{ *this};

JNI::Method<String, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "assertValidNamespace", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;").first
),String,String> assertValidNamespace{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "validPathChar", "(C)Z").first
),jchar> validPathChar{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "validNamespaceChar", "(C)Z").first
),jchar> validNamespaceChar{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "isValidResourceLocation", "(Ljava/lang/String;)Z").first
),String> isValidResourceLocation{ *this};

JNI::Method<String, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "assertValidPath", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;").first
),String,String> assertValidPath{ *this};

END_KLASS_DEF();
END_1_20_1