#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "common/Gamewindow.h"
#pragma comment(lib, "opengl32.lib")
#include "Game.h"

int main(void)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	if (Gamewindow::instance().gwindow == NULL) {
		fprintf(stderr, "ウィンドウ作成失敗");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(Gamewindow::instance().gwindow);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	glfwSetTime(0.0f);

	double FPS = 60.0; 
	double currentTime, lastTime, elapsedTime;
	currentTime = lastTime = elapsedTime = 0.0;
	Game game;
	do
	{
		currentTime = glfwGetTime();
		elapsedTime = currentTime - lastTime;
		if (elapsedTime >= 1.0 / FPS) {
			glClear(GL_COLOR_BUFFER_BIT);

			game.update();

			glfwSwapBuffers(Gamewindow::instance().gwindow);

			glfwPollEvents();
			lastTime = glfwGetTime();
		}

	} while (glfwGetKey(Gamewindow::instance().gwindow, GLFW_KEY_ESCAPE) != GLFW_PRESS 
		&& glfwWindowShouldClose(Gamewindow::instance().gwindow) == 0);

	glfwTerminate();

	return 0;
}