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

	////頂点配列オブジェクトの作成
	//create();
	init("Shader/Background.vertex", "Shader/Background.fragment", "full");
}

Background::~Background() {

}

void Background::update() {
	draw();
}
