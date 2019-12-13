#include "Game.h"

void Game::Startup()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout <<  "SDL didn't set up video ERROR : " << SDL_GetError() ;
    }
                     //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    std::cout <<  "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
                }
    win0 = SDL_CreateWindow( Name_of_app.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
            if( win0 == NULL )
        {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError();
            SDL_Quit();
        }
    Ren0 = SDL_CreateRenderer(win0, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Ren0 == NULL){
        SDL_DestroyWindow(win0);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

        //Initialize renderer color
        SDL_SetRenderDrawColor( Ren0, 0xFF, 0xFF, 0xFF, 0xFF );

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            std::cout << "SDL_image could not initialize! SDL_image Error: " <<  IMG_GetError() << std::endl;
        }

        //dump into RUN
        run();
}

SDL_Texture* Game::loadTexture(std::string path)
    {
            //The final texture
            SDL_Texture* newTexture = NULL;

            //Load image at specified path
            SDL_Surface* loadedSurface = IMG_Load( path.c_str() );


            if( loadedSurface == NULL )
            {
                std::cout <<  "Unable to load image" << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
            }
            else
            {
                //Create texture from surface pixels
                newTexture = SDL_CreateTextureFromSurface( Ren0, loadedSurface );
                if( newTexture == NULL )
                {
                    std::cout << "Unable to create texture from" <<  path << "! SDL Error: " << SDL_GetError() << std::endl;
                }

                //Get rid of old loaded surface
                SDL_FreeSurface( loadedSurface );
            }

            return newTexture;
}
