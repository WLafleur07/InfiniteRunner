#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Obstacle.h"

class Background : public Obstacle
{
    public:
		Background();
        virtual ~Background();
        SDL_Rect destscr;
        SDL_Rect src;   // Where to get Image (Part of Big Image
        void display(SDL_Renderer *prenderer);
        int loadPlayer(SDL_Renderer *prenderer);

		//function to make the background texture scroll
        void setScroll(int sx, int sy, int sw, int sh)
        {
            src.x = sx;
            src.y = sy;
            src.w = sw,
            src.h = sh;
        }
        void move();
    protected:
    private:
};

#endif
