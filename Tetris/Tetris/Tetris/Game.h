#pragma once

/*
	Visual studio code & MinGW-w64 �� �ۼ� �� ������ ���� ��, mt19937 ���� ������ ��� �� ���α׷�
	���� ���� ���� ���� ��� ���� ������. 
	���� : http://www.cpp.re/forum/beginner/250575/
	If you are using some port of the GCC compiler for Microsoft OSs, like MingW or MinGW-w64 in W10 or W7, as far as I know std::random_device is not guaranteed to work.
    You can initialize std::mt19937 by std::chrono::high_resolution_clock.

	
*/

#include <random>
#include <vector>
#include "Board.h"

class Game
{
public:
	Game();
	void Run();
	void Update();
	void ComposeFrame();
	void GenerateBlocks( const Vec2& pos, std::vector<Block>& currentblocks );
private:
	/*
		��� ������ ������ �������� �������ֱ� ���� ���� ���ڸ� ����.
		�Ʒ��� ���� ���� ������ ���õ� ��ü��.
	*/
	std::mt19937 RandomGenerator;
	Board BoardInstance;
public:
	std::vector<Block> CurrentBlocks;
};