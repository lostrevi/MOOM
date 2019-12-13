#include "background.h"

void background::init(SDL_Renderer* Ren0, SDL_Texture *_LazyZone1, int zoneid)
{
    RenA = Ren0;
    LazyZone1 = LazyZone1;
    Zone_id = zoneid;

    Tick_tock.init(3);

    Current_texture = _LazyZone1;

    Tile_1 = {0,0,screenWidth,screenHeight};
    Tile_2 = {0,-screenHeight,screenWidth,screenHeight};
}
void background::update()
{
    Tick_tock.update();
    if(Tick_tock.Check_clock())
    {
        Tile_1.y ++;
        Tile_2.y ++;

        if(Tile_1.y == screenHeight)
            Tile_1.y = -screenHeight;
        if(Tile_2.y == screenHeight)
            Tile_2.y = -screenHeight;
    }
}
void background::draw()
{
    SDL_RenderCopy(RenA,Current_texture,NULL,&Tile_1);
    SDL_RenderCopy(RenA,Current_texture,NULL,&Tile_2);
}
