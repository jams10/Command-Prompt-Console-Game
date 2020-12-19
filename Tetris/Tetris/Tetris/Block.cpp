#include "Block.h"

Block::Block( const int& X, const int& Y )
{
	Pos = Vec2( X, Y );
}

Block::Block( const Vec2& Pos )
	:
	Pos(Pos)
{
}

void Block::SetPosition( const int& X, const int& Y )
{
	Pos.x = X;
	Pos.y = Y;
}

Vec2 Block::GetPosition() const
{
	return Pos;
}
