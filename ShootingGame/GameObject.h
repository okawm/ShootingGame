#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <array>
using namespace std;

class GameObject {
public:
	GameObject();
	~GameObject();

	virtual void update() = 0;

protected:
	// viewSize:ウィンドウに表示するサイズ
    virtual void init(const char* vsPath, const char*fsPath, vector<array<float, 3>> vertexP);
	virtual void draw();
	GLuint mProgram;
	GLuint mVao;
	GLuint mVertices;
};