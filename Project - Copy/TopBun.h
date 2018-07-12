#ifndef TOPBUN_H
#define TOPBUN_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"

class TopBun
{
    public:
        TopBun(LTexture*, float, float);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        Point position;
        int width;
        int height;
    protected:

    private:
        SDL_Rect uparwalabun;
        LTexture* spriteSheetTexture;

#endif // TOPBUN_H
