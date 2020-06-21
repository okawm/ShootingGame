#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
using namespace std;

// �E�B���h�E�ɕ`�悷��I�u�W�F�N�g
class GameObject {
public:
	GameObject();
	~GameObject();

	virtual void update() = 0;

protected:
	// viewSize:�E�B���h�E�ɕ\������T�C�Y
    void init(const char* vsPath, const char*fsPath, string viewSize);
	virtual void draw();
private:
	GLuint mProgram;
	GLuint mVao;
	GLuint mVertices;
};