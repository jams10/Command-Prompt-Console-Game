#pragma once

#include "Vec2.h"

enum class BLOCKSHAPE
{
	EMPTY_SQ,
	FULLFILLED_SQ,
	DOUBLE_SQ
};

enum class COLOR
{
	RED,
	GREEN,
	BLUE
};

class Block
{
public:
	Block( const Vec2& pos, const BLOCKSHAPE& shape, const COLOR& color );
	void SetBlockShape( const BLOCKSHAPE& shape );
	void SetBlockColor( const COLOR& color );
private:
	Vec2 pos;
	BLOCKSHAPE shape;
	COLOR color;
};