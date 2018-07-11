#include "KetchupBottle.h"

KetchupBottle::KetchupBottle(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    ketchup.x = 0; //The left part of the button
    ketchup.y = 0;
    ketchup.w = 133;
    ketchup.h = 133;

    position.x = x;
    position.y = y;

    this->width = ketchup.w;
    this->height = ketchup.h;
}

void KetchupBottle::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &ketchup, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
