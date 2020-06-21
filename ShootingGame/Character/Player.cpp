#include "Player.h"

Player::Player() {

	////頂点配列オブジェクトの作成
	//create();

	////bulletクラスを作成
	//mBullets = new Bullet[mBulletNum];

	////位置など初期化
	
	init("Shader/Player.vertex", "Shader/Player.fragment", "Player");
}

Player::~Player() {

}

void Player::update() {
	draw();
}
void Player::shoot() {

}