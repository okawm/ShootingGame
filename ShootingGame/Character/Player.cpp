#include "Player.h"

Player::Player() {

	////���_�z��I�u�W�F�N�g�̍쐬
	//create();

	////bullet�N���X���쐬
	//mBullets = new Bullet[mBulletNum];

	////�ʒu�ȂǏ�����
	
	init("Shader/Player.vertex", "Shader/Player.fragment", "Player");
}

Player::~Player() {

}

void Player::update() {
	draw();
}
void Player::shoot() {

}