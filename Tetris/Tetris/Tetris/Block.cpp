#include "Block.h"

Block::Block( const Vec2& pos_in, const BLOCKSHAPE& shape_in, const COLOR& color_in )
	:
	pos(pos_in),
	shape(shape_in),
	color(color_in)
{
}

void Block::SetBlockShape( const BLOCKSHAPE& shape )
{
	this->shape = shape;
}

void Block::SetBlockColor( const COLOR& color )
{
}
