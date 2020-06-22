#pragma once
#include "Background.h"
#include "Character/Player/Player.h"
#include "Character/Target/Target.h"
#include "Character/Player/Aim.h"
#include "common/Gamewindow.h"

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
	Player mPlayer;
	Target mTarget;
};