#pragma once
#include "Texture.h"
#include "Shader.h"
#include <cstring>
#include <vector>

void initText2D(const char * texturePath);
void printText2D(const char * text, int x, int y, int size);
void cleanupText2D();