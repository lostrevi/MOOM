#include "game.h"


void Game::initmouse()
{
    SDL_ShowCursor(SDL_DISABLE);

    TargetMouse.x = 0;
    TargetMouse.y = 0;
    TargetMouse.w = 4;
    TargetMouse.h = 4;
}


void Game::updatemouse()
{

    TargetMouse.x = INPUTS.GetMouseX();
    TargetMouse.y = INPUTS.GetMouseY();


    if(INPUTS.LCPressed())
    {
        //std::cout << "Left Click\n";
        Shot NewSHOT;
        pos NEWPOS = {TargetMouse.x, TargetMouse.y};
        NewSHOT.init(loadTexture("Data/Shot.png"),NEWPOS, angle, 5, 0);
        SHOTs_TEST.push_back(NewSHOT);


    }
    if(INPUTS.RCPressed())
    {
        std::cout << "Right Click\n";
    }
    if(INPUTS.MCPressed())
    {
      std::cout << "Middle Click\n";
    }
    else if(!INPUTS.MCPressed())
    {
        //Release
    }



    if(INPUTS.GetWheelUp())
    {
        //std::cout << "mouse wheel up\n";
        angle++;
        std::cout << "angel : " << angle << std::endl;
    }
    if(INPUTS.GetWheelDown())
    {
        //std::cout << "mouse wheel down\n";
        angle--;
        std::cout << "angel : " << angle << std::endl;
    }


}

void Game::drawmouse()
{
    SDL_SetRenderDrawColor( Ren0, 255, 0, 0, 0xFF );
    SDL_RenderDrawRect(Ren0,&TargetMouse);
}

