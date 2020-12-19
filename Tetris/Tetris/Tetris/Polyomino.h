#pragma once

#include <vector>
#include "Vec2.h"
#include "Block.h"

class Polyomino
{
public:
	Polyomino(const int& StartX, const int& StartY);
	void PrintBlocksForTest() const;
	void GetBlocksPositions(Vec2* Positions) const;
private:
	int StartX;
	int StartY;
	Block Blocks[4];
};