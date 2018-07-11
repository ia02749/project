#ifndef PAN_H
#define PAN_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"

class Pan
{
    public:
        Pan(LTexture*, float, float);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        Point position;
        int width;
        int height;
    protected:

    private:
        SDL_Rect tawa;
        LTexture* spriteSheetTexture;

};

#endif // PAN_H
