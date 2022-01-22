#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <gl/GL.h>

namespace bmcengine {
	namespace graphics {
		class Window
		{
		private:
			GLFWwindow* m_Window;
			int m_Width, m_Height;
			const char* m_Title;
		public:
			bool init();
			void update();
			Window(int width, int height, const char *title);
			bool ShouldClose();
		};
	}
}