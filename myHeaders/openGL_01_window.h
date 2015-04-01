////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2012-2014 - Modular Framework for OpenGLES2 rendering on multiple platforms.
//
// OpenGL Learning Project - Create a window

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

		}

		/// this is called to draw the world
		void draw_world(int x, int y, int w, int h) {
			// the framework gives us the dimensions of the window.
			int vx = 0, vy = 0;
			get_viewport_size(vx, vy);

			/// set a viewport - includes whole window area
			glClearColor(1, 0, 0, 1);       // this line sets the color... R G B A
			glClear(GL_COLOR_BUFFER_BIT);   // openGl clear the buffer

		}
	};
}
