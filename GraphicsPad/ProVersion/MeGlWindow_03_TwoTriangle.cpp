#include <GL\glew.h>
#include <MeGlWindow.h>

void MeGlWindow::initializeGL()
{
	glewInit();

	GLfloat verts[] =
	{
		+0.0f, +0.0f,
		+1.0f, +1.0f,
		-1.0f, +1.0f,

		+0.0f, +0.0f,
		-1.0f, -1.0f,
		+1.0f, -1.0f,

	};
	GLuint myBufferID;
	glGenBuffers(1, &myBufferID); // generates the Buffer Objects and stores the ID 
	// that reprensents the BO to myBufferID. Thinks about a penGL pointer

	glBindBuffer(GL_ARRAY_BUFFER, myBufferID); // creates a binding point for the bufferID

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
		verts, GL_STATIC_DRAW);  // send the data that is bound to the GL_ARRAY_BUFFER binding point, down to openGL

	glEnableVertexAttribArray(0); // enable the data that we copied down to buffer 
	//(verts array)to go to graphic process pipeline	

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0); // here we describe the data (verts array) to openGL
}

void MeGlWindow::paintGL()
{
	glViewport(0, 0, width(), height()); // the triangle reshape according with the size of the window

	glDrawArrays(GL_TRIANGLES, 0, 6); // what do we whant to render: Triangles; 
	// we start drawing from? : vertex 1 (0);
	// how many verteces do we whant to draw? : 3;
}