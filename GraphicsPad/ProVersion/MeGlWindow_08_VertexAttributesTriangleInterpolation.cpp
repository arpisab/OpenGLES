///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Vertex Attributes Triangle Interpolation
//	Shows interpolation (or blending) of vertex attributes from the vertex shader to the fragment (pixel) shader. 
//  Uses OpenGL's version of the graphics pipeline.
//


#include <GL\glew.h>
#include <MeGlWindow.h>

extern const char* vertexShaderCode;
extern const char* fragmentShaderCode;

void sendDataToOpenGL()
{
	GLfloat verts[] =
	{
		+0.0f, +0.0f,
		+1.0f, +0.0f, +0.0f,
		+1.0f, +1.0f,
		+1.0f, +0.0f, +0.0f,
		-1.0f, +1.0f,
		+1.0f, +0.0f, +0.0f,
		-1.0f, -1.0f,
		+1.0f, +0.0f, +0.0f,
		+1.0f, -1.0f,
		+1.0f, +0.0f, +0.0f,
	};
	GLuint vertexBufferID;
	glGenBuffers(1, &vertexBufferID); // generates the Buffer Objects and stores the ID that reprensents the BO to myBufferID. Thinks about a penGL pointer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID); // creates a binding point for the bufferID
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
		verts, GL_STATIC_DRAW);  // send the data that is bound to the GL_ARRAY_BUFFER binding point, down to openGL

	glEnableVertexAttribArray(0); // enable the data that we copied down to buffer (verts array)to go to graphic process pipeline	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0); // here we describe the data (verts array) to openGL

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 2));


	GLushort indices[] = { 0, 1, 2, 0, 3, 4 }; // GLushort saves more memory
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
		indices, GL_STATIC_DRAW);
}

void installShaders()
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	adapter[0] = vertexShaderCode;
	glShaderSource(vertexShaderID, 1, adapter, 0);  // here we send the shader down to the graphic card 
	adapter[0] = fragmentShaderCode;
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);   // and here we ask opneGL to compile the shaders
	glCompileShader(fragmentShaderID);

	GLuint programID = glCreateProgram();  // create the programID that will link the shaders

	glAttachShader(programID, vertexShaderID);    // attach the shader to the programID
	glAttachShader(programID, fragmentShaderID);

	glLinkProgram(programID); // link the programID

	glUseProgram(programID); // link the programID


}

void MeGlWindow::initializeGL()
{
	glewInit();
	sendDataToOpenGL();
	installShaders();

}

void MeGlWindow::paintGL()
{
	glViewport(0, 0, width(), height()); // the triangle reshape according with the size of the window

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0); // what do we want to render: Triangles; 
									  // how many verteces do we whant to draw? : 6;
									  // What data type are they? : GLushort (we're passing the indices buffer now);
									  // Is there any offset? : no (0);
}