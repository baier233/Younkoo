#include "../Maths.hpp"
#include <iostream>
#include <array>
#include <GL/glew.h>
using namespace Math;


static void __gluMultMatrixVecf(const std::array<float, 16>& m, const std::array<float, 4>& in, std::array<float, 4>& out) {
	for (int i = 0; i < 4; i++) {
		out[i] = in[0] * m[0 * 4 + i]
			+ in[1] * m[1 * 4 + i]
			+ in[2] * m[2 * 4 + i]
			+ in[3] * m[3 * 4 + i];
	}
}

static bool _gluProject(
	double objx,
	double objy,
	double objz,
	const std::array<float, 16>& modelMatrix,
	const std::array<float, 16>& projMatrix,
	const std::array<int, 4>& viewport,
	std::array<float, 3>& win_pos) {

	std::array<float, 4> in = { objx, objy, objz, 1.0f };
	std::array<float, 4> out;

	__gluMultMatrixVecf(modelMatrix, in, out);
	__gluMultMatrixVecf(projMatrix, out, in);

	if (in[3] == 0.0f)
		return false;

	float w = 1.0f / in[3];
	in[0] *= w;
	in[1] *= w;
	in[2] *= w;

	// Map x, y and z to range 0-1
	in[0] = in[0] * 0.5f + 0.5f;
	in[1] = in[1] * 0.5f + 0.5f;
	in[2] = in[2] * 0.5f + 0.5f;

	// Map x, y to viewport
	win_pos[0] = in[0] * viewport[2] + viewport[0];
	win_pos[1] = in[1] * viewport[3] + viewport[1];
	win_pos[2] = in[2];

	return true;
}

std::array<double, 3> Math::W2S::world2Screen(const std::array<float, 16>& modelViewMatrix, const std::array<float, 16>& projectionMatrix, const Math::Vector3D& pos, const std::array<int, 4>& viewport, double guiScale) {
	std::array<float, 3> win_pos{};
	bool var12 = _gluProject(static_cast<float>(pos.x), static_cast<float>(pos.y), static_cast<float>(pos.z), modelViewMatrix, projectionMatrix, viewport, win_pos);
	if (!var12) {
		return {};
	}
	else {
		// Adjust according to GUI scale and render target height as needed
		// Placeholder for mc.getWindow().getGuiScale() and mc.getMainRenderTarget().height

		return {
			win_pos[0] / guiScale,
			(viewport[3] - win_pos[1]) / guiScale,
			win_pos[2]
		};
	}
}

