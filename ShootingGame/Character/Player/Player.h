#pragma once
#include "../../GameObject.h"
#include "../../Character.h"
#include <vector>
#include <array>

class Player : Character {
public:
	Player();
	~Player();
	void update();
	void shoot();

private:
};