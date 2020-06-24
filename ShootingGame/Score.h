#pragma once
#include <string>
using namespace std;

class Score {
public:
	static Score& instance() {
		static Score *instance = new Score();
		return *instance;
	}
	
	// param
	//   mode:"set"Å®mScore = point,"add"Å®mScore += point
	void score(int point, string mode) {
		if (mode == "set") { mScore = point; }
		if (mode == "add") { mScore += point; }
	}

	int getScore() {
		return mScore;
	}
private:
	Score() : mScore(0){}
	int mScore;
};