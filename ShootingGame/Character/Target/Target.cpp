#include "Target.h"

Target::Target() {
	vector<array<float, 3>> vp;
	array<float, 3> pa;
	GLfloat p[][3] = {
		{-1.0f, -1.0f, 0.0f},{1.0f, -1.0f, 0.0f},{0.0f, 1.0f, 0.0f}
	};
	pa = { -1.0f, -1.0f, 0.0f };  vp.push_back(pa);
	pa = { 1.0f, -1.0f, 0.0f };  vp.push_back(pa);
	pa = { 0.0f, 1.0f, 0.0f };  vp.push_back(pa);
	//mat4 mm = translate(vec3(0.0f, 0.0f, -100.0f));//モデル行列
	//mm *= scale(vec3(100.0f, 100.0f, 100.0f));
	//mm *= rotate(t*1.5f, vec3(0.0f, 0.0f, 1.0f));
	//mm *= scale(vec3(5.0f, 5.0f, 1.0f));
	float randomPos[10] = { 10.0f, -10.0f, 21.0f, -7.0f, 14.0f, -9.0f, 23.0f, -11.0f, 2.0f, -4.0f };
	//std::random_device rnd;
	//int x = rnd() % 10;
	//int y = rnd() % 10;
	//mPos = vec3(0, 0, -100);
	mat4 mm = translate(vec3(0,0,-100));//モデル行列
	//float t = glfwGetTime();
	//mm *= rotate(1.5f, vec3(0.0f, 0.0f, 1.0f));
	mm *= scale(vec3(5.0f, 5.0f, 1.0f));
	mat4 mv = lookAt(gCamera.pos, vec3(0.0, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//ビュー行列
	mat4 mp = perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f);//射影行列

	Model m;
	m.pos = vec3(0.0f, 0.0f, -100.0f);
	m.scale = vec3(5.0f, 5.0f, 1.0f);
	m.drawingMethod = DRAWWING_METHOD::TRIANGLE;
	m.modelMatrix = mm;
	m.vertexPos = vp;
	m.viewMatrix = mv;
	m.projectionMatrix = mp;
	init("Shader/Target.vertex", "Shader/Target.fragment", m);
}

void Target::update() {
	mInput.update();
	if (mInput.down) {
		Character::move("down");
	}
	draw();
}