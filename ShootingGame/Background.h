#pragma once
#include "common/Shader.h"
#include "GameObject.h"
#include <vector>
#include <array>
#include "common/Model.h"
class Background:GameObject{
public:
	Background();
	~Background();

	void update();
private:
};