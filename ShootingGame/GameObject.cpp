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
	//シェーダプログラム読み込み
	mProgram = LoadShaders(vsPath, fsPath);
	GLfloat p[30][3];// 配列の要素数は多めに取っている

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
	//シェーダプログラムの使用開始
	glUseProgram(mProgram);

	// 時刻の計測
	float t(glfwGetTime());

	//変換行列の計算
	mat4 mm = mModel.modelMatrix;
	mat4 mv = mModel.viewMatrix;//lookAt(vec3(0.0f, 0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//ビュー行列
	mat4 mp = mModel.projectionMatrix;//perspective(radians(45.0f), gWindow.resolution[0] / gWindow.resolution[1], 0.1f, 200.0f);//プロジェクション(射影)行列
	mat4 mvp = mp * mv * mm;//モデルビュー射影行列

	//シェーダのuniform変数
	GLuint timeLoc = glGetUniformLocation(mProgram, "time");//時間
	GLuint resolutionLoc = glGetUniformLocation(mProgram, "resolution");//ウィンドウサイズ
	GLuint mvpLoc = glGetUniformLocation(mProgram, "mvp");//変換行列

	//シェーダへ送る
	glUniform1f(timeLoc, t);
	float resolution[2] = { 1000, 1000 };

	glUniform2fv(resolutionLoc, 1, resolution);
	glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, &mvp[0][0]);

	// 描画に使う頂点配列オブジェクトの指定
	glBindVertexArray(mVao);

	//描画
	if (mModel.drawingMethod == DRAWWING_METHOD::LINE) {
		glDrawArrays(GL_LINES, 0, mVertices);
	}
	if (mModel.drawingMethod == DRAWWING_METHOD::TRIANGLE) {
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	//vao指
	if (mModel.drawingMethod == DRAWWING_METHOD::TRIANGLE_FAN) {
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}

	// 頂点配列オブジェクトの指定解除
	glBindVertexArray(0);

	//シェーダプログラムの使用終了
	glUseProgram(0);
}

