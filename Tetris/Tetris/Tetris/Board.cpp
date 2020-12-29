#include <iostream>
#include "Board.h"

using namespace std;

Board::Board( const int& width_in, const int& height_in )
	:
	Width(width_in),
	Height(height_in)
{
	// BLOCKSHAPE : EMPTY, COLOR : WHITE를 인자로 하는 Block 개체로 height * width 만큼 벡터를 채움.
	Blocks.resize( Height, std::vector<Block>( Width, Block( BLOCKSHAPE::EMPTY, COLOR::WHITE ) ) );
}

void Board::Print( const std::vector<Block> currentblocks ) const
{
	Tool::PrintOffSetY( 5 );
	
	for( int y = 0; y < Height; ++y )
	{
		Tool::PrintOffSetX( 5 );
		// 왼쪽 바깥 프레임 출력
		Tool::PrintByColor( BLOCKSHAPE::GRILLED_SQ, COLOR::WHITE );
		
		// 프레임 안쪽 블록들 출력
		for( int x = 0; x < Width; ++x )
		{
			bool checkflag = false;
			for( const Block& block : currentblocks )
			{
				Vec2 pos = block.GetBlockPosition();
				if( pos.x == x && pos.y == y)
				{
					checkflag = true;
					Tool::PrintByColor( block.GetBlockShape(), block.GetBlockColor() );
				}
			}
			if( !checkflag )
			{
				Tool::PrintByColor( Blocks[y][x].GetBlockShape(), Blocks[y][x].GetBlockColor() );
			}
		}
		
		// 오른쪽 바깥 프레임 출력
		Tool::PrintByColor( BLOCKSHAPE::GRILLED_SQ, COLOR::WHITE );
		std::cout << std::endl;
	}
	
	Tool::PrintOffSetX( 5 );
	
	// 아래쪽 바깥 프레임 출력
	for( int x = 0; x < Width + 2; ++x )
	{
		Tool::PrintByColor( BLOCKSHAPE::GRILLED_SQ, COLOR::WHITE );
	}
}

int Board::GetWidth() const
{
	return Width;
}

int Board::GetHeight() const
{
	return Height;
}