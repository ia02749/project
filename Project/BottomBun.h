#ifndef BOTTOMBUN_H
#define BOTTOMBUN_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"

class BottomBun
{
    public:
        BottomBun(LTexture*, float, float);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        Point position;
        int width;
        int height;
    protected:

    private:
        SDL_Rect neechaywalabun;
        LTexture* spriteSheetTexture;

};


#endif // BOTTOMBUN_H
