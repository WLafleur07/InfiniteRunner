#include "Game.h"

void Game::OnEvent(SDL_Event* Event)
{
	switch (Event->type)
	{
	case SDL_QUIT:
		Running = false;
	case SDL_KEYDOWN:
		switch (Event->key.keysym.sym)
		{
		case SDLK_ESCAPE:
			Running = false;
			break;
		case SDLK_w:
			character.velocity.y = -7;
			break;

		default:
			break;
		}
	}
	switch (Event->type)
	{
	case SDL_KEYUP:
		switch (Event->key.keysym.sym)
		{
		case SDLK_w:
			
			break;

		default:
			break;
		}
	}
	
}


//==============================================================================
