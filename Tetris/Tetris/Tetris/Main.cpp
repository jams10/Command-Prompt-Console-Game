#include <iostream>
#include "Board.h"
#include "Polyomino.h"

int main()
{
	Polyomino P( 0, 0 );
	Board B;

	P.PrintBlocksForTest();
	B.AddMino( P );
	B.Show();

	Polyomino P1( 0, 0 );
	P1.PrintBlocksForTest();
	B.AddMino( P1 );
	B.Show();

	Polyomino P2( 0, 0 );
	P2.PrintBlocksForTest();
	B.AddMino( P2 );
	B.Show();

	return 0;
}