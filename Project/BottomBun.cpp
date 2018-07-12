#include "BottomBun.h"

BottomBun::BottomBun(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    khana.x = 0; //The left part of the button
    khana.y = 0;
    khana.w = 181;
    khana.h = 48;

    position.x = x;
    position.y = y;

    this->width = khana.w;
    this->height = khana.h;
}
//
//void BottomBun::MoveWithMouse(int a, int b)
//{
//    position.x = a;
//    position.y = b;
//}
//int BottomBun::GetCordinates()
//{
//    int x1 = int x3 = position.x;
//    int y1 = int y2 = position.y;
//    int x2 = int x4 = position.x + neechaywalabun.w;
//    int y3 = int y4 = position.y + neechaywalabun.h;
//}

//void BottomBun::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
//{
//    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &khana, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
//    if(debug == true)
//    {
//        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
//        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
//        SDL_RenderDrawRect( gRenderer, &rect );
//    }
//}
