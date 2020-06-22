#pragma once
#include "../../GameObject.h"
#include "Camera.h"
class Bullet : GameObject {
public:
	Bullet();
	~Bullet(){}
	void update();
	void set() {
		visible = true;
	}
private:
	bool visible;
	int countVisible;
};