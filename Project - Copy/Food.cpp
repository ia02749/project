#include "Food.h"

Food::Food()
{
    //ctor
}

bool Food::HasIntersect(int x, int y)
{
    return ((x > position.x - width/2 && x < position.x + width/2) && (y > position.y - height/2 && y < position.y + height/2));
    //return SDL_HasIntersection(Mouse, khana);
}

void Food::MoveWithMouse(int a, int b)
{
    position.x = a;
    position.y = b;
}

void Food::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &khana, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
