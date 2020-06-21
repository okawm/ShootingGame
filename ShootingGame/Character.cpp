#include "Character.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "Character/Camera.h"

Character::Character() {
	mPos = { 0,0,0 };
	mSpeed = 1.0f;
}

Character::~Character() {
}

void Character::move(string direction) {
	if (direction == "left") {
		mPos.x -= mSpeed * 0.1f;
	}
	if (direction == "right") {
		mPos.x += mSpeed * 0.1f;
	}
	if (direction == "up") {
		mPos.y += mSpeed * 0.1f;
	}
	if (direction == "down") {
		mPos.y -= mSpeed * 0.1f;
	}
}

void Character::draw() {
	//�V�F�[�_�g�p�J�n
	glUseProgram(mProgram);

	//�ϊ��s��̌v�Z
    //�v���C���[�̈ʒu�X�V
	//���f���s��v�Z
	mat4 mm = translate(mPos);//mat4 mm = input(gw);//�L�[�{�[�h����̓��͂Ń��f���s������߂�
	mm *= scale(vec3(5.0f, 5.0f, 5.0f));
	mat4 mv = lookAt(gCamera.pos, vec3(0.0, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//�r���[�s��
	mat4 mp = perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f);//�ˉe�s��
	mat4 mvp = mp * mv * mm;//���f���r���[�ˉe�s��

	//�V�F�[�_��uniform�ϐ����擾���đ���
	GLuint mvpLoc = glGetUniformLocation(mProgram, "mvp");
	glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, &mvp[0][0]);

	// �`��Ɏg�����_�z��I�u�W�F�N�g�̎w��
	glBindVertexArray(mVao);

	//�`��
	glDrawArrays(GL_LINES, 0, mVertices);

	//vao�w�����
	glBindVertexArray(0);
}

void Character::init(const char* vsPath, const char*fsPath, string viewSize){
	GameObject::init(vsPath, fsPath, viewSize);
}