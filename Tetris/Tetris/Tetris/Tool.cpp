#include <iostream>
#include "Tool.h"

void Tool::PrintOffSetX( const int& size )
{
	for( int x = 0; x < size; ++x )
	{
		std::cout << " ";
	}
}

void Tool::PrintOffSetY( const int& size )
{
	for( int y = 0; y < size; ++y )
	{
		std::cout << std::endl;
	}
}

void Tool::PrintByColor( const BLOCKSHAPE& shape, const COLOR& color )
{
	switch( color )
	{
	case COLOR::RED:
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_RED );
		break;
	case COLOR::GREEN:
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN );
		break;
	case COLOR::BLUE:
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_BLUE );
		break;
	case COLOR::YELLOW:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		break;
	case COLOR::PURPLE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	default:
		break;
	}
	// 각 case에서 해당하는 색상으로 콘솔 텍스트 출력 색상을 변경해주고, 모양을 출력함.
	// 그 후, 다시 출력 색상을 기본 색상인 흰색으로 바꾸어줌.
	PrintShape( shape );
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),
			FOREGROUND_RED | FOREGROUND_BLUE |
			FOREGROUND_GREEN | FOREGROUND_INTENSITY );
}

void Tool::PrintShape( const BLOCKSHAPE& shape )
{
	switch( shape )
	{
	case BLOCKSHAPE::EMPTY:
		std::cout << "  ";
		break;
	case BLOCKSHAPE::EMPTY_SQ:
		std::cout << "□";
		break;
	case BLOCKSHAPE::FULLFILLED_SQ:
		std::cout << "■";
		break;
	case BLOCKSHAPE::DOUBLE_SQ:
		std::cout << "▣";
		break;
	case BLOCKSHAPE::GRILLED_SQ:
		std::cout << "▩";
		break;
	default:
		break;
	}
}
