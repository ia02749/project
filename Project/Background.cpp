#include "Background.h"

Background::Background(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    background.x = 0; //The left part of the button
    background.y = 0;
    background.w = 1000;
    background.h = 700;

    position.x = x;
    position.y = y;

    this->width = background.w;
    this->height = background.h;
}

void Background::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &background, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
