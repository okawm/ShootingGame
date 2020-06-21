#pragma once
#include "GameObject.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "common/Gamewindow.h"
using namespace glm;
#include <string>
using namespace std;

// 動かすオブジェクト
class Character :GameObject {
public:
	Character();
	~Character();

	//void update();

	// direction: "left", "right", "up", "down"
	void move(string direction);
	void setVelocity(float speed) {
		mSpeed = speed;
	}
private:
	//void draw();

protected:
	vec3 mPos;
	float mSpeed;
};