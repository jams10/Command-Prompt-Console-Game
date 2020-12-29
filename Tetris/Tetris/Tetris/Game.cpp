#include <chrono>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <algorithm>
#include "Game.h"

Game::Game()
	:
	RandomGenerator( std::chrono::high_resolution_clock::now().time_since_epoch().count() ),
	BoardInstance( Board(10, 20) ),
	CurrentBlocks( std::vector<Block>( 4, Block( BLOCKSHAPE::DOUBLE_SQ, COLOR::WHITE ) ) )
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
	system("cls");

	char input = ' ';

	if(!isFalling)
	{
		GenerateBlocks( Vec2( BoardInstance.GetWidth() / 2 - 1, 0 ) );
		isFalling = true;
	}

	input = _getch();

	if( input == 'r' )
	{
		RotateBlocks();
	}

	GoDownBlocks();

	if( FloorTest() )
	{
		isFalling = false;
	}

	ComposeFrame();

	Sleep(500);
}

void Game::ComposeFrame()
{
	BoardInstance.Print( CurrentBlocks );
}

void Game::GenerateBlocks( const Vec2& pos )
{
	//std::cout << "pos.x : " << pos.x << " pos. y : " << pos.y << std::endl;
	int RandomNumber = 0;

	// 1. 색상 지정을 위한 난수 할당.
	std::uniform_int_distribution<int> ColorDist(0,2);
	RandomNumber = ColorDist( RandomGenerator );

	//std::cout << "rnd number for color : " << RandomNumber << std::endl;

	// 난수에 따른 블록 색상 변경.
	for( Block& blocks : CurrentBlocks )
	{
		blocks.SetBlockColor( COLOR(RandomNumber) );
	}

	// 2. 모양 지정을 위한 난수 할당.
	std::uniform_int_distribution<int> ShapeDist(0,6);
	RandomNumber = ShapeDist( RandomGenerator );

	//std::cout << "rnd number for shape : " << RandomNumber << std::endl;

	// 난수에 따른 블록 구조 모양 변경.
	CurrentBlocks[0].SetBlockPosition( Vec2( pos.x, pos.y) );
	switch( RandomNumber )
	{
	case 0: // ㄴ 모양
		CurrentBlocks[1].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		CurrentBlocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 2) );
		CurrentBlocks[3].SetBlockPosition( Vec2( pos.x + 1, pos.y + 2) );
		break;
	case 1: // 」 모양
		CurrentBlocks[1].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		CurrentBlocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 2) );
		CurrentBlocks[3].SetBlockPosition( Vec2( pos.x - 1, pos.y + 2) );
		break;
	case 2: // s 모양
		CurrentBlocks[1].SetBlockPosition( Vec2( pos.x + 1, pos.y) );
		CurrentBlocks[2].SetBlockPosition( Vec2( pos.x - 1, pos.y + 1) );
		CurrentBlocks[3].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		break;
	case 3: // 2 모양
		CurrentBlocks[1].SetBlockPosition( Vec2( pos.x - 1, pos.y) );
		CurrentBlocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		CurrentBlocks[3].SetBlockPosition( Vec2( pos.x + 1, pos.y + 1) );
		break;
	case 4: // ㅗ 모양
		CurrentBlocks[1].SetBlockPosition( Vec2( pos.x - 1, pos.y + 1) );
		CurrentBlocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		CurrentBlocks[3].SetBlockPosition( Vec2( pos.x + 1, pos.y + 1) );
		break;
	case 5: // ㅁ 모양
		CurrentBlocks[1].SetBlockPosition( Vec2( pos.x + 1, pos.y) );
		CurrentBlocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		CurrentBlocks[3].SetBlockPosition( Vec2( pos.x + 1, pos.y + 1) );
		break;
	case 6: // l 모양
		CurrentBlocks[1].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		CurrentBlocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 2) );
		CurrentBlocks[3].SetBlockPosition( Vec2( pos.x, pos.y + 3) );
		break;
	default:
		break;
	}
}

void Game::GoDownBlocks()
{
	for( Block& block : CurrentBlocks )
	{
		Vec2 pos = block.GetBlockPosition();
		//std::cout << "BEFORE / pos.x : " << pos.x << " pos.y : " << pos.y << std::endl;
		block.SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		//pos = block.GetBlockPosition();
		//std::cout << "AFTER / pos.x : " << pos.x << " pos.y : " << pos.y << std::endl;
	}
}

void Game::GoLeftBlocks()
{
	for( Block& block : CurrentBlocks )
	{
		Vec2 pos = block.GetBlockPosition();
		block.SetBlockPosition( Vec2( pos.x - 1, pos.y ) );
	}
}

void Game::GoRightBlocks()
{
	for( Block& block : CurrentBlocks )
	{
		Vec2 pos = block.GetBlockPosition();
		block.SetBlockPosition( Vec2( pos.x + 1, pos.y ) );
	}
}

void Game::RotateBlocks()
{
	int max = std::max( CurrentBlocks[0].GetBlockPosition().y, CurrentBlocks[3].GetBlockPosition().y );

	for( Block& block : CurrentBlocks )
	{
		Vec2 pos = block.GetBlockPosition();
		std::cout << "Before / pos.x : " << pos.x << " pos.y : " << pos.y << std::endl;
		block.SetBlockPosition( Vec2( pos.y, pos.x ) );
		pos = block.GetBlockPosition();
		std::cout << "After / pos.x : " << pos.x << " pos.y : " << pos.y << std::endl;
	}
}

bool Game::FloorTest() const
{
	int blockfloor = std::max( CurrentBlocks[0].GetBlockPosition().y, CurrentBlocks[3].GetBlockPosition().y );

	return blockfloor >= BoardInstance.GetHeight() - 1;
}

// 게임 바깥 프레임에 닿을 경우, 이미 쌓여 있는 블록에 닿을 경우 케이스 처리



