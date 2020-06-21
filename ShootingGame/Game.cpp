#include "Game.h"
#include "common/Tex2D.h"
#include "common/Gamewindow.h"

Game::Game() {
	//mBackground = new Background();
	mSeq = SEQ_READY;
	//�t�H���g�ǂݍ���
	initText2D("Texture/Font.DDS");
}

Game::~Game() {

}

void Game::update() {
	switch (mSeq) {
	case SEQ_TITLE:
		mBackground.update();

		// prinText2D���g���O�ɁAinitText2D�Ńt�H���g��ǂݍ���ł���
		printText2D("Shooting Game", 50, 500, 50);
		printText2D("Press Space to Start", 50, 100, 30);

		//if (glfwGetKey(gWindow.window, GLFW_KEY_SPACE) == GLFW_PRESS) {//space�L�[����������
		//	mSeq = SEQ_READY;
		//	//mPlayer->init();
		//}		
		break;
	case SEQ_READY:
		//mBackground.update();
		mBackground.update();

		printText2D("Cursor Key to Move", 50, 500, 30);
		printText2D("Space to Shoot", 50, 400, 30);
		mPlayer.update();

		break;
	case SEQ_PLAY:
		mBackground.update();
		break;
	case SEQ_END:
		mBackground.update();
		break;
	}
}