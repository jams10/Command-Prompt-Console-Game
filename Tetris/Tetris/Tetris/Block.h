#pragma once

#include "Vec2.h"

enum class BLOCKSHAPE
{
	EMPTY,			// "  "
	EMPTY_SQ,		// "бр"
	FULLFILLED_SQ,  // "бс"
	DOUBLE_SQ,      // "в├"
	GRILLED_SQ      // "в╠"
};

enum class COLOR
{
	RED,
	GREEN,
	BLUE,
	WHITE
};

class Block
{
public:
	Block( const BLOCKSHAPE& shape_in, const COLOR& color_in );
	Block( const Vec2& pos_in, const BLOCKSHAPE& shape_in, const COLOR& color_in );
	void SetBlockShape( const BLOCKSHAPE& shape );
	void SetBlockColor( const COLOR& color );
	BLOCKSHAPE GetBlockShape() const;
	COLOR GetBlockColor() const;
private:
	Vec2 Pos;
	BLOCKSHAPE Shape;
	COLOR Color;
};