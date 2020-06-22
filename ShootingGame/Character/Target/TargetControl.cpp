#include "TargetControl.h"

TargetControl::TargetControl() :
	left(false), right(false), up(false), down(false), shoot(false), rotate(false) {
}
void TargetControl::update() {
	left = false;
	right = false;
	up = false;
	down = true;
	shoot = false;
}