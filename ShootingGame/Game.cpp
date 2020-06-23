#include "Game.h"
#include "common/Tex2D.h"
#include "common/Gamewindow.h"

Game::Game() {
	mSeq = SEQ_TITLE;
	initText2D("Texture/Font.DDS");
}

Game::~Game() {

}

void Game::update() {
	static int score = 0;
	switch (mSeq) {
	case SEQ_TITLE:
		mBackground.update();

		printText2D("Shooting Game", 50, 500, 50);
		printText2D("Press Space to Start", 50, 100, 30);

		if (glfwGetKey(Gamewindow::instance().gwindow, GLFW_KEY_SPACE) == GLFW_PRESS) {
			mSeq = SEQ_READY;
		}		
		break;
	case SEQ_READY:
		mBackground.update();
		Manager::instance().getPlayer()->update();
		printText2D("Cursor Key to Move", 50, 500, 30);
		printText2D("Space to Shoot", 50, 400, 30);
		if (glfwGetKey(Gamewindow::instance().gwindow, GLFW_KEY_LEFT) == GLFW_PRESS ||
			glfwGetKey(Gamewindow::instance().gwindow, GLFW_KEY_RIGHT) == GLFW_PRESS ||
			glfwGetKey(Gamewindow::instance().gwindow, GLFW_KEY_UP) == GLFW_PRESS ||
			glfwGetKey(Gamewindow::instance().gwindow, GLFW_KEY_DOWN) == GLFW_PRESS) {
			mSeq = SEQ_PLAY;
		}
		break;
	case SEQ_PLAY:
		mBackground.update();
		Manager::instance().getTarget()->update();
		Manager::instance().getPlayer()->update();

		char text[256];
		sprintf_s(text, "Score:%d", score);
		printText2D(text, 0, 550, 30);
		if (glfwGetKey(Gamewindow::instance().gwindow, GLFW_KEY_ENTER) == GLFW_PRESS) {
			mSeq = SEQ_END;
			score = 0;
		}
		break;
	case SEQ_END:
		mBackground.update();

		char text2[256];
		sprintf_s(text2, "Score is %d", score);
		printText2D(text2, 50, 300, 30);
		printText2D("Press Enter to Return Title", 50, 100, 20);
		if (glfwGetKey(Gamewindow::instance().gwindow, GLFW_KEY_ENTER) == GLFW_PRESS) {
			mSeq = SEQ_TITLE;
			score = 0;
		}
		break;
	}
}