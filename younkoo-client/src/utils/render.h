#pragma once
#include <gl2d/gl2d.h>
#include <glm/gtc/type_ptr.hpp>
#include <nanovg/nanovg.h>
#include <utils/types/Maths.hpp>
namespace utils {
	namespace render {
		// 定义Box结构体
		inline void drawOutlinedBox(Math::Box<double>& boundingBox)
		{
			glBegin(3);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glEnd();

			glBegin(3);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.minZ);
			glEnd();

			glBegin(1);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.maxZ);
			glEnd();
		}
		inline void drawFilledBox(Math::Box<double>& boundingBox)
		{
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(255, 255, 255, 0.15f);
			glBegin(7);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.maxZ);
			glEnd();
			glBegin(7);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.maxZ);
			glEnd();
			glBegin(7);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.minZ);
			glEnd();
			glBegin(7);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.minZ);
			glEnd();
			glBegin(7);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.minZ);
			glEnd();
			glBegin(7);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.minZ);
			glEnd();
			glBegin(7);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.maxZ);
			glVertex3f(boundingBox.minX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.minX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.minZ);
			glVertex3f(boundingBox.maxX, boundingBox.maxY, boundingBox.maxZ);
			glVertex3f(boundingBox.maxX, boundingBox.minY, boundingBox.maxZ);
			glEnd();
			glDisable(GL_BLEND);//turn the blending off 
			glColor4f(255, 255, 255, 1);
		}

		inline void copyUniformValues(GLuint originalProgramID, GLuint newProgramID) {
			GLint numUniforms;
			glGetProgramiv(originalProgramID, GL_ACTIVE_UNIFORMS, &numUniforms);

			GLint maxUniformNameLength;
			glGetProgramiv(originalProgramID, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniformNameLength);

			GLchar* uniformName = new GLchar[maxUniformNameLength];

			for (GLint i = 0; i < numUniforms; ++i) {
				GLint size;
				GLenum type;
				GLsizei length;
				glGetActiveUniform(originalProgramID, i, maxUniformNameLength, &length, &size, &type, uniformName);

				GLint location = glGetUniformLocation(newProgramID, uniformName);

				switch (type) {
				case GL_FLOAT:
				{
					GLfloat value;
					glGetUniformfv(originalProgramID, i, &value);
					glUniform1f(location, value);
					break;
				}
				case GL_FLOAT_VEC2:
				{
					GLfloat values[2];
					glGetUniformfv(originalProgramID, i, values);
					glUniform2fv(location, 1, values);
					break;
				}
				case GL_FLOAT_VEC3:
				{
					GLfloat values[3];
					glGetUniformfv(originalProgramID, i, values);
					glUniform3fv(location, 1, values);
					break;
				}
				case GL_FLOAT_VEC4:
				{
					GLfloat values[4];
					glGetUniformfv(originalProgramID, i, values);
					glUniform4fv(location, 1, values);
					break;
				}
				// 处理其他类型的uniform变量
				// ...
				}
			}

			delete[] uniformName;
		}
	}

}