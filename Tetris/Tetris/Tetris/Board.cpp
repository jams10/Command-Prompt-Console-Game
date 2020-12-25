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

void Board::Print() const
{
	Tool::PrintOffSetY( 5 );
	
	for( int y = 0; y < Height; ++y )
	{
		Tool::PrintOffSetX( 5 );
		Tool::PrintByColor( BLOCKSHAPE::GRILLED_SQ, COLOR::WHITE );
		
		for( int x = 0; x < Width; ++x )
		{
			Tool::PrintByColor( Blocks[y][x].GetBlockShape(), Blocks[y][x].GetBlockColor() );
		}
		
		Tool::PrintByColor( BLOCKSHAPE::GRILLED_SQ, COLOR::WHITE );
		std::cout << std::endl;
	}
	
	Tool::PrintOffSetX( 5 );
	
	for( int x = 0; x < Width + 2; ++x )
	{
		Tool::PrintByColor( BLOCKSHAPE::GRILLED_SQ, COLOR::WHITE );
	}
}
