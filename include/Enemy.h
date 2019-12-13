#ifndef ENEMY_H
#define ENEMY_H

#include "Shot.h"

class MAP;

class Enemy
{
    public:
        void init(SDL_Renderer *Ren0, SDL_Texture *Texture, pos _LOC, MAP *MapPointer, char type);
        virtual void initShip();
        virtual void update();
        virtual void draw();

        void Take_Damage(int dmg)
        {
            hp -= dmg;
            if(hp < 1)
                dead = true;
        }

        bool is_dead()
        {
            return dead;
        }

        char Get_type()
        {
            return Type;
        }

        SDL_Rect Get_hit()
        {
            return HIT_SHIP;
        }

    protected:
        char Type = '?';

        SDL_Renderer *RenA;
        SDL_Texture *Ship_Texture;
        pos LOC;
        MAP *Map_Pointer;

        SDL_Rect LOC_SHIP = {-999,-999,2,2};
        SDL_Rect HIT_SHIP = {-999,-999,2,2};

        int hp = 1;

        bool dead = false;

};

#endif // ENEMY_H
