#include "Player.h"

Player::Player() {

	////���_�z��I�u�W�F�N�g�̍쐬
	//create();

	////bullet�N���X���쐬
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
	mat4 mm = translate(vec3(0.0f, 0.0f, 0.0f));
	mm *= scale(vec3(5.0f, 5.0f, 5.0f));
	mat4 mv = lookAt(gCamera.pos, vec3(0.0, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//�r���[�s��
	mat4 mp = perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f);//�ˉe�s��
	Model m;
	m.drawingMethod = DRAWWING_METHOD::LINE;
	m.modelMatrix = mm;
	m.vertexPos = vp;
	m.viewMatrix = mv;
	m.projectionMatrix = mp;
	init("Shader/Player.vertex", "Shader/Player.fragment", m);
}

Player::~Player() {

}

void Player::update() {
	draw();
}

void Player::shoot() {

}