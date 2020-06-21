#include "Character.h"

Character::Character() {
	/*mPos = { 0,0,0 };
	mSpeed = 1.0f;*/
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