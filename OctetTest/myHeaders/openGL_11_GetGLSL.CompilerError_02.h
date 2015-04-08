////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2012-2014 - Modular Framework for OpenGLES2 rendering on multiple platforms.
//
// OpenGL Learning Project - 10 - Get GLSL Compiler Error 02



#include <iostream>
#include "shader_R1.h"


using namespace std;

namespace octet {


	void sendDataToOpenGL()
	{
		GLfloat verts[] =  // we define the position of the vertices with this array
		{
			0.0f, 1.0f,
			1.0f, 0.0f, 0.0f,
			-1.0f, -1.0f,
			0.0f, 1.0f, 0.0f,
			1.0f, -1.0f,
			0.0f, 0.0f, 1.0f,

		};

		GLuint vertexBufferID;
		glGenBuffers(1, &vertexBufferID);  // Creates the Buffer Object - BO
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);  // Binds the buffer to the binding point

		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts,
			GL_STATIC_DRAW);   //  stores the verts array in a array down to the Graphic Card

		glEnableVertexAttribArray(0);  //  enables the attribute atrray or the data that is copied down to the buffer 
		//  to go throught the process graphic pipeline

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0); // this function decribes the data to openGL
		// position attribute -> zero is the starting point, numb of elements, 
		// type, normalise (GL_FALSE means don't touch the data),
		// stride is the distance in bytes between tose vertices 
		// The pointer tells openGl where we start counting in this case is from zero position 

		/// now we need to describe the colour atttribute to openGL
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 2));


		/// Below we create Indices to save a vertex for two triangles
		GLushort indeces[] = { 0, 1, 2, 0, 3, 4 }; // we define how our position are connecte using thir array
		GLuint indexBufferID;
		glGenBuffers(1, &indexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces),
			indeces, GL_STATIC_DRAW);
	}

	/// Shader compiler checker - version 02
	bool checkShaderStatus(GLuint shaderID)
	{
		GLint compileStatus;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);  //GLGetShaderiv - iv stands for integer vector
		if (compileStatus != GL_TRUE)
		{
			GLint infoLogLenght;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLenght);
			GLchar* buffer = new GLchar[infoLogLenght];

			GLsizei bufferSize;
			glGetShaderInfoLog(shaderID, infoLogLenght, &bufferSize, buffer);
			std::cout << buffer << std::endl;

			delete[] buffer;
			return false;
		}
		return true;
	}


	void installShaders()
	{
		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);


		const char* adapter[1]; // adapter is a pointer to the array 1 - the array contains pointers to characher strings
		adapter[0] = vertexShaderCode;
		glShaderSource(vertexShaderID, 1, adapter, 0);
		adapter[0] = fragmentShaderCode;
		glShaderSource(fragmentShaderID, 1, adapter, 0);

		glCompileShader(vertexShaderID);
		glCompileShader(fragmentShaderID);

		/// Shader compiler checker
		if (!checkShaderStatus(vertexShaderID) || !checkShaderStatus(fragmentShaderID))
		{
			return;
		};
		///	


		GLuint programID = glCreateProgram();
		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, fragmentShaderID);
		glLinkProgram(programID);

		glUseProgram(programID);



	}

	/// Scene containing a box with octet.
	class openGL_LearningProject : public app {

	public:
		/// this is called when we construct the class before everything is initialised.
		openGL_LearningProject(int argc, char **argv) : app(argc, argv) {
		}

		/// this is called once OpenGL is initialized
		void app_init()
		{
			sendDataToOpenGL();
			installShaders();

		}

		/// this is called to draw the world
		void draw_world(int x, int y, int w, int h) {
			// the framework gives us the dimensions of the window.
			int vx = 0, vy = 0;
			get_viewport_size(vx, vy);


			glViewport(0, 0, vx, vy); // this func. sets what area of the window we want to render, in this case it just makes the window resizeble

			// this func. draws
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);

		}
	};
}
