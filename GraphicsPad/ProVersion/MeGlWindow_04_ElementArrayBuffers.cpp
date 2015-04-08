///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Element Array Buffer and indices
//	Simple example that shows how to save memory by using element array buffers (index buffers). 
//  Calls glDrawElements() with GL_TRIANGLES for the mode to render a simple triangle.
//


#include <GL\glew.h>
#include <MeGlWindow.h>

void MeGlWindow::initializeGL()
{
	glewInit();

	GLfloat verts[] =
	{
		+0.0f, +0.0f, // 0
		+1.0f, +1.0f, // 1
		-1.0f, +1.0f, // 2
		-1.0f, -1.0f, // 3
		+1.0f, -1.0f, // 4
	};
	GLuint vertexBufferID;
	glGenBuffers(1, &vertexBufferID); // generates the Buffer Objects and stores the ID that reprensents the BO to myBufferID. Thinks about a penGL pointer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID); // creates a binding point for the bufferID
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
		verts, GL_STATIC_DRAW);  // send the data that is bound to the GL_ARRAY_BUFFER binding point, down to openGL
	glEnableVertexAttribArray(0); // enable the data that we copied down to buffer (verts array)to go to graphic process pipeline	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0); // here we describe the data (verts array) to openGL

	GLushort indices[] = { 0, 1, 2, 0, 3, 4 }; // GLushort saves more memory
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
		indices, GL_STATIC_DRAW);

}

void MeGlWindow::paintGL()
{
	glViewport(0, 0, width(), height()); // the triangle reshape according with the size of the window

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0); // what do we want to render: Triangles; 
	// how many verteces do we whant to draw? : 6;
	// What data type are they? : GLushort (we're passing the indices buffer now);
	// Is there any offset? : no (0);
}