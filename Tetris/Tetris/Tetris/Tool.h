#pragma once

#include <Windows.h>
#include "Block.h"

class Tool
{
public:
	/*
		PrintOffSetX, Y : 가로, 세로에 빈 공간을 출력. 게임 화면 출력 위치를 설정할 때 사용함.
	*/
	static void PrintOffSetX( const int& size );
	static void PrintOffSetY( const int& size );
	/*
		PrintByColor 함수에서 콘솔 출력 색상을 설정하고 PrintShape 함수를 호출하여
		출력 색상이 적용된 상태에서 텍스트를 출력.
	*/
	static void PrintByColor( const BLOCKSHAPE& shape, const COLOR& color );
	static void PrintShape( const BLOCKSHAPE& shape );
};