#include "MayoBottle.h"

MayoBottle::MayoBottle(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    mayo.x = 0; //The left part of the button
    mayo.y = 0;
    mayo.w = 133;
    mayo.h = 133;

    position.x = x;
    position.y = y;

    this->width = mayo.w;
    this->height = mayo.h;
}

void MayoBottle::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &mayo, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
