#include "Shot.h"



void Shot::init(SDL_Texture *_Shot_Texture, pos _LOC, double _angel, double _speed, int _side)
{
    Shot_texture = _Shot_Texture;
    LOC = _LOC;
    Angel = _angel;
    speed = _speed;
    side = _side;

    LOC_RECT.x = LOC.x;
    LOC_RECT.y = LOC.y;
    LOC_RECT.w = 9;
    LOC_RECT.h = 10;

    Hitx = HIT_RECT.x = LOC.x + 2;
    Hity = HIT_RECT.y = LOC.y;
    HIT_RECT.w = 5;
    HIT_RECT.h = 10;
}

void Shot::update()
{
    //LOC.x = LOC_RECT.x;
    //LOC.y = LOC_RECT.y;

   check_out_of_range();


    //x1 =  cos(Angel) * _Speed;
    //y1 =  sin(Angel) * _Speed;
        double Thada = Angel*3.14159265359/180;
    LOC.x += (cos(Thada)*speed); //- OffsetX;
    LOC.y += (sin(Thada)*speed); //- OffsetY;
    Hitx += (cos(Thada)*speed); //- OffsetX;
    Hity += (sin(Thada)*speed); //- OffsetY;

    //note! make sure you add into the double cz that shti needs it or else it smashes your usable angles


    LOC_RECT.x = LOC.x;
    HIT_RECT.x = Hitx;
    LOC_RECT.y = LOC.y;
    HIT_RECT.y = Hity;
}

void Shot::draw(SDL_Renderer *RenA)
{


    if(!dead && !SpShot)
            if(side == 1)
            SDL_SetTextureColorMod(Shot_texture, 255, 100, 100);

        SDL_RenderCopyEx( RenA, Shot_texture,NULL, &LOC_RECT, Angel+90, center, SDL_FLIP_NONE );

        SDL_SetTextureColorMod(Shot_texture, 255, 255, 255);

    if(SpShot)
    {
        SDL_SetTextureColorMod(Shot_texture, 0, 255, 255);

        if(!dead)
        SDL_RenderCopyEx( RenA, Shot_texture,NULL, &LOC_RECT, Angel+90, center, SDL_FLIP_NONE );

        SDL_SetTextureColorMod(Shot_texture, 255, 255, 255);

    }





}


void Shot::check_out_of_range()
{
    if(LOC_RECT.y < -29 || LOC_RECT.y > 800)
        dead = true;
}










