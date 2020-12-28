#include <chrono>
#include <iostream>
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
	GenerateBlocks( Vec2( BoardInstance.GetWidth() / 2, 0 ), CurrentBlocks );
	ComposeFrame();
}

void Game::ComposeFrame()
{
	BoardInstance.Print( CurrentBlocks );
}

void Game::GenerateBlocks( const Vec2& pos, std::vector<Block>& currentblocks )
{
	//std::cout << "pos.x : " << pos.x << " pos. y : " << pos.y << std::endl;
	int RandomNumber = 0;

	// 1. ���� ������ ���� ���� �Ҵ�.
	std::uniform_int_distribution<int> ColorDist(0,2);
	RandomNumber = ColorDist( RandomGenerator );

	std::cout << "rnd number for color : " << RandomNumber << std::endl;

	// ������ ���� ��� ���� ����.
	for(Block& blocks : currentblocks)
	{
		blocks.SetBlockColor( COLOR(RandomNumber) );
	}

	// 2. ��� ������ ���� ���� �Ҵ�.
	std::uniform_int_distribution<int> ShapeDist(0,6);
	RandomNumber = ShapeDist( RandomGenerator );

	//std::cout << "rnd number for shape : " << RandomNumber << std::endl;

	// ������ ���� ��� ���� ��� ����.
	currentblocks[0].SetBlockPosition( Vec2( pos.x, pos.y) );
	switch( RandomNumber )
	{
	case 0: // �� ���
		currentblocks[1].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		currentblocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 2) );
		currentblocks[3].SetBlockPosition( Vec2( pos.x + 1, pos.y + 2) );
		break;
	case 1: // �� ���
		currentblocks[1].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		currentblocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 2) );
		currentblocks[3].SetBlockPosition( Vec2( pos.x - 1, pos.y + 2) );
		break;
	case 2: // s ���
		currentblocks[1].SetBlockPosition( Vec2( pos.x + 1, pos.y) );
		currentblocks[2].SetBlockPosition( Vec2( pos.x - 1, pos.y + 1) );
		currentblocks[3].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		break;
	case 3: // 2 ���
		currentblocks[1].SetBlockPosition( Vec2( pos.x - 1, pos.y) );
		currentblocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		currentblocks[3].SetBlockPosition( Vec2( pos.x + 1, pos.y + 1) );
		break;
	case 4: // �� ���
		currentblocks[1].SetBlockPosition( Vec2( pos.x - 1, pos.y + 1) );
		currentblocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		currentblocks[3].SetBlockPosition( Vec2( pos.x + 1, pos.y + 1) );
		break;
	case 5: // �� ���
		currentblocks[1].SetBlockPosition( Vec2( pos.x + 1, pos.y) );
		currentblocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		currentblocks[3].SetBlockPosition( Vec2( pos.x + 1, pos.y + 1) );
		break;
	case 6: // l ���
		currentblocks[1].SetBlockPosition( Vec2( pos.x, pos.y + 1) );
		currentblocks[2].SetBlockPosition( Vec2( pos.x, pos.y + 2) );
		currentblocks[3].SetBlockPosition( Vec2( pos.x, pos.y + 3) );
		break;
	default:
		break;
	}
}
