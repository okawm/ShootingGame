#include "PlayerControl.h"

PlayerControl::PlayerControl() : 
mLeft(false),mRight(false),mUp(false),mDown(false),mShoot(false){
}
void PlayerControl::update() {
	mLeft = false;
	mRight = false;
	mUp = false;
	mDown = false;
	mShoot = false;
	Gamewindow gw = Gamewindow::instance();
	if (glfwGetKey(gw.gwindow, GLFW_KEY_SPACE) == GLFW_PRESS) {
		mShoot = true;
	}
	if (glfwGetKey(gw.gwindow, GLFW_KEY_LEFT) == GLFW_PRESS) {
		mLeft = true;
	}
	if (glfwGetKey(gw.gwindow, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		mRight = true;
	}
	if (glfwGetKey(gw.gwindow, GLFW_KEY_UP) == GLFW_PRESS) {
		mUp = true;
	}
	if (glfwGetKey(gw.gwindow, GLFW_KEY_DOWN) == GLFW_PRESS) {
		mDown = true;
	}
}