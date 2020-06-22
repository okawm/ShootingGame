#include "Game.h"
#include "common/Tex2D.h"
#include "common/Gamewindow.h"

Game::Game() {
	//mBackground = new Background();
	mSeq = SEQ_TITLE;
	//フォント読み込む
	initText2D("Texture/Font.DDS");
}

Game::~Game() {

}

void Game::update() {
	static int score = 0;
	Gamewindow gw = Gamewindow::instance();
	switch (mSeq) {
	case SEQ_TITLE:
		mBackground.update();

		// prinText2Dを使う前に、initText2Dでフォントを読み込んでおく
		printText2D("Shooting Game", 50, 500, 50);
		printText2D("Press Space to Start", 50, 100, 30);

		if (glfwGetKey(gw.gwindow, GLFW_KEY_SPACE) == GLFW_PRESS) {//spaceキーを押したら
			mSeq = SEQ_READY;
		}		
		break;
	case SEQ_READY:
		mBackground.update();
		mPlayer.update();

		printText2D("Cursor Key to Move", 50, 500, 30);
		printText2D("Space to Shoot", 50, 400, 30);
		if (glfwGetKey(gw.gwindow, GLFW_KEY_LEFT) == GLFW_PRESS ||
			glfwGetKey(gw.gwindow, GLFW_KEY_RIGHT) == GLFW_PRESS ||
			glfwGetKey(gw.gwindow, GLFW_KEY_UP) == GLFW_PRESS ||
			glfwGetKey(gw.gwindow, GLFW_KEY_DOWN) == GLFW_PRESS) {//spaceキーを押したら
			mSeq = SEQ_PLAY;
		}
		break;
	case SEQ_PLAY:
		mBackground.update();
		mTarget.update();
		mPlayer.update();
		char text[256];
		sprintf_s(text, "Score:%d", score);
		printText2D(text, 0, 550, 30);
		if (glfwGetKey(gw.gwindow, GLFW_KEY_ENTER) == GLFW_PRESS) {
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
		if (glfwGetKey(gw.gwindow, GLFW_KEY_ENTER) == GLFW_PRESS) {
			mSeq = SEQ_TITLE;
			score = 0;
		}
		break;
	}
}