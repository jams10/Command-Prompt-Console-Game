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
}

void Polyomino::PrintBlocksForTest() const
{
	for( int i = 0; i < 4; ++i )
	{
		std::cout << "X : " << Blocks[i].GetPosition().x << " Y :  " << Blocks[i].GetPosition().y;
		std::cout << std::endl;
	}
}

void Polyomino::GetBlocksPositions(Vec2* Positions) const
{
	// 매개변수로 배열을 받지 않고 이 함수 내에서 배열을 생성 후 리턴 할 경우에
	// 함수의 스택과 함수를 호출한 곳의 스택이 다르므로, 리턴을 받을 때 배열이 사라짐.
	for( int i = 0; i < 4; ++i )
	{
		Positions[i] = Blocks[i].GetPosition();
	}
}

/*
	1. 랜덤 값 생성 참고 : https://modoocode.com/304
*/
