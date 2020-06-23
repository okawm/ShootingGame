#pragma once
#include "../../GameObject.h"
#include "../../Character.h"
#include <vector>
#include <array>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "../../common/Model.h"
#include "Camera.h"
#include "Aim.h"
#include "PlayerControl.h"
#include "Bullet.h"
#include <iostream>
using namespace glm;

class Player : Character {
public:
	Player();
	~Player();
	void update();
	void shoot();
	vec3 getPos() {
		return Character::getPos();
	}
private:
	Aim mAim;
	PlayerControl mInput;
	std::array<Bullet, 50> mBullets;
};