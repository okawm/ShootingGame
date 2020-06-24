#include "Aim.h"

Aim::Aim() {
	vector<array<float, 3>> vp;
	array<float, 3> pa;
	pa = { -1.0f, 0.0f, 0.0f };  vp.push_back(pa);
	pa = { 1.0f, 0.0f, 0.0f };  vp.push_back(pa);
	pa = { 0.0f, -1.0f, 0.0f }; vp.push_back(pa);
	pa = { 0.0f, 1.0f, 0.0f }; vp.push_back(pa);
	Model model;
	model.vertexPos = vp;
	model.scale = vec3(3.0f, 3.0f, 0.1f);
	model.drawingMethod = DRAWWING_METHOD::LINE;
	model.modelMatrix = translate(mModel.pos);
	model.modelMatrix *= scale(vec3(3.0f, .0f, 0.1f));
	model.viewMatrix = lookAt(gCamera.pos, vec3(0.0, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	model.projectionMatrix = perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f);
	init("Shader/Player.vertex", "Shader/Player.fragment", model);
}

void Aim::update() {
	GameObject::draw();
	setTransform(mModel.pos);
}