#include "graphics/window.h"

int main() {
	using namespace bmcengine::graphics;
	Window window(1280, 720, "BMCEngine");
	while (!window.ShouldClose()) {
		window.update();
	}
	glfwTerminate();
	return 0;
}