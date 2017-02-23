#ifndef __ShaderProgram__
#define __ShaderProgram__

GLuint compileShader(GLenum eShaderType, const char* shaderCodeChar);
GLuint linkShaderProgram(GLuint vertexShader, GLuint fragmentShader);

#endif
