#include "ToppBun.h"

ToppBun::ToppBun(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    uparwalabun.x = 0; //The left part of the button
    uparwalabun.y = 0;
    uparwalabun.w = 181;
    uparwalabun.h = 48;

    position.x = x;
    position.y = y;

    this->width = uparwalabun.w;
    this->height = uparwalabun.h;
}

void ToppBun::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &uparwalabun, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
