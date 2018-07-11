#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include "Background.h"
#include<string.h>
#include "Table.h"
#include "Plate.h"
#include "Costumer.h"
#include "Pan.h"
#include "BottomBun.h"
#include "ToppBun.h"
#include "KetchupBottle.h"
#include "MayoBottle.h"
#include "Egg.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture background, Thela, palate, kharedar, pan, lowerbun, upperbun, laalchatni, safedchatni, anda;

int main( int argc, char* args[] )
{
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;                      //Main loop flag
			SDL_Event e;                            //Event handler
			long int frame = 0;                     //Current animation frame

            srand (time(NULL));

            Background b(&background, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
            Table t(&Thela, 490, 750);
            Plate p(&palate, (float)SCREEN_WIDTH/2, 570);
            Costumer c(&kharedar, -10, 300);
            Pan pn(&pan, 780, 570);
            BottomBun bb(&lowerbun, 100, 600);
            ToppBun tb(&upperbun, 100, 520);
            KetchupBottle kb(&laalchatni, 230, 600);
            MayoBottle mb(&safedchatni, 300, 600);
            Egg eg(&anda, 790, 568 );

            while( !quit )                          //While application is running
			{
				while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
				{
                    //User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				if (c.GetCostumerX() < (float)SCREEN_WIDTH/2)
                {
                    c.Move();
                }

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
				SDL_RenderClear( gRenderer );

				//b.Render()
                b.Render(frame, gRenderer, false); //Renders the Button
                c.Render(frame, gRenderer, false);
                t.Render(frame, gRenderer, false);
                p.Render(frame, gRenderer, false);
                pn.Render(frame, gRenderer, false);
                bb.Render(frame, gRenderer, false);
                tb.Render(frame, gRenderer, false);
                kb.Render(frame, gRenderer, false);
                mb.Render(frame, gRenderer, false);
                eg.Render(frame, gRenderer, false);

				SDL_RenderPresent( gRenderer );     //Update screen

				++frame;                            //Go to next frame
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

bool init() //Initializes the Window
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Anday Wala Burger", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia() //Loads the Media
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
//    if( !kharedar.LoadFromFile( "customers.png", gRenderer  ) )
//	{
//		printf( "Failed to load sprite sheet texture!\n" );
//		success = false;
//	}
    if( !kharedar.LoadFromFile( "Umair.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !background.LoadFromFile( "back.jpg", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !Thela.LoadFromFile( "table.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !palate.LoadFromFile( "plate.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !pan.LoadFromFile( "pan.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !lowerbun.LoadFromFile( "bottombun.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !upperbun.LoadFromFile( "topbun.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !laalchatni.LoadFromFile( "ketchupbottle.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !safedchatni.LoadFromFile( "mayobottle.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !anda.LoadFromFile( "friedegg.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	return success;
}

void close() //Closes the screen
{
	//Free loaded images
	background.Free();
	Thela.Free();
	palate.Free();
	kharedar.Free();
	pan.Free();
	lowerbun.Free();
	upperbun.Free();
	laalchatni.Free();
	safedchatni.Free();
	anda.Free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

