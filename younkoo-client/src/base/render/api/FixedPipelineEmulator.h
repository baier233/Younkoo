#pragma once
#include <gl2d/gl2d.h>
#include <glm/gtc/type_ptr.hpp>
#include <utils/types/Maths.hpp>
#include <utils/Singleton.hpp>

static glm::mat4 matrixToGlmMat4(const Math::Matrix& matrix) {
	return glm::mat4(
		matrix.m00, matrix.m01, matrix.m02, matrix.m03,
		matrix.m10, matrix.m11, matrix.m12, matrix.m13,
		matrix.m20, matrix.m21, matrix.m22, matrix.m23,
		matrix.m30, matrix.m31, matrix.m32, matrix.m33
	);
}

class FixedPipelineEmulator :public Singleton<FixedPipelineEmulator>
{
private:
	gl2d::ShaderProgram shaderProgram;
	glm::mat4 modelViewMatrix;
	glm::mat4  projectionMatrix;
	int u_texture = 0;
	int u_mvpMatrix = 0;
	//glm::vec4 viewport;
public:

	unsigned int VBO;

	~FixedPipelineEmulator() {
		shaderProgram.clear();
	}

	FixedPipelineEmulator() {
		const char* vertexShaderSource = R"(
            #version 330 core
            layout (location = 0) in vec3 aPos;
            layout (location = 1) in vec2 aTexCoord;
            out vec2 TexCoord;
            uniform mat4 u_mvpMatrix;
            void main()
            {
                gl_Position = u_mvpMatrix * vec4(aPos, 1.0);
                TexCoord = aTexCoord;
            }
        )";

		const char* fragmentShaderSource = R"(
            #version 330 core
            in vec2 TexCoord;
            out vec4 FragColor;
            uniform sampler2D u_texture;
            void main()
            {
                FragColor = texture(u_texture, TexCoord);
            }
        )";
		gl2d::init();
		shaderProgram = gl2d::createShaderProgram(vertexShaderSource, fragmentShaderSource);
		modelViewMatrix = {};
		projectionMatrix = {};

		u_mvpMatrix = glGetUniformLocation(shaderProgram.id, "u_mvpMatrix");
		u_texture = glGetUniformLocation(shaderProgram.id, "u_texture");
		glGenBuffers(1, &VBO);
	}
	inline void setModelViewMatrix(const glm::mat4& matrix)
	{
		modelViewMatrix = matrix;
	}

	inline void setProjectionMatrix(const glm::mat4& matrix)
	{
		projectionMatrix = matrix;
	}

	inline void setModelViewMatrix(const Math::Matrix& matrix)
	{
		modelViewMatrix = matrixToGlmMat4(matrix);
	}

	inline void setProjectionMatrix(const Math::Matrix& matrix)
	{
		projectionMatrix = matrixToGlmMat4(matrix);
	}

	inline void setTexture(GLuint textureId)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureId);
		glUniform1i(u_texture, 0);
	}
	inline void begin() {
		shaderProgram.bind();
		glm::mat4 mvpMatrix = projectionMatrix * modelViewMatrix;
		glUniformMatrix4fv(u_mvpMatrix, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
	}

	inline void end()
	{
		glUseProgram(0);
	}
};

