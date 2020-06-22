#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../common/Gamewindow.h"

class TargetControl {
public:
	TargetControl();
	~TargetControl() {};
	void update();
	bool left;
	bool right;
	bool up;
	bool down;
	bool shoot;
	bool rotate;
private:
};