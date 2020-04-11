#ifndef LEVEL_H
#define LEVEL_H

#include <SDL.h>
#include "mywindow.h"
#include <string>
#include "Character.h"

using namespace std;

class Level : public Character
{
public:

	bool loaded;
	string imagename;

	Level();
	Level(string s, int x, int y, int w, int h);
	int loadLevel(SDL_Renderer *prenderer);
	void display(SDL_Renderer *prenderer);

protected:
	SDL_Texture *texture;

};


#endif
