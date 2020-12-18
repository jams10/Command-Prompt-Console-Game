#include "Polyomino.h"
#include "Tool.h"

Polyomino::Polyomino()
{
	int Number = Tool::GenerateRandomNumber();

	switch( Number )
	{
	case 1:
		// ㅡ
		
	case 2:
		// ㄴ
	case 3:
		// ┚
	case 4:
		// ㅁ
	case 5:
		// s
	case 6:
		// ㅗ
	case 7:
		// ㄹ
	default:
		break;
	}
}

/*
	1. 랜덤 값 생성 참고 : https://modoocode.com/304
*/
