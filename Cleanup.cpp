//==============================================================================
#include "Game.h"

//==============================================================================
void Game::Cleanup() {
    //SDL_FreeSurface(Surf_Display);

	Mix_FreeMusic(music);
	music = NULL;
	Mix_Quit();
    SDL_Quit();
}

//==============================================================================
