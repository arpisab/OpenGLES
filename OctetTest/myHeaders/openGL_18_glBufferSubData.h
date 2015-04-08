////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2012-2014 - Modular Framework for OpenGLES2 rendering on multiple platforms.
//
// OpenGL Learning Project - 18 - Sending Triangles in Parts Using glBufferSubData


#include <iostream>
#include <fstream>


using namespace std;

namespace octet {
	typedef unsigned int uint;
	const float X_DELTA = 0.1f;
	const uint NUM_VERTICES_PER_TRI = 3;
	const uint NUM_FLOATS_PER_VERTICE = 6;
	const uint TRIANGLE_BYTE_SIZE = NUM_VERTICES_PER_TRI * NUM_FLOATS_PER_VERTICE * sizeof(float);
	const uint MAX_TRIS = 10;
	uint numTris = 0;

	void sendDataToOpenGL()
	{
		GLuint vertexBufferID;
		glGenBuffers(1, &vertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, MAX_TRIS * TRIANGLE_BYTE_SIZE, NULL, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
	}

	void sendAnotherTriToOpenGL()
	{
		if (numTris == MAX_TRIS)
			return;


		const GLfloat THIS_TRI_X = -1 + numTris * X_DELTA; // -1 + 0 * 0.1 = -0.1
		GLfloat thisTris[] =
		{
			THIS_TRI_X, 1.0f, 0.0f,             // -1.0, 1.0, 0.0
			1.0f, 0.0f, 0.0f,

			THIS_TRI_X + X_DELTA, 1.0f, 0.0f,   // -1.0 + 0.1 = -0.9, 1.0, 0.0
			1.0f, 0.0f, 0.0f,

			THIS_TRI_X, 0.0f, 0.0f,             // -1.0, 0.0, 0.0
			1.0f, 0.0f, 0.0f
		};
		glBufferSubData(GL_ARRAY_BUFFER,
			numTris * TRIANGLE_BYTE_SIZE, TRIANGLE_BYTE_SIZE, thisTris);
		numTris++;
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

	/// Linker checker
	bool checkProgramStatus(GLuint programID)
	{
		GLint linkStatus;
		glGetProgramiv(programID, GL_LINK_STATUS, &linkStatus);  //GLGetShaderiv - iv stands for integer vector
		if (linkStatus != GL_TRUE)
		{
			GLint infoLogLenght;
			glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLenght);
			GLchar* buffer = new GLchar[infoLogLenght];

			GLsizei bufferSize;
			glGetProgramInfoLog(programID, infoLogLenght, &bufferSize, buffer);
			std::cout << buffer << std::endl;

			delete[] buffer;
			return false;
		}
		return true;
	}

	/// 
	std::string readShaderCode(const char* fileName)
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

		const char* adapter[1]; // adapter is a pointer to the array 1 - the array contains pointers to characher strings
		std::string temp = readShaderCode("shader02.vs");
		adapter[0] = temp.c_str(); // c_str stands for C style string
		glShaderSource(vertexShaderID, 1, adapter, 0);
		temp = readShaderCode("shader.fs");
		adapter[0] = temp.c_str();
		glShaderSource(fragmentShaderID, 1, adapter, 0);

		glCompileShader(vertexShaderID);
		glCompileShader(fragmentShaderID);

		/// Shader compiler error checker
		if (!checkShaderStatus(vertexShaderID) || !checkShaderStatus(fragmentShaderID))
		{
			return;
		};
		///	

		GLuint programID = glCreateProgram();
		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, fragmentShaderID);
		glLinkProgram(programID);


		/// Linker error checker
		if (!checkProgramStatus(programID))
		{
			return;
		};
		///	

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

			//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



			glEnable(GL_DEPTH_TEST);
			glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

			glViewport(0, 0, vx, vy); // this func. sets what area of the window we want to render, in this case it just makes the window resizeble
			sendAnotherTriToOpenGL();

			//glDrawArrays(GL_TRIANGLES, 3, numTris * NUM_VERTICES_PER_TRI);
			//glDrawArrays(GL_TRIANGLES, (numTris - 1) * NUM_VERTICES_PER_TRI, NUM_VERTICES_PER_TRI);
			glDrawArrays(GL_TRIANGLES, 9, NUM_VERTICES_PER_TRI);

		}
	};
}
