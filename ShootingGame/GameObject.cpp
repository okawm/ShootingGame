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


void GameObject::init(const char* vsPath, const char* fsPath, string viewSize) {
	//シェーダプログラム読み込み
	mProgram = LoadShaders(vsPath, fsPath);

	if (viewSize == "full") {
		GLfloat p[][3] = {
			{-1.0f, 1.0f, 0.0f} ,{-1.0f, -1.0f, 0.0f}, {1.0f, -1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}
		};
		
		glGenVertexArrays(1, &mVao);
		glBindVertexArray(mVao);

		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof p, p, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);
	}
	else if (viewSize == "Player") {
		//プレイヤー
		GLfloat p[][3] = {
			{-1.0f, 1.0f, 1.0f},{1.0f, 1.0f, 1.0f},
			{1.0f, 1.0f, 1.0f},{0.0f, 1.0f, -1.0f},
			{0.0f, 1.0f, -1.0f},{-1.0f, 1.0f, 1.0f},
			{-1.0f, 1.0f, 1.0f},{0.0f, -1.0f, 1.0f},
			{1.0f, 1.0f, 1.0f},{0.0f, -1.0f, 1.0f},
			{0.0f, 1.0f, -1.0f},{0.0f, -1.0f, 1.0f }
		};
		mVertices = sizeof p / sizeof p[0];

		//GLuint vao;
		glGenVertexArrays(1, &mVao);
		glBindVertexArray(mVao);

		//頂点バッファオブジェクト
		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof p, p, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);
	}
	else {
		fprintf(stderr, "GameObject初期化できませんでした\n");
	}
}

void GameObject::draw() {
	//シェーダプログラムの使用開始
	glUseProgram(mProgram);

	// 時刻の計測
	float t(glfwGetTime());

	//変換行列の計算
	mat4 mm = translate(vec3(0.0f, 0.0f, -100.0f));//モデル行列
	mm *= scale(vec3(100.0f, 100.0f, 100.0f));
	mat4 mv = lookAt(vec3(0.0f, 0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));//ビュー行列
	mat4 mp = perspective(radians(45.0f), gWindow.resolution[0] / gWindow.resolution[1], 0.1f, 200.0f);//プロジェクション(射影)行列
	mat4 mvp = mp * mv * mm;//モデルビュー射影行列

	//シェーダのuniform変数
	GLuint timeLoc = glGetUniformLocation(mProgram, "time");//時間
	GLuint resolutionLoc = glGetUniformLocation(mProgram, "resolution");//ウィンドウサイズ
	GLuint mvpLoc = glGetUniformLocation(mProgram, "mvp");//変換行列

	//シェーダへ送る
	glUniform1f(timeLoc, t);
	glUniform2fv(resolutionLoc, 1, gWindow.resolution);
	glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, &mvp[0][0]);

	// 描画に使う頂点配列オブジェクトの指定
	glBindVertexArray(mVao);

	//描画
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	// 頂点配列オブジェクトの指定解除
	glBindVertexArray(0);

	//シェーダプログラムの使用終了
	glUseProgram(0);
}