///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Shape Data Structure
//  We abstract our shape geometry data generation to a ShapeGenerator class that returns ShapeDatas. 
//  ShapeDatas contain the vertices and indices for our the geometry we want to send to the graphics hardware via OpenGL.
//


#include <GL\glew.h>
#include <iostream>
#include <fstream>
#include <MeGlWindow.h>
#include <glm\glm.hpp>
#include <Primitives\vertex.h>
#include <Primitives\ShapeGenerator.h>
using namespace std;

const uint NUM_VERTICES_PER_TRI = 3;
const uint NUM_FLOATS_PER_VERTICE = 6;
const uint VERTEX_BYTE_SIZE = NUM_FLOATS_PER_VERTICE * sizeof(float);



void sendDataToOpenGL()
{
	shapeData tri = ShapeGenerator::makeTriangle();

	GLuint vertexBufferID;
	glGenBuffers(1, &vertexBufferID); // generates the Buffer Objects and stores the ID that reprensents the BO to myBufferID. Thinks about a penGL pointer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID); // creates a binding point for the bufferID
	glBufferData(GL_ARRAY_BUFFER, tri.vertexBufferSize(), tri.vertices, GL_STATIC_DRAW);  // send the data that is bound to the GL_ARRAY_BUFFER binding point, down to openGL
	glEnableVertexAttribArray(0); // enable the data that we copied down to buffer (verts array)to go to graphic process pipeline	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, 0); // here we describe the data (verts array) to openGL
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, (char*)(sizeof(float) * 3));

	GLuint indexArrayBufferID;
	glGenBuffers(1, &indexArrayBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, tri.indexBufferSize(), tri.indices, GL_STATIC_DRAW);

	tri.cleanup();
}


void MeGlWindow::paintGL()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, width(), height()); // the triangle reshape according with the size of the window
	glDrawArrays(GL_TRIANGLES, 0, 3);
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
	string temp = readShaderCode("shader_R03.vs");
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);  // here we send the shader down to the graphic card 
	temp = readShaderCode("shader_R01.fs");
	adapter[0] = temp.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);   // and here we ask opneGL to compile the shaders
	glCompileShader(fragmentShaderID);

	if (!chekShaderStatus(vertexShaderID) || !chekShaderStatus(fragmentShaderID))
		return;

	GLuint programID = glCreateProgram();  // create the programID that will link the shaders

	glAttachShader(programID, vertexShaderID);    // attach the shader to the programID
	glAttachShader(programID, fragmentShaderID);

	glLinkProgram(programID); // link the programID

	if (!chekProgramStatus(programID))
		return;

	glUseProgram(programID); // link the programID


}

void MeGlWindow::initializeGL()
{
	glewInit();
	glEnable(GL_DEPTH_TEST);
	sendDataToOpenGL();
	installShaders();

}