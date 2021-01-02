#pragma once

#include <vector>
#include "Block.h"
#include "Tool.h"

class Board
{
public:
	Board( const int& width, const int& height );
	void Print( const std::vector<Block> currentblocks ) const;
	void AddBlock( const Block& block );
	int GetWidth() const;
	int GetHeight() const;
private:
	int Width;
	int Height;
	// 2D -> 1D Vector
	std::vector<Block> Blocks;
};