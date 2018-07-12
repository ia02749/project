#include "MayoBottle.h"

MayoBottle::MayoBottle(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    khana.x = 0; //The left part of the button
    khana.y = 0;
    khana.w = 133;
    khana.h = 133;

    position.x = x;
    position.y = y;

    this->width = khana.w;
    this->height = khana.h;
}

//void MayoBottle::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
//{
//    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &khana, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
//    if(debug == true)
//    {
//        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
//        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
//        SDL_RenderDrawRect( gRenderer, &rect );
//    }
//}
