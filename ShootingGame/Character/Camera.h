#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>
using namespace glm;

struct Camera{
	vec3 pos = { 0.0f, 10.0f, 100.0f };
};
static Camera gCamera;
