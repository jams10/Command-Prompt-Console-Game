#pragma once

#include "Vec2.h"

enum class BLOCKTYPE
{
	FALLING,
	STACKED
};

class Block
{
public:
	Block() = default;
	Block( const int& X, const int& Y );
	Block( const Vec2& Pos );
	void SetPosition( const int& X, const int& Y );
	Vec2 GetPosition() const;
	void SetBlockType(const BLOCKTYPE& Type );
private:
	Vec2 Pos;
	BLOCKTYPE Type;
};