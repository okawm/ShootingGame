#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../common/Gamewindow.h"

class PlayerControl {
public:
	PlayerControl();
	~PlayerControl() {};

	void update();

	bool left() { return mLeft; }
	bool right() { return mRight; }
	bool up() { return mUp; }
	bool down(){ return mDown; }
	bool shoot(){ return mShoot; }
private:
	bool mLeft, mRight, mUp, mDown, mShoot;
};