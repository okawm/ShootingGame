#include "Player.h"

Player::Player() {

	////頂点配列オブジェクトの作成
	//create();

	////bulletクラスを作成
	//mBullets = new Bullet[mBulletNum];
	vector<array<float, 3>> vp;
	array<float, 3> pa;
	pa = { -1.0f, 1.0f, 0.0f };  vp.push_back(pa);
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

	init("Shader/Player.vertex", "Shader/Player.fragment", vp);
}

Player::~Player() {

}

void Player::update() {
	draw();
}
void Player::shoot() {

}