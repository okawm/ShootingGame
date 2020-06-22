#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "common/Gamewindow.h"
#pragma comment(lib, "opengl32.lib")
#include "Game.h"
//static GLFWwindow* gwindow;// = glfwCreateWindow(resolution[0], resolution[1], "Shooting Game", NULL, NULL);

int main(void)
{
	// GLFW初期化
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	//GameWindow* gw = new GameWindow();
	//nt windowWidth = 1000;
	//int windowHeight = 1000;
	//gWindow.window = glfwCreateWindow(windowWidth, windowHeight, "Shooting Game", NULL, NULL);
	Gamewindow gw = Gamewindow::instance();
	if (gw.gwindow == NULL) {
		fprintf(stderr, "ウィンドウ作成失敗");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(gw.gwindow);

	// GLEW初期化
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	//glfwタイマーのリセット
	glfwSetTime(0.0f);

	double FPS = 60.0; 
	double currentTime, lastTime, elapsedTime;
	currentTime = lastTime = elapsedTime = 0.0;
	//Background* bg = new Background();
	Game game;
	do
	{
		currentTime = glfwGetTime();
		elapsedTime = currentTime - lastTime;
		if (elapsedTime >= 1.0 / FPS) {
			glClear(GL_COLOR_BUFFER_BIT);

			// ウィンドウへの描画はglfwSwapBuffers()の前に行う
			game.update();

			glfwSwapBuffers(gw.gwindow);

			glfwPollEvents();
			lastTime = glfwGetTime();
		}

	} while (glfwGetKey(gw.gwindow, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(gw.gwindow) == 0);

	glfwTerminate();

	return 0;
}