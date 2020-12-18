#pragma once

#include <vector>
#include "Block.h"

class Polyomino
{
public:
	Polyomino();

private:
	std::vector<Block> Blocks[4];
};