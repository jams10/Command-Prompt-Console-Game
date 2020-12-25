#pragma once

#include <random>
#include "Board.h"

class Game
{
public:
	Game();
	void Run();
	void Update();
	void ComposeFrame();
private:
	/*
		블록 생성시 색상을 랜덤으로 지정해주기 위해 랜덤 숫자를 생성.
		아래는 랜덤 숫자 생성과 관련된 개체들.
	*/
	std::random_device RandomDevice;
	std::mt19937 RandomGenerator;
	std::uniform_int_distribution<int> Distribution;
	Board BoardInstance;
};