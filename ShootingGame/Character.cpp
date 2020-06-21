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
	//シェーダ使用開始
	glUseProgram(mProgram);

	//変換行列の計算
    //プレイヤーの位置更新
	//モデル行列計算
	mat4 mm = translate(mPos);//mat4 mm = input(gw);//キーボードからの入力でモデル行列を決める
	mm *= scale(vec3(5.0f, 5.0f, 5.0f));
	mat4 mv = lookAt(gCamera.pos, vec3(0.0, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//ビュー行列
	mat4 mp = perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f);//射影行列
	mat4 mvp = mp * mv * mm;//モデルビュー射影行列

	//シェーダのuniform変数を取得して送る
	GLuint mvpLoc = glGetUniformLocation(mProgram, "mvp");
	glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, &mvp[0][0]);

	// 描画に使う頂点配列オブジェクトの指定
	glBindVertexArray(mVao);

	//描画
	glDrawArrays(GL_LINES, 0, mVertices);

	//vao指定解除
	glBindVertexArray(0);
}

void Character::init(const char* vsPath, const char*fsPath, string viewSize){
	GameObject::init(vsPath, fsPath, viewSize);
}