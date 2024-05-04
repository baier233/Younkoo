#pragma once
#include <algorithm>
#include <cmath>
#include <vector>
namespace Math {
	class Vector3
	{
	public:

		float x{ NAN };
		float y{ NAN };
		float z{ NAN };

		Vector3() {};
		Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}
		Vector3 operator + (const Vector3& rhs) const { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
		Vector3 operator + (const float rhs) const { return Vector3(x + rhs, y + rhs, z + rhs); }
		Vector3 operator - (const Vector3& rhs) const { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
		Vector3 operator - (const float rhs) const { return Vector3(x - rhs, y - rhs, z - rhs); }
		Vector3 operator * (const Vector3& rhs) const { return Vector3(x * rhs.x, y * rhs.y, z * rhs.z); }
		Vector3 operator * (const float& rhs) const { return Vector3(x * rhs, y * rhs, z * rhs); }
		Vector3 operator / (const float& rhs) const { return Vector3(x / rhs, y / rhs, z / rhs); }
		Vector3& operator += (const Vector3& rhs) { return *this = *this + rhs; }
		Vector3& operator -= (const Vector3& rhs) { return *this = *this - rhs; }
		Vector3& operator *= (const float& rhs) { return *this = *this * rhs; }
		Vector3& operator /= (const float& rhs) { return *this = *this / rhs; }
		//Vector3 operator == (const Vector3& rhs) { return this == rhs; }
		float Length() const { return sqrtf(x * x + y * y + z * z); }
		Vector3 Normalize() const { return *this * (1 / Length()); }
		Vector3 Invert() const { return Vector3{ -x, -y, -z }; }
		float Distance(const Vector3& rhs) const { return (*this - rhs).Length(); }
		float Dist() { return std::sqrt(x * x + y * y); }
	};

	struct Vector2
	{

		Vector2 operator - (const Vector2& rhs) const { return Vector2(x - rhs.x, y - rhs.y); }
		Vector2 Invert() const { return Vector2{ -x, -y }; }
		float x{ NAN };
		float y{ NAN };
	};

	struct Vector2i
	{
		unsigned int x{ 0 };
		unsigned int y{ 0 };
	};

	struct Vector2D
	{
		Vector2D operator - (const Vector2D& rhs) const { return Vector2D(x - rhs.x, y - rhs.y); }
		Vector2D Invert() const { return Vector2D{ -x, -y }; }
		double x{ 0 };
		double y{ 0 };
	};

	struct Vector3i {
		Vector3i(const int x, const int y, const int z) : x(x), y(y), z(z) {}

		unsigned int x{ 0 };
		unsigned int y{ 0 };
		unsigned int z{ 0 };
	};

	struct Vector3D {
		double x, y, z;

		double distance(const Vector3D& other) const
		{
			return sqrt(pow(x - other.x, 2.0) + pow(y - other.y, 2.0) + pow(z - other.z, 2.0));
		}
	};


	struct Vector4
	{
		float x{ NAN };
		float y{ NAN };
		float z{ NAN };
		float w{ NAN };
	};

	// https://github.com/Marcelektro/MCP-919/blob/main/src/minecraft/net/minecraft/util/Matrix4f.java
	// For readability & maybe security purposes.
	struct Matrix
	{
		float m00, m01, m02, m03;
		float m10, m11, m12, m13;
		float m20, m21, m22, m23;
		float m30, m31, m32, m33;
	};

	struct BoundingBox {
		double minX;
		double minY;
		double minZ;
		double maxX;
		double maxY;
		double maxZ;
	};

	struct AxisAlignedBB {
		float minX, minY, minZ, maxX, maxY, maxZ;
	};

	inline std::vector<float> structToVector(const Matrix& matrix)
	{
		std::vector<float> result;
		result.reserve(16);

		result.push_back(matrix.m00);
		result.push_back(matrix.m01);
		result.push_back(matrix.m02);
		result.push_back(matrix.m03);

		result.push_back(matrix.m10);
		result.push_back(matrix.m11);
		result.push_back(matrix.m12);
		result.push_back(matrix.m13);

		result.push_back(matrix.m20);
		result.push_back(matrix.m21);
		result.push_back(matrix.m22);
		result.push_back(matrix.m23);

		result.push_back(matrix.m30);
		result.push_back(matrix.m31);
		result.push_back(matrix.m32);
		result.push_back(matrix.m33);

		return result;
	}
}
