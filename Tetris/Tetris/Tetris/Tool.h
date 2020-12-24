#pragma once

#include <Windows.h>
#include "Block.h"

class Tool
{
public:
	/*
		PrintOffSetX, Y : ����, ���ο� �� ������ ���. ���� ȭ�� ��� ��ġ�� ������ �� �����.
	*/
	static void PrintOffSetX( const int& size );
	static void PrintOffSetY( const int& size );
	/*
		PrintByColor �Լ����� �ܼ� ��� ������ �����ϰ� PrintShape �Լ��� ȣ���Ͽ�
		��� ������ ����� ���¿��� �ؽ�Ʈ�� ���.
	*/
	static void PrintByColor( const BLOCKSHAPE& shape, const COLOR& color );
	static void PrintShape( const BLOCKSHAPE& shape );
};