////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2012-2014 - Modular Framework for OpenGLES2 rendering on multiple platforms.
//
// OpenGL Learning Project - Create Two Triangles

namespace octet {
	/// Scene containing a box with octet.

	class openGL_LearningProject : public app {

	public:
		/// this is called when we construct the class before everything is initialised.
		openGL_LearningProject(int argc, char **argv) : app(argc, argv) {
		}

		/// this is called once OpenGL is initialized
		void app_init()
		{
			GLfloat verts[] =
			{
				0.0f, 0.0f,
				1.0f, 1.0f,
				-1.0f, 1.0f,

				0.0f, 0.0f,
				-1.0f, -1.0f,
				1.0f, -1.0f,

			};

			GLuint myBufferID;
			glGenBuffers(1, &myBufferID);  // Creates the Buffer Object - BO
			glBindBuffer(GL_ARRAY_BUFFER, myBufferID);  // Binds the buffer to the binding point

			glBufferData(GL_ARRAY_BUFFER,
				sizeof(verts),
				verts,
				GL_STATIC_DRAW);   //  stores the verts array in a array down to the Graphic Card

			glEnableVertexAttribArray(0);  //  enables the attribute atrray or the data that is copied down to the buffer 
			//  to go throught the process graphic pipeline

			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0); // this function decribes the data to openGL
			//position attr, numb of elements, type, normalise (GL_FALSE means don't touch the data), 


		}

		/// this is called to draw the world
		void draw_world(int x, int y, int w, int h) {
			// the framework gives us the dimensions of the window.
			int vx = 0, vy = 0;
			get_viewport_size(vx, vy);


			glViewport(0, 0, vx, vy); // this func. sets what area of the window we want to render, in this case it just makes the window resizeble

			glDrawArrays(GL_TRIANGLES, 0, 6); // this func. draws
			//(GL_TRIANGLES is what will be drawn, 0 incates at what triangles to start, 3 tells the number of vertices to draw per triamgles



		}
	};
}
