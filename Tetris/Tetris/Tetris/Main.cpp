#include "Game.h"

int main()
{
	Game GameInstance;
	//GameInstance.Run();
	Board BoardInstance(10,20);

	GameInstance.GenerateBlocks( Vec2( BoardInstance.GetWidth() / 2 - 1, 0 ), 
	                             GameInstance.CurrentBlocks );

	BoardInstance.Print(GameInstance.CurrentBlocks);

	GameInstance.GenerateBlocks( Vec2( BoardInstance.GetWidth() / 2 - 1, 0 ), 
	                             GameInstance.CurrentBlocks );

	BoardInstance.Print(GameInstance.CurrentBlocks);

	return 0;
}

