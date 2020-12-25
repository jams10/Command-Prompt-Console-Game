#include "Game.h"

Game::Game()
	:
	RandomGenerator( std::mt19937( RandomDevice() ) ),
	// Distribution의 경우 색상 enum class의 요소 갯수와 맞추기
	Distribution( std::uniform_int_distribution<int>( 0, 5 ) ),
	BoardInstance( Board(10, 20) )
{
}

void Game::Run()
{
	ComposeFrame();
	while( true )
	{
		Update();
	}
}

void Game::Update()
{
	ComposeFrame();
}

void Game::ComposeFrame()
{
	BoardInstance.Print();
}
