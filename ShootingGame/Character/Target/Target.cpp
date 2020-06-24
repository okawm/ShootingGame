#include "Target.h"
#include <random>
#include <iostream>
#include "../../Score.h"

Target::Target() {
	vector<array<float, 3>> vp;
	array<float, 3> pa;
	pa = { -1.0f, -1.0f, 0.0f };  vp.push_back(pa);
	pa = { 1.0f, -1.0f, 0.0f };  vp.push_back(pa);
	pa = { 0.0f, 1.0f, 0.0f };  vp.push_back(pa);

	Model m;
	m.pos = vec3(0.0f, 0.0f, -100.0f);
	m.scale = vec3(5.0f, 5.0f, 1.0f);
	m.vertexPos = vp;
	m.drawingMethod = DRAWWING_METHOD::TRIANGLE;
	m.modelMatrix = translate(vec3(0, 0, -100));
	m.modelMatrix *= scale(vec3(5.0f, 5.0f, 1.0f));
	m.viewMatrix = lookAt(gCamera.pos, vec3(0.0, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	m.projectionMatrix = perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f);
	init("Shader/Target.vertex", "Shader/Target.fragment", m);
}

void Target::update() {
	draw();

	mInput.update(getPos());
	if (mInput.down()) {
		Character::move("down");
	}
	if (mInput.up()) {
		Character::move("up");
	}
	if (mInput.left()) {
		Character::move("left");
	}
	if (mInput.right()) {
		Character::move("right");
	}
}

void Target::hit() {
	// スコア加算
	Score::instance().score(10, "add");

	// Targetの位置をランダムに初期化
	random_device seed_gen;
	mt19937 engine(seed_gen());
	normal_distribution<> dist(0, 19);
	float rx = dist(engine);
	float ry = dist(engine);
	Character::setRandomPos(vec3(rx, ry, -100));

	// Targetの動きを変える
	mInput.changeMove();

	// スピードを速くする
	setSpeed(1.5, "add");
}