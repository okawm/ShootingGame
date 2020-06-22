#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Gamewindow {
public:
	static Gamewindow& instance()
	{
		static Gamewindow *instance = new Gamewindow();
		return *instance;
	}
	GLFWwindow* gwindow;
private:
	Gamewindow() {
		gwindow = glfwCreateWindow(1000, 1000, "Shooting Game", NULL, NULL);
	};
};