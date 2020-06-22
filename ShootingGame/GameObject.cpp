#include "GameObject.h"
#include "common/Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "common/Gamewindow.h"
#include <array>
#include <vector>
using namespace glm;
using namespace std;
GameObject::GameObject() {
}

GameObject::~GameObject() {

}


void GameObject::init(const char* vsPath, const char* fsPath, Model m) {
	//�V�F�[�_�v���O�����ǂݍ���
	mProgram = LoadShaders(vsPath, fsPath);
	GLfloat p[30][3];// �z��̗v�f���͑��߂Ɏ���Ă���

	for (int i = 0; i < m.vertexPos.size(); i++) {
		for (int j = 0; j < 3; j++) {
			p[i][j] = m.vertexPos[i][j];
		}
	}
	mVertices = sizeof p / sizeof p[0];

	glGenVertexArrays(1, &mVao);
	glBindVertexArray(mVao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof p, p, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	mModel = m;
}

void GameObject::setTransform(vec3 pos) {
	mModel.modelMatrix = translate(mModel.pos);
	mModel.modelMatrix *= scale(mModel.scale);
}

void GameObject::draw() {
	//�V�F�[�_�v���O�����̎g�p�J�n
	glUseProgram(mProgram);

	// �����̌v��
	float t(glfwGetTime());

	//�ϊ��s��̌v�Z
	mat4 mm = mModel.modelMatrix;
	mat4 mv = mModel.viewMatrix;//lookAt(vec3(0.0f, 0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//�r���[�s��
	mat4 mp = mModel.projectionMatrix;//perspective(radians(45.0f), gWindow.resolution[0] / gWindow.resolution[1], 0.1f, 200.0f);//�v���W�F�N�V����(�ˉe)�s��
	mat4 mvp = mp * mv * mm;//���f���r���[�ˉe�s��

	//�V�F�[�_��uniform�ϐ�
	GLuint timeLoc = glGetUniformLocation(mProgram, "time");//����
	GLuint resolutionLoc = glGetUniformLocation(mProgram, "resolution");//�E�B���h�E�T�C�Y
	GLuint mvpLoc = glGetUniformLocation(mProgram, "mvp");//�ϊ��s��

	//�V�F�[�_�֑���
	glUniform1f(timeLoc, t);
	float resolution[2] = { 1000, 1000 };

	glUniform2fv(resolutionLoc, 1, resolution);
	glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, &mvp[0][0]);

	// �`��Ɏg�����_�z��I�u�W�F�N�g�̎w��
	glBindVertexArray(mVao);

	//�`��
	if (mModel.drawingMethod == DRAWWING_METHOD::LINE) {
		glDrawArrays(GL_LINES, 0, mVertices);
	}
	if (mModel.drawingMethod == DRAWWING_METHOD::TRIANGLE) {
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	//vao�w
	if (mModel.drawingMethod == DRAWWING_METHOD::TRIANGLE_FAN) {
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}

	// ���_�z��I�u�W�F�N�g�̎w�����
	glBindVertexArray(0);

	//�V�F�[�_�v���O�����̎g�p�I��
	glUseProgram(0);
}

