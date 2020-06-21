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
	init("Shader/Background.vertex", "Shader/Background.fragment", vp);
}

Background::~Background() {

}

void Background::update() {
	draw();
}
