#include "Character.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "Character/Player/Camera.h"

Character::Character() {
	mPos = { 0,0,0 };
	mSpeed = 1.0f;
}

Character::~Character() {
}

void Character::move(string direction) {
	if (direction == "left") {
		mPos.x -= mSpeed * 0.1f;
	}
	if (direction == "right") {
		mPos.x += mSpeed * 0.1f;
	}
	if (direction == "up") {
		mPos.y += mSpeed * 0.1f;
	}
	if (direction == "down") {
		mPos.y -= mSpeed * 0.1f;
	}
}

void Character::draw() {
	GameObject::draw();
}

void Character::init(const char* vsPath, const char*fsPath, Model m){
	GameObject::init(vsPath, fsPath, m);
}