#pragma once

#include <vector>
#include "Block.h"
#include "Tool.h"

class Board
{
public:
	Board( const int& width, const int& height );
	void Print( const std::vector<Block> currentblocks ) const;
	int GetWidth() const;
	int GetHeight() const;
private:
	int Width;
	int Height;
	// 2차원 Block vector
	std::vector<std::vector<Block>> Blocks;
};