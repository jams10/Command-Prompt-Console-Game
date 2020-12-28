#pragma once

/*
	Visual studio code & MinGW-w64 로 작성 및 컴파일 했을 때, mt19937 난수 생성의 경우 매 프로그램
	실행 마다 같은 난수 결과 값을 도출함. 
	참고 : http://www.cpp.re/forum/beginner/250575/
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
		블록 생성시 색상을 랜덤으로 지정해주기 위해 랜덤 숫자를 생성.
		아래는 랜덤 숫자 생성과 관련된 개체들.
	*/
	std::mt19937 RandomGenerator;
	Board BoardInstance;
public:
	std::vector<Block> CurrentBlocks;
};