#include "Game.h"

int main()
{
	Game GameInstance;
	//GameInstance.Run();

	
	GameInstance.GenerateBlocks( Vec2(4, 0) );

	GameInstance.ComposeFrame();

	GameInstance.RotateBlocks();

	GameInstance.ComposeFrame();

	/*
	for(int i = 0; i < 4; ++i)
	{
		GameInstance.RotateBlocks();

		GameInstance.ComposeFrame();

		GameInstance.GoDownBlocks();
	}
	*/
	return 0;
}

