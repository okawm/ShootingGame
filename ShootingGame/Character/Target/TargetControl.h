#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../common/Gamewindow.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
using namespace glm;
using namespace std;
class TargetControl {
public:
	TargetControl();
	~TargetControl() {};
	void update(vec3 pos);
	bool left() { return mLeft; }
	bool right() { return mRight; }
	bool up() { return mUp; }
	bool down() { return mDown; }

	// “®‚«‚ðƒ‰ƒ“ƒ_ƒ€‚É•Ï‚¦‚é
	void changeMove();
private:
	bool mLeft;
	bool mRight;
	bool mUp;
	bool mDown;
};