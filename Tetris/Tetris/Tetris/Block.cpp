#include "Block.h"

Block::Block( const BLOCKSHAPE& shape_in, const COLOR& color_in )
	:
	Shape(shape_in),
	Color(color_in)
{
}

Block::Block( const Vec2& pos_in, const BLOCKSHAPE& shape_in, const COLOR& color_in )
	:
	Pos(pos_in),
	Shape(shape_in),
	Color(color_in)
{
}

void Block::SetBlockShape( const BLOCKSHAPE& shape )
{
	this->Shape = shape;
}

void Block::SetBlockColor( const COLOR& color )
{
	this->Color = color;
}

BLOCKSHAPE Block::GetBlockShape() const
{
	return Shape;
}

COLOR Block::GetBlockColor() const
{
	return Color;
}
