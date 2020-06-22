#pragma once
#include <vector>
#include <array>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
using namespace glm;
using namespace std;

enum DRAWWING_METHOD {
	LINE,
	TRIANGLE,
	TRIANGLE_FAN,
};

struct Model {
	vector<array<float, 3>> vertexPos;
	mat4 modelMatrix;
	mat4 viewMatrix;
	mat4 projectionMatrix;
	DRAWWING_METHOD drawingMethod;
};

