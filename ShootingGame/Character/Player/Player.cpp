#include "Player.h"

Player::Player() {

	////頂点配列オブジェクトの作成
	//create();

	////bulletクラスを作成
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
	mat4 mv = lookAt(gCamera.pos, vec3(0.0, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//ビュー行列
	mat4 mp = perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f);//射影行列
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
	mBullet[0].update();
	mInput.update();
	if (mInput.right) { move("right"); }
	if (mInput.left) { move("left"); }
	if (mInput.down) { move("down"); }
	if (mInput.up) { move("up"); }
	if (mInput.shoot) { shoot(); }
	draw();
	vec3 aimPos = getPos();
	aimPos.y += 5;
	aimPos.z = -100;
	mAim.setPos(aimPos);
	mAim.update();
}

void Player::shoot() {
	mBullet[0].set();
}