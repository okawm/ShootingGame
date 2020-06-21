#pragma once
#include "../GameObject.h"
#include "../Character.h"

class Player : Character {
public:
	Player();
	~Player();
	void update();
	void shoot();

private:
};