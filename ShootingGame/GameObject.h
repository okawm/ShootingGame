#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <array>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "common/Model.h"
using namespace glm;
using namespace std;

class GameObject {
public:
	GameObject();
	~GameObject();

	virtual void update() = 0;

protected:
	// viewSize:ウィンドウに表示するサイズ
    virtual void init(const char* vsPath, const char*fsPath, Model m);
	virtual void draw();
	GLuint mProgram;
	GLuint mVao;
	GLuint mVertices;
	mat4 mModelMatrix;
	Model mModel;
};