#include "Bullet.h"
#include "../../Manager.h"
#include <iostream>
Bullet::Bullet() : mVisible(false),mLifeCount(50), mSpeed(4.0f){
	vector<array<float, 3>> vp;
	array<float, 3> pa;
	pa = { -1.0f, 1.0f, 0.7f }; vp.push_back(pa);
	pa = { 1.0f, 1.0f, 0.7f }; vp.push_back(pa);
	pa = { 1.0f, 1.0f, 0.7f }; vp.push_back(pa);
	pa = { 1.0f, 1.0f, -1.3f }; vp.push_back(pa);
	pa = { 1.0f, 1.0f, -1.3f }; vp.push_back(pa);
	pa = { -1.0f, 1.0f, -1.3f }; vp.push_back(pa);
	pa = { -1.0f, 1.0f, -1.3f }; vp.push_back(pa);
	pa = { -1.0f, 1.0f, 0.7f }; vp.push_back(pa);
	pa = { -1.0f, 1.0f, 0.7f }; vp.push_back(pa);
	pa = { -1.0f, -1.0f, 1.3f }; vp.push_back(pa);
	pa = { 1.0f, 1.0f, 0.7f }; vp.push_back(pa);
	pa = { 1.0f, -1.0f, 1.3f }; vp.push_back(pa);
	pa = { 1.0f, 1.0f, -1.3f }; vp.push_back(pa);
	pa = { 1.0f, -1.0f, -1.0f }; vp.push_back(pa);
	pa = { -1.0f, 1.0f, -1.3f }; vp.push_back(pa);
	pa = { -1.0f, -1.0f, -1.0f }; vp.push_back(pa);
	pa = { -1.0f, -1.0f, 1.0f }; vp.push_back(pa);
	pa = { 1.0f, -1.0f, 1.0f }; vp.push_back(pa);
	pa = { 1.0f, -1.0f, 1.0f }; vp.push_back(pa);
	pa = { 1.0f, -1.0f, -1.0f }; vp.push_back(pa);
	pa = { 1.0f, -1.0f, -1.0f }; vp.push_back(pa);
	pa = { -1.0f, -1.0f, -1.0f }; vp.push_back(pa);
	pa = { -1.0f, -1.0f, -1.0f }; vp.push_back(pa);
	pa = { -1.0f, -1.0f, 1.0f }; vp.push_back(pa);
	Model model;
	model.vertexPos = vp;
	model.pos = vec3(0.0f, 0.0f, 0.0f);
	model.scale = vec3(1.0f, 0.05f, 2.0f);
	model.drawingMethod = DRAWWING_METHOD::LINE;
	model.modelMatrix = translate(vec3(0.0f, 0.0f, 0.0f));
	model.modelMatrix *= scale(vec3(3.0f, 0.1f, 0.1f));
	model.viewMatrix = lookAt(gCamera.pos, vec3(0.0, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//ƒrƒ…[s—ñ
	model.projectionMatrix = perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f);
	init("Shader/Bullet.vertex", "Shader/Bullet.fragment", model);
}

void Bullet::set(vec3 playerPos) {
	mVisible = true;
	mModel.pos = playerPos;
	mModel.pos.y += 5.0f;
	setTransform(mModel.pos);
}
void Bullet::update() {
	if (mVisible) {
		static int count = 0;
		if (collide(Manager::instance().getTarget()->getPos())) {
			mVisible = false;
  			Manager::instance().getTarget()->hit();
		}
		mModel.pos.z -= mSpeed;
		setTransform(mModel.pos);
		draw();
		if (count > mLifeCount) { mVisible = false; count = 0; }
		count++;
	}
}