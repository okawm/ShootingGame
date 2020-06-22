#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../common/Gamewindow.h"

class PlayerControl {
public:
	PlayerControl();
	~PlayerControl() {};
	void update();
	bool left;
	bool right;
	bool up;
	bool down;
	bool shoot;
private:
};