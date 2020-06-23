#include "Background.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
#include "common/Gamewindow.h"
using namespace glm;

Background::Background() {
	vector<array<float, 3>> vp;
	array<float, 3> pa;
	pa = { -1.0f, 1.0f, 0.0f };  vp.push_back(pa);
	pa = { -1.0f, -1.0f, 0.0f };  vp.push_back(pa);
	pa = { 1.0f, -1.0f, 0.0f };  vp.push_back(pa);
	pa = { 1.0f, 1.0f, 0.0f };  vp.push_back(pa);
	Model m;
	m.vertexPos = vp;
	m.modelMatrix = translate(vec3(0.0f, 0.0f, -100.0f));
	m.modelMatrix *= scale(vec3(100.0f, 100.0f, 100.0f));
	m.drawingMethod = DRAWWING_METHOD::TRIANGLE_FAN;
	m.viewMatrix = lookAt(vec3(0.0f, 0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));;
	m.projectionMatrix = perspective(radians(45.0f), 1.0f, 0.1f, 200.0f);;
	init("Shader/Background.vertex", "Shader/Background.fragment", m);
}

Background::~Background() {

}

void Background::update() {
	draw();
}
