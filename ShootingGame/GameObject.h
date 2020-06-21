#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
using namespace std;

class GameObject {
public:
	GameObject();
	~GameObject();

	virtual void update() = 0;

protected:
	// viewSize:�E�B���h�E�ɕ\������T�C�Y
    virtual void init(const char* vsPath, const char*fsPath, string viewSize);
	virtual void draw();
	GLuint mProgram;
	GLuint mVao;
	GLuint mVertices;
};