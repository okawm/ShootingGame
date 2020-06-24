#include "Character.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "Character/Player/Camera.h"

Character::Character() :mSpeed(1.0f){
}

Character::~Character() {
}

void Character::move(string direction) {
	if (direction == "left") {
		mModel.pos.x -= mSpeed * 0.1f;
		setTransform(mModel.pos);
	}
	if (direction == "right") {
		mModel.pos.x += mSpeed * 0.1f;
		setTransform(mModel.pos);
	}
	if (direction == "up") {
		mModel.pos.y += mSpeed * 0.1f;
		setTransform(mModel.pos);
	}
	if (direction == "down") {
		mModel.pos.y -= mSpeed * 0.1f;
		setTransform(mModel.pos);
	}
}

void Character::setRandomPos(vec3 pos) {
	mModel.pos = pos;
	setTransform(mModel.pos);
}
void Character::draw() {
	GameObject::draw();
}

void Character::init(const char* vsPath, const char*fsPath, Model m){
	GameObject::init(vsPath, fsPath, m);
}