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
#include <iostream>
#include "Food.h"

using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture background, Thela, palate, kharedar, pan, lowerbun, upperbun, laalchatni, safedchatni, anda;

//SDL_Rect srcrect;
//SDL_Rect dstrect;




int main( int argc, char* args[] )
{
//    srcrect.w = 10;
//    srcrect.h = 10;

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
            BottomBun bb(&lowerbun, 100, 600); ///here
            ToppBun tb(&upperbun, 100, 520);
            KetchupBottle kb(&laalchatni, 230, 600);
            MayoBottle mb(&safedchatni, 300, 600);
            Egg eg(&anda, 790, 568 );
            BottomBun doosrabottom(&lowerbun, (float)SCREEN_WIDTH/2, 570);
            ToppBun doosratop(&upperbun, (float)SCREEN_WIDTH/2, 500);

            bool mouseClicked = false;
            bool check1 = false;
            bool check2 = false;
            int seq = 0;


            while( !quit )                          //While application is running
            {
                while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    //}
                    //if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                    // {
                    //Get mouse position
                    //int x, y;
                    //SDL_GetMouseState( &x, &y );

//                        if(e.type ==  SDL_MOUSEMOTION)
//                        {
//                            if(mouseClicked == true)
//                                fillRect = { oldx, oldy, x - oldx, y - oldy };
//                        }

                    if(e.type == SDL_MOUSEMOTION)
                    {
                        if ((e.button.button == SDL_BUTTON_LEFT)) //takes the co-ordinates when the mouse button is clicked
                        {
                            //if(mouseClicked == false)
                            //{
                            mouseClicked = true;
                            //cout << "yay" << endl;

                            //BottomBun doosra(&lowerbun, 100, 600) = new BottomBun;

                            if (mouseClicked == true)
                            {
                                if (bb.HasIntersect(e.button.x, e.button.y))
                                {
                                    seq = 1;
                                    bb.MoveWithMouse(e.button.x,e.button.y);
                                    cout<<"sec 1"<<endl;
                                }
                                if (tb.HasIntersect(e.button.x, e.button.y))
                                {
                                    seq = 2;
                                    tb.MoveWithMouse(e.button.x, e.button.y);
                                    cout<<"sec 2"<<endl;
                                }
                            }
                        }
                    }
                    if(e.type == SDL_MOUSEBUTTONUP)
                    {
                        mouseClicked = false;
                        if (seq == 1)
                        {
                            bb.MoveWithMouse(100,600);
                        }
                        if (seq == 2)
                        {
                            cout << "aaaa" << endl;
                            tb.MoveWithMouse(100, 520);
                        }
                        cout<<" button up"<<endl;

                        if (p.HasIntersect(e.button.x, e.button.y) && (seq == 1) && mouseClicked == false)
                        {
                            cout<<" plate match"<<endl;
                            check1 = true;
                        }
                        if (p.HasIntersect(e.button.x, e.button.y) && (seq == 2) && mouseClicked == false)
                        {
                            cout<<" plate match"<<endl;
                            check2 = true;
                        }
                    }
                    //}
                    //if (tb.HasIntersect())
                    //cout<<" button up"<<endl;
//                            if (p.HasIntersect(e.button.x, e.button.y) && mouseClicked == false)
//                            {
//                                //cout<<" plate match"<<endl;
//                                check = 2;
//                            }

//                            if (mouseClicked == false)
//                            {
//
//
//
//                                //BottomBun doosra(&lowerbun, 100, 600);
//                                //doosra.Render(frame, gRenderer, true);
//
//                            }


            }



//				srcrect.x = e.button.x;
//                srcrect.y = e.button.y;
//cout << "Hi" << endl;
            if (bb.HasIntersect(e.button.x, e.button.y))
            {
                //cout << "Yayy" << endl;
            }

            //Egg.HasIntersect(s);

//				if ((e.button.x > 10 && e.button.x < 190) && (e.button.y > 495 && e.button.y < 545) && (e.button.button == SDL_BUTTON_LEFT))
//                {
//                    cout << "Top Bun Clicked" << endl;
//                }
//
//                if ((e.button.x > 10 && e.button.x < 190) && (e.button.y > 575 && e.button.y < 625) && (e.button.button == SDL_BUTTON_LEFT))
//                {
//                    cout << "Bottom Bun Clicked" << endl;
//                }
//
//                if ((e.button.x > 206 && e.button.x < 256) && (e.button.y > 537 && e.button.y < 665) && (e.button.button == SDL_BUTTON_LEFT))
//                {
//                    cout << "Ketchup Bottle Clicked" << endl;
//                }
//
//                if ((e.button.x > 279 && e.button.x < 323) && (e.button.y > 533 && e.button.y < 699) && (e.button.button == SDL_BUTTON_LEFT))
//                {
//                    cout << "Mayo Bottle Clicked" << endl;
//                }
//
//                if ((e.button.x > 712 && e.button.x < 867) && (e.button.y > 493 && e.button.y < 639) && (e.button.button == SDL_BUTTON_LEFT))
//                {
//                    cout << "Egg Clicked" << endl;
//                }

            // cout << e.button.x << "," << e.button.y << endl;

            //if (e.button.x)

            //SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };

//                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
//                SDL_RenderDrawRect( gRenderer, &srcrect );

            if (c.GetCostumerX() < (float)SCREEN_WIDTH/2)
            {
                c.Move();
            }

            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
            SDL_RenderClear( gRenderer );

            //b.Render()
            bool debug = false;
            b.Render(frame, gRenderer, debug); //Renders the Button
            c.Render(frame, gRenderer, debug);
            t.Render(frame, gRenderer, debug);
            p.Render(frame, gRenderer, debug);
            pn.Render(frame, gRenderer, debug);
            bb.Render(frame, gRenderer, debug);
            tb.Render(frame, gRenderer, debug);
            kb.Render(frame, gRenderer, debug);
            mb.Render(frame, gRenderer, debug);
            eg.Render(frame, gRenderer, debug);
            if (check1 == true)
            {

                doosrabottom.Render(frame, gRenderer, true);
                //doosratop.Render(frame, gRenderer, true);
            }
            if (check2 == true)
            {
                doosratop.Render(frame, gRenderer, true);
            }

            //   SDL_RenderDrawRect(gRenderer, &srcrect);

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

