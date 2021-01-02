#include <iostream>
#include "Board.h"

using namespace std;

Board::Board( const int& width_in, const int& height_in )
	:
	Width(width_in),
	Height(height_in)
{
	Blocks.resize( Width * Height, Block(BLOCKSHAPE::EMPTY, COLOR::WHITE) );
}

void Board::Print( const std::vector<Block> currentblocks ) const
{
	Tool::PrintOffSetY( 5 );
	
	for( int y = 0; y < Height; ++y )
	{
		Tool::PrintOffSetX( 7 );
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
				Tool::PrintByColor( Blocks[y * Width + x].GetBlockShape(), Blocks[y * Width + x].GetBlockColor() );
			}
		}
		
		// 오른쪽 바깥 프레임 출력
		Tool::PrintByColor( BLOCKSHAPE::GRILLED_SQ, COLOR::WHITE );
		std::cout << std::endl;
	}
	
	Tool::PrintOffSetX( 7 );
	
	// 아래쪽 바깥 프레임 출력
	for( int x = 0; x < Width + 2; ++x )
	{
		Tool::PrintByColor( BLOCKSHAPE::GRILLED_SQ, COLOR::WHITE );
	}
}

void Board::AddBlock( const Block& block )
{
	Vec2 blockPos = block.GetBlockPosition();
	Blocks[blockPos.y * Width + blockPos.x] = block;
}

int Board::GetWidth() const
{
	return Width;
}

int Board::GetHeight() const
{
	return Height;
}