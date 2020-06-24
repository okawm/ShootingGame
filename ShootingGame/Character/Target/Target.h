#pragma once
#include "../../Character.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include <vector>
#include "../../common/Model.h"
#include "../Player/Camera.h"
#include "TargetControl.h"

using namespace glm;

class Target : Character {
public:
	Target();
	~Target() {};
	void update();
	vec3 getPos() {
		return Character::getPos();
	}
	// Target‚ÆBullet‚ªÕ“Ë‚µ‚½‚Æ‚«‚ÉŒÄ‚Î‚ê‚é
	void hit();
private:
	TargetControl mInput;
};