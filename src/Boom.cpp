#include "Boom.h"

void Boom::init(SDL_Texture *Texture,pos LOC)
{
    texture = Texture;

    LOC_R.x = LOC.x - 15;
    LOC_R.y = LOC.y - 15;
    LOC_R.w = LOC_R.h = rand() % 30 + 10;///25; //this can be change to make it bigger or smaller
    Clip_R.w = Clip_R.h = 25;
    Clip_R.x = Clip_R.y = 0;

    ANGLE = rand() % 360;

    DelayBetween_Frames.init(3);

}
void Boom::init(SDL_Texture *Texture,pos LOC,int SIZEB)
{
        texture = Texture;

    LOC_R.x = LOC.x - 15;
    LOC_R.y = LOC.y - 15;
    LOC_R.w = LOC_R.h = rand() % SIZEB;
    Clip_R.w = Clip_R.h = 25;
    Clip_R.x = Clip_R.y = 0;

    ANGLE = rand() % 360;

    DelayBetween_Frames.init(3);
}

void Boom::update()
{
    if(!done)
    DelayBetween_Frames.update();

    if(DelayBetween_Frames.Check_clock())
    {
        Clip_R.x += Clip_R.w;
        if(Clip_R.x > 100)
            done = true;
    }

}
void Boom::draw(SDL_Renderer *Ren0)
{
    if(!done)
        SDL_RenderCopyEx(Ren0,texture,&Clip_R,&LOC_R,ANGLE,NULL,SDL_FLIP_NONE);
}
