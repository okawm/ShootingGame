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
	mInput.update();
	if (mInput.down) {
		Character::move("down");
	}
	draw();
	if (mCollided) {
		Score::instance().score(10, "add");
		float randomPos[10] = { 10.0f, -10.0f, 21.0f, -7.0f, 14.0f, -9.0f, 23.0f, -11.0f, 2.0f, -4.0f };
		std::random_device rnd;
		int x = rnd() % 10;
		int y = rnd() % 10;
		vec3 p = vec3(randomPos[x], randomPos[y], -100);
		Character::setRandomPos(p);
		mCollided = false;
	}
}
