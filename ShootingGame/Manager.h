#pragma once
#include "Character/Player/Player.h"
#include "Character/Target/Target.h"

class Manager {
public:
	static Manager& instance() {
		static Manager *instance = new Manager();
		return *instance;
	}
	Player* getPlayer() {
		return mPlayer;
	}
	Target* getTarget() {
		return mTarget;
	}
	void setData(int d) {
		data = d;
	}
	void print() {
		std::cout << data;
	}
	~Manager() {
		delete mPlayer;
		delete mTarget;
	}
private:
	Manager() {
		mPlayer = new Player();
		mTarget = new Target();
	}
	int data;
	Player* mPlayer;
	Target* mTarget;
};