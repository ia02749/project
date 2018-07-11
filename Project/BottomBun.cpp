#include "BottomBun.h"

BottomBun::BottomBun(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    neechaywalabun.x = 0; //The left part of the button
    neechaywalabun.y = 0;
    neechaywalabun.w = 481;
    neechaywalabun.h = 128;

    position.x = x;
    position.y = y;

    this->width = neechaywalabun.w;
    this->height = neechaywalabun.h;
}

void BottomBun::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &neechaywalabun, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}


