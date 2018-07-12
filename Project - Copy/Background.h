#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"

class Background
{
    public:
        Background(LTexture*, float, float);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        Point position;
        int width;
        int height;
    protected:

    private:
        SDL_Rect background;
        LTexture* spriteSheetTexture;

};

#endif // BACKGROUND_H
