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
protected:
	vec3 mPos;
	float mSpeed;
	void draw();
	void init(const char* vsPath, const char*fsPath, vector<array<float, 3>> vertexP);
};