#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include <SDL_mixer.h>
#include "iostream"
#include "mywindow.h"
#include "Character.h"
#include "Level.h"
#include "Obstacle.h"
#include "Background.h"

#define TICK_INTERVAL   10
#define NUM_SPRITES		10
#define MAX_SPEED       1
#define MAX_LEVEL		3
#define MAX_SCROLLBACK	8
#define MAX_OBSTACLES	10

class Game
{
private:
    bool Running;

    Uint32 next_time;
    SDL_Window *window;
    SDL_Renderer *renderer;
	Character character;
	Level level[MAX_LEVEL];
	Background background[MAX_SCROLLBACK];
	Obstacle obstacle[MAX_OBSTACLES];
	Mix_Music *music = NULL;

	

public:
	
	Game();
    Uint32 time_left(void);
    int OnExecute();
	bool checkCollision(SDL_Rect A, SDL_Rect B);
	
public:
    bool Init();

    void OnEvent(SDL_Event* Event);

    void Loop();

    void Render();
    void MoveSprites();

    void Cleanup();
};

#endif
