#pragma once
#include "../../GameObject.h"
#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
using namespace glm;

class Bullet : GameObject {
public:
	Bullet();
	~Bullet(){}
	void update();
	void set(vec3  playerPos);
	bool getVisible() {
		return mVisible;
	}
private:
	bool mVisible;
	int mLifeCount;
	float mSpeed;
};