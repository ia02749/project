#ifndef TABLE_H
#define TABLE_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"

class Table
{
    public:
        Table(LTexture*, float, float);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        Point position;
        int width;
        int height;
    protected:

    private:
        SDL_Rect table;
        LTexture* spriteSheetTexture;

};

#endif // BACKGROUND_H
