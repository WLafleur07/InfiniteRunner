//==============================================================================
#include "Game.h"

//==============================================================================
void Game::Render()
{

	SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
	SDL_RenderClear(renderer);

	level[0].display(renderer);
	level[1].display(renderer);
	level[2].display(renderer);

	for (int i = 0; i <= MAX_SCROLLBACK - 1; i++)
	{
		background[i].display(renderer);
	}

	static Uint32 cnt = 0;
	if (cnt % 2 == 0)
	{
		character.play(renderer, &character.position, true);
	}
	else
	{
		character.play(renderer, &character.position, false);
	}
	cnt++;

	obstacle[0].display(renderer);
	background[7].display(renderer);

    /* Update the screen! */
    SDL_RenderPresent(renderer);
    //SDL_Delay(10);
    SDL_Delay(time_left());
    next_time += TICK_INTERVAL;

}

//==============================================================================
