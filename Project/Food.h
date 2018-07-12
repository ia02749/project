#ifndef FOOD_H
#define FOOD_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"

class Food
{
    public:
        Food();
        bool HasIntersect(int, int);
        void MoveWithMouse(int a, int b);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);

        //SDL_Rect khana;

    protected:
        SDL_Rect khana;
        Point position;
        int width;
        int height;
        LTexture* spriteSheetTexture;

    private:
        //SDL_Rect khana;
};

#endif // FOOD_H
