#pragma once
#include <SDK.hpp>

BEGIN_1_20_1

BEGIN_KLASS_DEF(Matrix4f, return "org/joml/Matrix4f")
JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m00"
)> m00{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m01"
)> m01{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m02"
)> m02{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m03"
)> m03{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m10"
)> m10{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m11"
)> m11{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m12"
)> m12{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m13"
)> m13{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m20"
)> m20{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m21"
)> m21{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m22"
)> m22{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m23"
)> m23{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m30"
)> m30{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m31"
)> m31{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m32"
)> m32{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return "m33"
)> m33{ *this };/* F */


END_KLASS_DEF();

END_1_20_1