#include "Window.h"

void Window::createWindow(const char* title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	const GLFWvidmode* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	window = glfwCreateWindow(vidMode->width / 1.1, vidMode->height / 1.2, title, NULL, NULL);
	glfwSetWindowPos(window, vidMode->width / 25, vidMode->height / 17);

	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glViewport(0, 0, vidMode->width / 1.1, vidMode->height / 1.2);
}

void Window::update() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}