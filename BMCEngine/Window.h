#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:
	void createWindow(const char* title);
	void update();
public:
	GLFWwindow* window;
};