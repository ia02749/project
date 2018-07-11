#ifndef KETCHUPBOTTLE_H
#define KETCHUPBOTTLE_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"

class KetchupBottle
{
    public:
        KetchupBottle(LTexture*, float, float);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        Point position;
        int width;
        int height;
    protected:

    private:
        SDL_Rect ketchup;
        LTexture* spriteSheetTexture;

};

#endif // KETCHUPBOTTLE_H
