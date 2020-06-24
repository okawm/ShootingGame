#include "Player.h"

Player::Player() {
	vector<array<float, 3>> vp;
	array<float, 3> pa;
	pa = { -1.0f, 1.0f, 1.0f };  vp.push_back(pa);
	pa = { 1.0f, 1.0f, 1.0f };  vp.push_back(pa);
	pa = { 1.0f, 1.0f, 1.0f };  vp.push_back(pa);
	pa = { 0.0f, 1.0f, -1.0f };  vp.push_back(pa);
	pa = { 0.0f, 1.0f, -1.0f };  vp.push_back(pa);
	pa = { -1.0f, 1.0f, 1.0f }; vp.push_back(pa);
	pa = { -1.0f, 1.0f, 1.0f }; vp.push_back(pa);
	pa = { 0.0f, -1.0f, 1.0f }; vp.push_back(pa);
	pa = { 1.0f, 1.0f, 1.0f }; vp.push_back(pa);
	pa = { 0.0f, -1.0f, 1.0f }; vp.push_back(pa);
	pa = { 0.0f, 1.0f, -1.0f }; vp.push_back(pa);
	pa = { 0.0f, -1.0f, 1.0f }; vp.push_back(pa);
	Model m;
	m.vertexPos = vp;
	m.scale = vec3(5.0f, 5.0f, 5.0f);
	m.pos = vec3(0.0f, 0.0f, 0.0f);
	m.drawingMethod = DRAWWING_METHOD::LINE;
	m.modelMatrix = translate(vec3(0.0f, 0.0f, 0.0f));
	m.modelMatrix *= scale(vec3(5.0f, 5.0f, 5.0f));
	m.viewMatrix = lookAt(gCamera.pos, vec3(0.0, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	m.projectionMatrix = perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f);
	init("Shader/Player.vertex", "Shader/Player.fragment", m);
	vec3 aimPos = getPos();
	aimPos.y += 5;
	aimPos.z = -100;
	mAim.setPos(aimPos);
	setSpeed(5.0f, "set");
}

Player::~Player() {
}

void Player::update() {
	draw();

	// ì¸óÕ
	mInput.update();
	if (mInput.right) { move("right"); }
	if (mInput.left) { move("left"); }
	if (mInput.down) { move("down"); }
	if (mInput.up) { move("up"); }
	if (mInput.shoot) { shoot(); }

	// è∆èÄ
	vec3 aimPos = getPos();
	aimPos.y += 5;
	aimPos.z = -100;
	mAim.setPos(aimPos);
	mAim.update();

	// íe
	for (int i = 0; i < mBullets.size(); ++i) {
		mBullets[i].update();
	}
}

void Player::shoot() {
	for (int i = 0; i < mBullets.size(); ++i) {
		if (!mBullets[i].getVisible()) {
			mBullets[i].set(getPos());
			break;
		}
	}
}