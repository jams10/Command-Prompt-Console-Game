#pragma once

#include <string>
#include "Vec2.h"

class Block
{
public:
	Block() = default;
	Block( const int& X, const int& Y );
	Block( const Vec2& Pos );
	void SetPosition( const int& X, const int& Y );
	Vec2 GetPosition() const;
private:
	Vec2 Pos;
	std::string Shape = "бс";
};