#pragma once
#include "../../GameObject.h"
#include "../../common/Model.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include <vector>
#include "Camera.h"
#include <iostream>
using namespace glm;

class Aim : GameObject{
public:
	Aim();
	~Aim() {};
	void update();
	void setPos(vec3 pos) {
		mModel.pos = pos;
	};
private:
};