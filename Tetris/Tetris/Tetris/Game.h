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
		��� ������ ������ �������� �������ֱ� ���� ���� ���ڸ� ����.
		�Ʒ��� ���� ���� ������ ���õ� ��ü��.
	*/
	std::random_device RandomDevice;
	std::mt19937 RandomGenerator;
	std::uniform_int_distribution<int> Distribution;
	Board BoardInstance;
};