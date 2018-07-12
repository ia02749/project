#include "Plate.h"

Plate::Plate(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    plate.x = 0; //The left part of the button
    plate.y = 0;
    plate.w = 300;
    plate.h = 128;

    position.x = x;
    position.y = y;

    this->width = plate.w;
    this->height = plate.h;
}

void Plate::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &plate, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

bool Plate::HasIntersect(int x, int y)
{
    return ((x > position.x - width/2 && x < position.x + width/2) && (y > position.y - height/2 && y < position.y + height/2));
}
