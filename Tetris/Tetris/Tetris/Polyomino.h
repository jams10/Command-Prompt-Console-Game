#pragma once

#include <vector>
#include "Vec2.h"
#include "Block.h"

#define OUT

class Polyomino
{
public:
	Polyomino(const int& StartX, const int& StartY);
	void PrintBlocksForTest() const;
	void GetBlocksPositions( Vec2* pArr ) const;
	void DownMino();
	void RotateMino();
private:
	int StartX;
	int StartY;
	Vec2 Positions[4];
	Block Blocks[4];
};