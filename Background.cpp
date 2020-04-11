#include "Background.h"

Background::Background(){
    
}

Background::~Background(){

}

void Background::display(SDL_Renderer *prenderer)
{
    SDL_RenderCopy(prenderer, texture, &src, &destscr);
}


int Background::loadPlayer(SDL_Renderer *prenderer)
{
    int retval;

    retval = Obstacle::loadPlayer(prenderer);
    destscr.x = 0;
    destscr.y = 0;
    destscr.h = window_h;
    destscr.w = window_w;
    velocity.x = 1;
    velocity.y = 0;
    return (retval);
}


//function to make the background texture scroll
void Background::move()
{
	src.x += velocity.x;
	src.y += velocity.y;
	if (src.y >= position.h - window_h)
	{
		velocity.y = -velocity.y;
		src.y += velocity.y;

	}
	if (src.y < 0)
	{
		velocity.y = -velocity.y;
		src.y += velocity.y;
	}
	if (src.x >= position.w - window_w)   // Assumes that image is greater than window width..
	{
		src.x = 0;
	}
	if (src.x < 0)
	{
		velocity.x = -velocity.x;
		src.x += velocity.x;
	}
}
