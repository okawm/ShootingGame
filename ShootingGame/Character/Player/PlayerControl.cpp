#include "PlayerControl.h"

PlayerControl::PlayerControl() : 
left(false),right(false),up(false),down(false),shoot(false){
}
void PlayerControl::update() {
	left = false;
	right = false;
	up = false;
	down = false;
	shoot = false;
	Gamewindow gw = Gamewindow::instance();
	if (glfwGetKey(gw.gwindow, GLFW_KEY_SPACE) == GLFW_PRESS) {
		shoot = true;
	}
	if (glfwGetKey(gw.gwindow, GLFW_KEY_LEFT) == GLFW_PRESS) {
		left = true;
	}
	if (glfwGetKey(gw.gwindow, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		right = true;
	}
	if (glfwGetKey(gw.gwindow, GLFW_KEY_UP) == GLFW_PRESS) {
		up = true;
	}
	if (glfwGetKey(gw.gwindow, GLFW_KEY_DOWN) == GLFW_PRESS) {
		down = true;
	}
}