#include "window.h"

bool bmcengine::graphics::Window::init()
{
	if (glfwInit())
		std::cout << "Initializing GLFW." << std::endl;
	else {
		std::cout << "Failed to initialize GLFW!" << std::endl;
		glfwTerminate();
		return false;
	}

	std::cout << "Setting window hints." << std::endl;
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	const GLFWvidmode* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

	if (m_Window)
		std::cout << "Made window." << std::endl;
	else {
		std::cout << "Failed to make window!" << std::endl;
		glfwTerminate();
		return false;
	}
	
	std::cout << "Moving window to center." << std::endl;
	glfwSetWindowPos(m_Window, (vidMode->width / 2) - (m_Width / 2), (vidMode->height / 2) - (m_Height / 2));

	std::cout << "Showing window." << std::endl;
	glfwShowWindow(m_Window);

	return true;
}

void bmcengine::graphics::Window::update()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

bmcengine::graphics::Window::Window(int width, int height, const char *title)
{
	m_Width = width;
	m_Height = height;
	m_Title = title;
	init();
}

bool bmcengine::graphics::Window::ShouldClose()
{
	return glfwWindowShouldClose(m_Window);
}
