#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct Gamewindow {
	GLFWwindow* window;
	float resolution[2] = { 1000, 1000 };
};
static Gamewindow gWindow;