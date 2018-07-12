#ifndef COSTUMER_H
#define COSTUMER_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Point.h"

class Costumer
{
    public:
        Costumer(LTexture*, float, float);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        Point position;
        int width;
        int height;
        void Move();
        int GetCostumerX();
    protected:

    private:
        SDL_Rect gahak;
        LTexture* spriteSheetTexture;

};

#endif // COSTUMER_H
