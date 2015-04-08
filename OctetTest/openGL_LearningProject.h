////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2012-2014 - Modular Framework for OpenGLES2 rendering on multiple platforms.
//
// OpenGL Learning Project - 18 - Sending Triangles in Parts Using glBufferSubData


#include <iostream>
#include <fstream>
#include <glm\vec3.hpp>

using namespace std;

namespace octet {
	typedef unsigned int uint;
	const uint NUM_VERTICES_PER_TRI = 3;
	const uint NUM_FLOATS_PER_VERTICE = 6;
	const uint TRIANGLE_BYTE_SIZE = NUM_VERTICES_PER_TRI * NUM_FLOATS_PER_VERTICE * sizeof(float);
	GLuint programID;

	void sendDataToOpenGL()
	{
		
		GLfloat verts[] =  // we define the position of the vertices with this array
		{
			0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 1.0f,
			1.0f, 0.0f, 0.0f,
			-1.0f, 1.0f,
			1.0f, 0.0f, 0.0f,
			-1.0f, -1.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, -1.0f,
			1.0f, 0.0f, 0.0f,

		};
		
		GLuint vertexBufferID;
		glGenBuffers(1, &vertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
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
		std::string temp = readShaderCode("shader03.vs");
		adapter[0] = temp.c_str(); // c_str stands for C style string
		glShaderSource(vertexShaderID, 1, adapter, 0);
		temp = readShaderCode("shader.fs");
		adapter[0] = temp.c_str();
		glShaderSource(fragmentShaderID, 1, adapter, 0);

		glCompileShader(vertexShaderID);
		glCompileShader(fragmentShaderID);


		programID = glCreateProgram();
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

			//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



			glEnable(GL_DEPTH_TEST);
			glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

			glViewport(0, 0, vx, vy); // this func. sets what area of the window we want to render, in this case it just makes the window resizeble

			vec3 dominatingColor(1.0f, 0.0f, 0.0f);
			GLuint dominatingColorUniformLocation = glGetUniformLocation(programID, "dominatingColor");
			glUniform3fv(dominatingColorUniformLocation, 1, &dominatingColor[0]);

			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
			//glDrawArrays(GL_TRIANGLES, (numTris - 1) * NUM_VERTICES_PER_TRI, NUM_VERTICES_PER_TRI);

		}
	};
}
