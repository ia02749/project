#ifndef MAYOBOTTLE_H
#define MAYOBOTTLE_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"

class MayoBottle
{
    public:
        MayoBottle(LTexture*, float, float);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        Point position;
        int width;
        int height;
    protected:

    private:
        SDL_Rect mayo;
        LTexture* spriteSheetTexture;

};


#endif // MAYOBOTTLE_H
