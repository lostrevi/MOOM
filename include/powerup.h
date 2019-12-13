#ifndef POWERUP_H
#define POWERUP_H

#include "BlastShip.h"

class powerup
{
    public:
        void init(SDL_Renderer* Ren0, SDL_Texture* _Texture, pos _LOC);
        void update();
        void draw();

        void Used();
        bool Check_Done();
        SDL_Rect Get_rect();

    private:
        SDL_Renderer* RenA;
        SDL_Texture* Texture;
        SDL_Rect LOC;

        bool Done = false;


};

#endif // POWERUP_H
