#include <iostream>
#include "Polyomino.h"
#include "Tool.h"

Polyomino::Polyomino( const int& StartX, const int& StartY )
	:
	StartX(StartX),
	StartY(StartY)
{
	int Number = Tool::GenerateRandomNumber();

	switch( Number )
	{
	case 1:
		// ㅡ
		Blocks[0] = Block( Vec2( StartX, StartY) );
		Blocks[1] = Block( Vec2( StartX + 1, StartY) );
		Blocks[2] = Block( Vec2( StartX + 2, StartY) );
		Blocks[3] = Block( Vec2( StartX + 3, StartY) );
		break;
	case 2:
		// ㄴ
		Blocks[0] = Block( Vec2( StartX, StartY ) );
		Blocks[1] = Block( Vec2( StartX, StartY + 1 ) );
		Blocks[2] = Block( Vec2( StartX, StartY + 2 ) );
		Blocks[3] = Block( Vec2( StartX + 1, StartY + 2 ) );
		break;
	case 3:
		// ┚
		Blocks[0] = Block( Vec2( StartX + 1, StartY ) );
		Blocks[1] = Block( Vec2( StartX + 1, StartY + 1 ) );
		Blocks[2] = Block( Vec2( StartX + 1, StartY + 2 ) );
		Blocks[3] = Block( Vec2( StartX, StartY + 2 ) );
		break;
	case 4:
		// ㅁ
		Blocks[0] = Block( Vec2( StartX, StartY ) );
		Blocks[1] = Block( Vec2( StartX + 1, StartY ) );
		Blocks[2] = Block( Vec2( StartX, StartY + 1 ) );
		Blocks[3] = Block( Vec2( StartX + 1, StartY + 1 ) );
		break;
	case 5:
		// s
		Blocks[0] = Block( Vec2( StartX + 1, StartY ) );
		Blocks[1] = Block( Vec2( StartX + 2, StartY ) );
		Blocks[2] = Block( Vec2( StartX + 1, StartY + 1 ) );
		Blocks[3] = Block( Vec2( StartX, StartY + 1 ) );
		break;
	case 6:
		// ㅗ
		Blocks[0] = Block( Vec2( StartX + 1, StartY ) );
		Blocks[1] = Block( Vec2( StartX, StartY + 1 ) );
		Blocks[2] = Block( Vec2( StartX + 1, StartY + 1 ) );
		Blocks[3] = Block( Vec2( StartX + 2, StartY + 1 ) );
		break;
	case 7:
		// ㄹ
		Blocks[0] = Block( Vec2( StartX, StartY ) );
		Blocks[1] = Block( Vec2( StartX + 1, StartY ) );
		Blocks[2] = Block( Vec2( StartX + 1, StartY + 1 ) );
		Blocks[3] = Block( Vec2( StartX + 2, StartY + 1 ) );
		break;
	default:
		break;
	}

	for( int i = 0; i < 4; ++i )
	{
		Positions[i] = Blocks[i].GetPosition();
	}
}

void Polyomino::PrintBlocksForTest() const
{
	for( int i = 0; i < 4; ++i )
	{
		std::cout << "X : " << Blocks[i].GetPosition().x << " Y :  " << Blocks[i].GetPosition().y;
		std::cout << std::endl;
	}
}

void Polyomino::GetBlocksPositions(Vec2* pArr) const
{
	for( int i = 0; i < 4; ++i )
	{
		pArr[i] = Positions[i];
	}
}

void Polyomino::DownMino()
{
	for( int i = 0; i < 4; ++i )
	{
		--Positions[i].y;
	}
}

/*
	1. 랜덤 값 생성 참고 : https://modoocode.com/304
*/
