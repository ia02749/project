#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"
#include "Button.h"



class Main_menu
{
public:
    Main_menu();
    Main_menu(LTexture* image,LTexture* buttons, float x, float y);
    ~Main_menu();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void checkifclick( int x, int y);
    bool gameScreen = false;

protected:
    Point position;
    int width;
    int height;
    SDL_Rect gBackgroundTexture;
    LTexture* spriteSheetTexture;
    int maxButtons = 3;
    Button *b1,*b2,*b3;

};
