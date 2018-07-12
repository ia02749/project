#include "Costumer.h"

Costumer::Costumer(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

//    gahak.x = 85; //The left part of the button
//    gahak.y = 0;
//    gahak.w = 290-85;
//    gahak.h = 480;

    gahak.x = 0; //The left part of the button
    gahak.y = 0;
    gahak.w = 833/2;
    gahak.h = 833/2;

//    for (int i = 0, i < 10, i++)
//    {
//
//    }
    position.x = x;
    position.y = y;

    this->width = gahak.w;
    this->height = gahak.h;
}

int Costumer::GetCostumerX()
{
    return this->position.x;
}

void Costumer::Move()
{
     //speedx = speedx * friction;
     //speedy = speedy * friction;

     //x = x + speedx;
     this->position.x = this->position.x + 2; //speedy;
//     if(this->position.x > 500)
//     {
//         break;
//     }
}

void Costumer::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &gahak, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

