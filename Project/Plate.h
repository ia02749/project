#ifndef PLATE_H
#define PLATE_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"

class Plate
{
    public:
        Plate(LTexture*, float, float);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        Point position;
        int width;
        int height;
    protected:

    private:
        SDL_Rect plate;
        LTexture* spriteSheetTexture;

};

#endif // PLATE_H
