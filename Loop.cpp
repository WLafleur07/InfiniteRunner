//==============================================================================
#include "Game.h"

using namespace std;


void Game::MoveSprites() {

	for (int i = 0; i <= MAX_SCROLLBACK; i++)
	{
		background[i].move();
	}

	character.move();
	obstacle[0].move();
}


//==============================================================================
void Game::Loop()
{
    MoveSprites();
}

//==============================================================================
