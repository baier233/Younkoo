#pragma once
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>


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
		Vector3D operator - (const Vector3D& rhs) const { return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z); }
		Vector3D& operator -= (const Vector3D& rhs) { return *this = *this - rhs; }
	};


	struct Vector4
	{
		float x{ NAN };
		float y{ NAN };
		float z{ NAN };
		float w{ NAN };
	};

	struct Vector4D
	{
		double x{ NAN };
		double y{ NAN };
		double z{ NAN };
		double w{ NAN };
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
		result.push_back(matrix.m10);
		result.push_back(matrix.m20);
		result.push_back(matrix.m30);

		result.push_back(matrix.m01);
		result.push_back(matrix.m11);
		result.push_back(matrix.m21);
		result.push_back(matrix.m31);

		result.push_back(matrix.m02);
		result.push_back(matrix.m12);
		result.push_back(matrix.m22);
		result.push_back(matrix.m32);

		result.push_back(matrix.m03);
		result.push_back(matrix.m13);
		result.push_back(matrix.m23);
		result.push_back(matrix.m33);


		return result;
	}

	struct Matrix4 {
		std::array<std::array<float, 4>, 4> mat;

		Matrix4(std::initializer_list<float> values) {
			auto it = values.begin();
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					mat[i][j] = *it++;
				}
			}
		}
	};

	inline Vector4 Multiply(Vector4 v, Matrix m) {
		return Vector4{
			v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + v.w * m.m30,
			v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + v.w * m.m31,
			v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + v.w * m.m32,
			v.x * m.m03 + v.y * m.m13 + v.z * m.m23 + v.w * m.m33
		};
	}

	inline Vector4D Multiply(Vector4D v, Matrix m) {
		return Vector4D{
			v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + v.w * m.m30,
			v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + v.w * m.m31,
			v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + v.w * m.m32,
			v.x * m.m03 + v.y * m.m13 + v.z * m.m23 + v.w * m.m33
		};
	}



	inline void __gluMultMatrixVecf(const std::vector<float>& m, const std::array<float, 4>& in, std::array<float, 4>& out) {
		for (int i = 0; i < 4; i++) {
			out[i] =
				in[0] * m[static_cast<unsigned long long>(0) * 4 + static_cast<std::vector<float, std::allocator<float>>::size_type>(i)] +
				in[1] * m[static_cast<unsigned long long>(1) * 4 + static_cast<std::vector<float, std::allocator<float>>::size_type>(i)] +
				in[2] * m[static_cast<unsigned long long>(2) * 4 + static_cast<std::vector<float, std::allocator<float>>::size_type>(i)] +
				in[3] * m[static_cast<unsigned long long>(3) * 4 + static_cast<std::vector<float, std::allocator<float>>::size_type>(i)];
		}
	}

	inline bool gluProject(
		float objx,
		float objy,
		float objz,
		const std::vector<float>& modelMatrix,
		const std::vector<float>& projMatrix,
		const std::vector<int>& viewport,
		std::vector<float>& win_pos)
	{
		std::array<float, 4> in = { objx, objy, objz, 1.0f };
		std::array<float, 4> out{};

		__gluMultMatrixVecf(modelMatrix, in, out);
		__gluMultMatrixVecf(projMatrix, out, in);

		if (in[3] == 0.0f) {
			return false;
		}

		in[3] = 1.0f / in[3] * 0.5f;

		// Map x, y and z to range 0-1
		in[0] = in[0] * in[3] + 0.5f;
		in[1] = in[1] * in[3] + 0.5f;
		in[2] = in[2] * in[3] + 0.5f;

		// Map x,y to viewport
		win_pos[0] = in[0] * viewport[2] + viewport[0];
		win_pos[1] = in[1] * viewport[3] + viewport[1];
		win_pos[2] = in[2];

		return true;
	}

	namespace W2S {

		inline bool world2Screen(const std::vector<int>& viewport, const Matrix& modelViewMatrix, const Matrix& projectionMatrix, float x, float y, float z, int screenHeight, Vector2D& point, double guiScale = 2.0f) {
			std::vector<float> result(3);

			bool ok = gluProject(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z), structToVector(modelViewMatrix), structToVector(projectionMatrix), viewport, result);

			if (!ok) {
				return false;
			}
			else {
				point = { result[0] / static_cast<float>(guiScale)
					,(static_cast<float>(viewport[3]) - result[1]) / static_cast<float>(guiScale) };
				return true;
			}
		}

		inline bool WorldToScreen(Vector3D point, Matrix modelView, Matrix projection, int screenWidth, int screenHeight, Vector2D& screenPos) {
			// csp = Clip Space Position
			Vector4D csp = Multiply(
				Multiply(
					Vector4D{ point.x, point.y, point.z, 1.0f },
					modelView
				),
				projection
			);

			// ndc = Native Device Coordinate
			Vector3D ndc{
				csp.x / csp.w,
				csp.y / csp.w,
				csp.z / csp.w
			};

			//Logger::Log("NDC.Z: " + std::to_string(ndc.z));
			screenPos = Vector2D{
					((ndc.x + 1.0f) / 2.0f) * screenWidth,
					((1.0f - ndc.y) / 2.0f) * screenHeight,
			};
			return true;
		}
	}

}
