#include "Game.h"

Game::Game()
	:
	RandomGenerator( std::mt19937( RandomDevice() ) ),
	// Distribution�� ��� ���� enum class�� ��� ������ ���߱�
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
