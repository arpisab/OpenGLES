#ifndef ME_GL_WINDOW
#define ME_GL_WINDOW


#include <QtOpenGL\qglwidget>


class MeGlWindow : public QGLWidget
{
protected:
	void initializeGL();
	void paintGL();
public:

	// Remember that I applied the destractor from video 26
	// In case the preview video don't work comment the line below out
	~MeGlWindow();
};

#endif
