#pragma once
#include "Background.h"

enum Sequence {
	SEQ_TITLE,
	SEQ_READY,
	SEQ_PLAY,
	SEQ_END,

	SEQ_NONE,
};
class Game {
public:
	Game();
	~Game();
	void update();
private:
	Sequence mSeq;
	Background mBackground;
};