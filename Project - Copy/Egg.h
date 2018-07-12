#ifndef EGG_H
#define EGG_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"
#include "Food.h"

class Egg : public Food
{
    public:
        Egg(LTexture*, float, float);
        //void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
//        Point position;
//        int width;
//        int height;
    protected:

    private:
        //SDL_Rect anda;
        //LTexture* spriteSheetTexture;

};


#endif // EGG_H
