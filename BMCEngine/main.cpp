#include "Window.h"
#include "Files.h"
#include "Renderer.h"

Window window;
Files fileManager;
Renderer renderer;

int main() {
	window.createWindow("BMCEngine");
	renderer.setup();
	while (!glfwWindowShouldClose(window.window)) {
		window.update();
		renderer.render();
	}
	glfwTerminate();
	return 0;
}