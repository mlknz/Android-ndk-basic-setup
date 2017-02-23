#include <stdio.h>
#include <algorithm>
#include <GLES2/gl2.h>

#include "shaderProgram.h"
#include <android/log.h>
#include "customDefines.h"

GLuint compileShader(GLenum eShaderType, const char* shaderCodeChar)
{
	GLuint shader = glCreateShader(eShaderType);

	glShaderSource(shader, 1, &shaderCodeChar, NULL);

	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE){
		GLint infoLogLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
		if (infoLogLength > 0){
			std::vector<char> ShaderErrorMessage(infoLogLength + 1);
			glGetShaderInfoLog(shader, infoLogLength, NULL, &ShaderErrorMessage[0]);
            LOGI("%s - shader error msg.\n", &ShaderErrorMessage[0]);
		}
	}

	return shader;
}

GLuint linkShaderProgram(GLuint vertexShader, GLuint fragmentShader)
{
	GLuint program = glCreateProgram();

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);

	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
		LOGE("Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}

	glDetachShader(program, vertexShader);
	glDetachShader(program, fragmentShader);

	return program;
}
