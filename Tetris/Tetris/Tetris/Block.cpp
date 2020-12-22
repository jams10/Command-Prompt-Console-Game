#include "Block.h"

Block::Block( const int& X, const int& Y )
	:
	Pos( Vec2(X,Y) ),
	Type( BLOCKTYPE::FALLING )
{
}

Block::Block( const Vec2& Pos )
	:
	Pos(Pos),
	Type( BLOCKTYPE::FALLING )
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

void Block::SetBlockType( const BLOCKTYPE& Type )
{
	this->Type = Type;
}
