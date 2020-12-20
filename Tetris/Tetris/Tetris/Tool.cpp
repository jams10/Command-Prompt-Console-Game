#include <iostream>
#include <random>
#include "Tool.h"

int Tool::GenerateRandomNumber()
{
	// 시드 값을 얻기 위해 랜덤 디바이스 생성.
	std::random_device RandomDevice;

	// 앞서 생성한 랜덤 디바이스를 통해 난수 엔진 초기화.
	std::mt19937 Generator( RandomDevice() );

	// 어디에서 수들을 뽑아낼지 알려주는 분포를 정의. (균등 분포)
	std::uniform_int_distribution<int> Distribution( 1, 7 );

	// 균등 분포 개체에 사용할 난수 엔진을 전달하여 균등 분포에서 무작위로 샘플을 뽑음.
	return Distribution( Generator );
}

void Tool::PrintOffsetX( const int& OffsetX )
{
	for( int x = 0; x < OffsetX; ++x )
	{
		std::cout << " ";
	}
}

void Tool::PrintOffsetY( const int& OffsetY )
{
	for( int y = 0; y < OffsetY; ++y )
	{
		std::cout << std::endl;
	}
}
