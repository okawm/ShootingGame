#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
using namespace std;

// ウィンドウに描画するオブジェクト
class GameObject {
public:
	GameObject();
	~GameObject();

	virtual void update() = 0;

protected:
	// viewSize:ウィンドウに表示するサイズ
    void init(const char* vsPath, const char*fsPath, string viewSize);
	virtual void draw();
private:
	GLuint mProgram;
	GLuint mVao;
	GLuint mVertices;
};