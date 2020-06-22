#include "Background.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "common/Gamewindow.h"
using namespace glm;

Background::Background() {
	////シェーダプログラム読み込み
	//mProgram = LoadShaders("Shader/Background.vertex", "Shader/Background.fragment");

	vector<array<float, 3>> vp;
	array<float, 3> pa;
	pa = { -1.0f, 1.0f, 0.0f };  vp.push_back(pa);
	pa = { -1.0f, -1.0f, 0.0f };  vp.push_back(pa);
	pa = { 1.0f, -1.0f, 0.0f };  vp.push_back(pa);
	pa = { 1.0f, 1.0f, 0.0f };  vp.push_back(pa);
	mat4 mm = translate(vec3(0.0f, 0.0f, -100.0f));//モデル行列
	mm *= scale(vec3(100.0f, 100.0f, 100.0f));
	mat4 mv = lookAt(vec3(0.0f, 0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//ビュー行列
	mat4 mp = perspective(radians(45.0f), gWindow.resolution[0] / gWindow.resolution[1], 0.1f, 200.0f);//プロジェクション(射影)行列
	Model m;
	m.vertexPos = vp;
	m.modelMatrix = mm;
	m.drawingMethod = DRAWWING_METHOD::TRIANGLE_FAN;
	m.viewMatrix = mv;
	m.projectionMatrix = mp;
	init("Shader/Background.vertex", "Shader/Background.fragment", m);
}

Background::~Background() {

}

void Background::update() {
	draw();
}
