#include "Table.h"

Table::Table(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    table.x = 0; //The left part of the button
    table.y = 0;
    table.w = 1500;
    table.h = 700;

    position.x = x;
    position.y = y;

    this->width = table.w;
    this->height = table.h;
}

void Table::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &table, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
