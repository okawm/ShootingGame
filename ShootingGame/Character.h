#pragma once
#include "GameObject.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "common/Gamewindow.h"
#include <vector>
using namespace glm;
#include <string>
using namespace std;
#include <array>
#include "common/Model.h"

class Character :GameObject {
public:
	Character();
	~Character();

	// direction: "left", "right", "up", "down"
	void move(string direction);
	void setSpeed(float speed) {
		mSpeed = speed;
	}
	
private:
protected:
	float mSpeed;
	void draw();
	void init(const char* vsPath, const char*fsPath, Model m);
	vec3 getPos() {
		return mPos;
	}
};