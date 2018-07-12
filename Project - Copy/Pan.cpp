#include "Pan.h"

Pan::Pan(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    tawa.x = 0; //The left part of the button
    tawa.y = 0;
    tawa.w = 250;
    tawa.h = 200;

    position.x = x;
    position.y = y;

    this->width = tawa.w;
    this->height = tawa.h;
}

void Pan::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &tawa, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

