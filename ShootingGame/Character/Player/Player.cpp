#include "Player.h"

Player::Player() {

	////���_�z��I�u�W�F�N�g�̍쐬
	//create();

	////bullet�N���X���쐬
	//mBullets = new Bullet[mBulletNum];
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
	mat4 mm = translate(vec3(0.0f, 0.0f, 0.0f));
	mm *= scale(vec3(5.0f, 5.0f, 5.0f));
	mat4 mv = lookAt(gCamera.pos, vec3(0.0, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//�r���[�s��
	mat4 mp = perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f);//�ˉe�s��
	Model m;
	m.scale = vec3(5.0f, 5.0f, 5.0f);
	m.pos = vec3(0.0f, 0.0f, 0.0f);
	m.drawingMethod = DRAWWING_METHOD::LINE;
	m.modelMatrix = mm;
	m.vertexPos = vp;
	m.viewMatrix = mv;
	m.projectionMatrix = mp;
	init("Shader/Player.vertex", "Shader/Player.fragment", m);
	vec3 aimPos = getPos();
	aimPos.y += 5;
	aimPos.z = -100;
	mAim.setPos(aimPos);
	setSpeed(10.0f);
}

Player::~Player() {

}

void Player::update() {
	draw();

	// ����
	mInput.update();
	if (mInput.right) { move("right"); }
	if (mInput.left) { move("left"); }
	if (mInput.down) { move("down"); }
	if (mInput.up) { move("up"); }
	if (mInput.shoot) { shoot(); }

	// �Ə�
	vec3 aimPos = getPos();
	aimPos.y += 5;
	aimPos.z = -100;
	mAim.setPos(aimPos);
	mAim.update();

	// �e
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