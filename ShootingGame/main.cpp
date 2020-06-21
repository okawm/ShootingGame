#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "common/Gamewindow.h"
#pragma comment(lib, "opengl32.lib")
#include "Game.h"

int main(void)
{
	// GLFW������
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	//GameWindow* gw = new GameWindow();
	int windowWidth = 1000;
	int windowHeight = 1000;
	gWindow.window = glfwCreateWindow(windowWidth, windowHeight, "Shooting Game", NULL, NULL);
	if (gWindow.window == NULL) {
		fprintf(stderr, "�E�B���h�E�쐬���s");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(gWindow.window);

	// GLEW������
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	//glfw�^�C�}�[�̃��Z�b�g
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

			// �E�B���h�E�ւ̕`���glfwSwapBuffers()�̑O�ɍs��
			game.update();

			glfwSwapBuffers(gWindow.window);

			glfwPollEvents();
			lastTime = glfwGetTime();
		}

	} while (glfwGetKey(gWindow.window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(gWindow.window) == 0);

	glfwTerminate();

	return 0;
}