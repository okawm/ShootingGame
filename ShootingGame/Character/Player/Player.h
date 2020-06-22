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

using namespace glm;
class Player : Character {
public:
	Player();
	~Player();
	void update();
	void shoot();
private:
	Aim mAim;
	PlayerControl mInput;
	Bullet mBullet[100];
};