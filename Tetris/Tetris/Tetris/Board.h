#pragma once

#include <vector>
#include "Block.h"
#include "Tool.h"

class Board
{
public:
	Board( const int& width, const int& height );
	void Print() const;
private:
	int Width;
	int Height;
	// 2Â÷¿ø Block vector
	std::vector<std::vector<Block>> Blocks;
};