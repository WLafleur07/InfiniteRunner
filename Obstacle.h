#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL.h>
#include "mywindow.h"
#include <string>
#include <iostream>

using namespace std;

class Obstacle
{
public:
	bool loaded;
	SDL_Rect position;
	SDL_Rect velocity;
	string imagename;

	Obstacle();
	Obstacle(string s, int x, int y, int vx, int vy);

	int loadPlayer(SDL_Renderer *prenderer);
	void display(SDL_Renderer *prenderer);
	void move();

protected:
	SDL_Texture *texture;
};


#endif
