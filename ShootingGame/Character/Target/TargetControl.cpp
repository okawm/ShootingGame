#include "TargetControl.h"
#include <random>
#include <iostream>

TargetControl::TargetControl() :
	mLeft(false), mRight(false), mUp(false), mDown(false) {
}
void TargetControl::update(vec3 pos) {
	if (pos.x <= -20) { mRight = true; mLeft = false; }
	if (pos.x >= 20) { mLeft = true; mRight = false; }
	if (pos.y <= -20) { mUp = true; mDown = false; }
	if (pos.y >= 20) { mDown = true; mUp = false; }
}

void TargetControl::changeMove() {
	mLeft = false; mRight = false; mUp = false; mDown = false;
	random_device seed_gen;
	mt19937 engine(seed_gen());
	uniform_int_distribution<> dist(0, 7);
	int r = dist(engine);
	if (r == 0) { mRight = true; }
	if (r == 1) { mLeft = true; }
	if (r == 2) { mUp = true; }
	if (r == 3) { mDown = true; }
	if (r == 4) { mLeft = true; mUp = true; }
	if (r == 5) { mLeft = true; mDown = true; }
	if (r == 6) { mRight = true; mUp = true; }
	if (r == 7) { mRight = true; mDown = true; }
}