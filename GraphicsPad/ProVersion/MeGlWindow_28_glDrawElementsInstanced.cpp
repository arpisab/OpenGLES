///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// glDrawElementsInstanced
// Performs instanced rendering by using glDrawElementsInstanced and glVertexAttribDivisor. 
// glDrawArrayInstanced works in a similar fashion using glVertexAttribDivisor to instance 
// geometries and triangles. 
// 

#include <GL\glew.h>
#include <iostream>
#include <fstream>
#include <MeGlWindow.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtx\transform.hpp> // this supports the matrices
#include <Primitives\vertex.h>
#include <Primitives\ShapeGenerator.h>
using namespace std;
using glm::vec3;
using glm::mat4;

const uint NUM_VERTICES_PER_TRI = 3;
const uint NUM_FLOATS_PER_VERTICE = 6;
const uint VERTEX_BYTE_SIZE = NUM_FLOATS_PER_VERTICE * sizeof(float);
GLuint programID;
GLint numIndices;

void sendDataToOpenGL()
{
	GLfloat tri[] = {
		-1.0f, +0.0f,
		-1.0f, +1.0f,
		-0.9f, +0.0f,
	};

	GLuint vertexBufferID;
	glGenBuffers(1, &vertexBufferID); // generates the Buffer Objects and stores the ID that reprensents the BO to myBufferID. Thinks about a penGL pointer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID); // creates a binding point for the bufferID
	glBufferData(GL_ARRAY_BUFFER, sizeof(tri), tri, GL_STATIC_DRAW);  // send the data that is bound to the GL_ARRAY_BUFFER binding point, down to openGL
	glEnableVertexAttribArray(0); // enable the data that we copied down to buffer (verts array)to go to graphic process pipeline	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0); // here we describe the data (verts array) to openGL

	GLfloat offsets[] = { 0.0f, 0.5f, 1.0f, 1.2f, 1.6f };
	GLuint offsetBufferID;
	glGenBuffers(1, &offsetBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, offsetBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(offsets), offsets, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribDivisor(1, 1);


	GLushort indices[] = { 0, 1, 2 };
	GLuint indexArrayBufferID;
	glGenBuffers(1, &indexArrayBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	numIndices = 3;
}

void MeGlWindow::paintGL()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, width(), height()); // the triangle reshape according with the size of the window

	GLint fullTransformMatrixUniformLocation =
		glGetUniformLocation(programID, "fullTransformMatrix");

	glDrawElementsInstanced(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, 0, 5);

}

bool checkStatus(
	GLuint objectID,
	PFNGLGETSHADERIVPROC objectPropertyGetter,
	PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
	GLenum statusType)
{
	GLint status;
	objectPropertyGetter(objectID, statusType, &status);  //GLGetShaderiv - iv stands for integer vector
	if (status != GL_TRUE)
	{
		GLint infoLogLenght;
		objectPropertyGetter(objectID, GL_INFO_LOG_LENGTH, &infoLogLenght);
		GLchar* buffer = new GLchar[infoLogLenght];

		GLsizei bufferSize;
		getInfoLogFunc(objectID, infoLogLenght, &bufferSize, buffer); // glGetShaderInfoLog will write the error message out of the buffer
		cout << buffer << endl;

		delete[] buffer;
		return false;
	}
	return true;
}

bool chekShaderStatus(GLuint shaderID)
{
	return checkStatus(shaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
}

bool chekProgramStatus(GLuint programID)
{
	return checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);
}

string readShaderCode(const char* fileName)
{
	ifstream myInput(fileName);
	if (!myInput.good())
	{
		cout << "File failed to load... " << fileName;
		exit(1);
	}
	return std::string(
		std::istreambuf_iterator<char>(myInput),
		std::istreambuf_iterator<char>());	// return value optimization
}

void installShaders()
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	string temp = readShaderCode("Shaders/shader_R07.vs");
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);  // here we send the shader down to the graphic card 
	temp = readShaderCode("Shaders/shader_R01.fs");
	adapter[0] = temp.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);   // and here we ask opneGL to compile the shaders
	glCompileShader(fragmentShaderID);

	if (!chekShaderStatus(vertexShaderID) || !chekShaderStatus(fragmentShaderID))
		return;

	programID = glCreateProgram();  // create the programID that will link the shaders

	glAttachShader(programID, vertexShaderID);    // attach the shader to the programID
	glAttachShader(programID, fragmentShaderID);

	glLinkProgram(programID); // link the programID

	if (!chekProgramStatus(programID))
		return;

	/// We now need to delete the shaders
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	///


	glUseProgram(programID); // link the programID
}

void MeGlWindow::initializeGL()
{
	glewInit();
	glEnable(GL_DEPTH_TEST);
	sendDataToOpenGL();
	installShaders();

}

/// Now we delete the program
MeGlWindow::~MeGlWindow()
{
	glUseProgram(0);
	glDeleteProgram(programID);
}