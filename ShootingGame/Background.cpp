#include "Background.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "common/Gamewindow.h"
using namespace glm;

Background::Background() {
	////�V�F�[�_�v���O�����ǂݍ���
	//mProgram = LoadShaders("Shader/Background.vertex", "Shader/Background.fragment");

	////���_�z��I�u�W�F�N�g�̍쐬
	//create();
	init("Shader/Background.vertex", "Shader/Background.fragment", "full");
}

Background::~Background() {

}

void Background::update() {
	draw();
}
