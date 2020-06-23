#include "Bullet.h"

Bullet::Bullet() : visible(false),countVisible(0){
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
	visible = true;
	mModel.pos = playerPos;
	mModel.pos.y += 5.0f;
	countVisible = 0;
	setTransform(mModel.pos);
}
void Bullet::update() {
	if (visible) {
		countVisible++;
		mModel.pos.z -= 2.0f;
		setTransform(mModel.pos);
		draw();
		if (countVisible > 50) { visible = false; }
	}
}