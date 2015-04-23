#ifndef ME_GL_WINDOW
#define ME_GL_WINDOW
#include <GL\glew.h>
#include <QtOpenGL\qglwidget>
#include <string>

class MeGlWindow : public QGLWidget
{
	void sendDataToOpenGL();
	bool checkStatus(
		GLuint objectID,
		PFNGLGETSHADERIVPROC objectPropertyGetter,
		PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
		GLenum statusType);
	bool chekShaderStatus(GLuint shaderID);
	bool chekProgramStatus(GLuint programID);
	std::string readShaderCode(const char* fileName);
	void installShaders();
protected:
	void initializeGL();
	void paintGL();
	void mouseMoveEvent(QMouseEvent*);
public:

	// Remember that I applied the destractor from video 26
	// In case the preview video don't work comment the line below out
	~MeGlWindow();
};

#endif