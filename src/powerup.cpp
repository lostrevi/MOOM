#include "powerup.h"

void powerup::init(SDL_Renderer* Ren0, SDL_Texture* _Texture, pos _LOC)
{
    RenA = Ren0;
    Texture = _Texture;
    LOC.x = _LOC.x;
    LOC.y = _LOC.y;
    LOC.w = LOC.h = 20;


}
void powerup::update()
{
    LOC.y ++;
    if(LOC.y > 800)
        Done = true;
}
void powerup::draw()
{
    if(!Done)
        SDL_RenderCopy(RenA,Texture,NULL,&LOC);
}

void powerup::Used()
{
    Done = true;
}
bool powerup::Check_Done()
{
    return Done;
}
SDL_Rect powerup::Get_rect()
{
    return LOC;
}
