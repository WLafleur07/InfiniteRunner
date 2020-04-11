#include "Game.h"
#include <stdlib.h>
#include <time.h>

bool Game::Init()
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) < 0)
	{
		return false;
	}
	window = SDL_CreateWindow("Platformer",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
		return false;
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
		return false;

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	music = Mix_LoadMUS("Assets/03-Before-the-Dawn.wav");
	Mix_VolumeMusic(SDL_MIX_MAXVOLUME / 6);
	//Mix_PlayMusic(music, -1);

	level[0] = Level("Assets/Layer_0010_1.bmp", 0, 0, 928, 793);
	level[0].loadLevel(renderer);
	level[1] = Level("Assets/Layer_0009_2.bmp", 0, -296, 928, 793);
	level[1].loadLevel(renderer);
	level[2] = Level("Assets/Layer_0008_3.bmp", 0, -330, 928, 793);
	level[2].loadLevel(renderer);


	background[0].imagename = "Assets/Layer_0007_Lights.bmp";
	background[0].setScroll(0, 296, window_w, window_h);
	background[0].loadPlayer(renderer);

	background[1].imagename = "Assets/Layer_0006_4.bmp";
	background[1].setScroll(0, 330, window_w, window_h);
	background[1].loadPlayer(renderer);
	background[1].velocity.x = -2;

	background[2].imagename = "Assets/Layer_0005_5.bmp";
	background[2].setScroll(0, 330, window_w, window_h);
	background[2].loadPlayer(renderer);
	background[2].velocity.x = -2;

	background[3].imagename = "Assets/Layer_0004_Lights.bmp";
	background[3].setScroll(0, 330, window_w, window_h);
	background[3].loadPlayer(renderer);
	background[3].velocity.x = -3;

	background[4].imagename = "Assets/Layer_0003_6.bmp";
	background[4].setScroll(0, 330, window_w, window_h);
	background[4].loadPlayer(renderer);
	background[4].velocity.x = -4;

	background[5].imagename = "Assets/Layer_0002_7.bmp";
	background[5].setScroll(0, 330, window_w, window_h);
	background[5].loadPlayer(renderer);
	background[5].velocity.x = -4;

	background[6].imagename = "Assets/Layer_0001_8.bmp";
	background[6].setScroll(0, 330, window_w, window_h);
	background[6].loadPlayer(renderer);
	background[6].velocity.x = -4;

	background[7].imagename = "Assets/Layer_0000_9.bmp";
	background[7].setScroll(0, 330, window_w, window_h);
	background[7].loadPlayer(renderer);
	background[7].velocity.x = -4;

	obstacle[0] = Obstacle("Assets/CactusG.bmp", window_w / 2, 330, 0, 0);
	obstacle[0].loadPlayer(renderer);
	obstacle[0].velocity.x = -10;
	obstacle[0].position.h = obstacle[0].position.h / 1.2;
	obstacle[0].position.w = obstacle[0].position.w / 1.5;
	
	character.setSpriteSheet("Assets/characterRun.bmp");
	character.configSpriteSheet(12, 0, 0, 66, 48, 12, 1, 0);
	character.characterPosDimen(character.images[0].w * 1.5, character.images[0].h * 1.5, 32, 330);
	character.loadSpriteSheet(renderer);
	//character.velocity.y = character.gravity;


    return true;
}




//==============================================================================
