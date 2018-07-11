#include "Egg.h"

Egg::Egg(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    anda.x = 0; //The left part of the button
    anda.y = 0;
    anda.w = 170;
    anda.h = 163;

    position.x = x;
    position.y = y;

    this->width = anda.w;
    this->height = anda.h;
}

void Egg::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &anda, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
