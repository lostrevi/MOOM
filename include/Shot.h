#ifndef SHOT_H
#define SHOT_H

#include "Boom.h"







class Shot
{
    public:
        void init(SDL_Texture *_Shot_Texture, pos _LOC, double _angel, double _speed, int _side);
        void update();
        void draw(SDL_Renderer *RenA);

        bool is_dead()
        {
            return dead;
        }

        void shot_dead()
        {
            dead = true;
        }

        void is_SP_SHOT()
        {
            SpShot = true;
            damage = damage * 3; //change as needed
        }

        SDL_Rect get_HIT_rect()
        {
            return HIT_RECT;
        }

        int Check_side()
        {
            return side;
        }

        int get_dmg()
        {
            return damage;
        }

    private:
        pos LOC;
        SDL_Rect LOC_RECT;
        SDL_Rect HIT_RECT;

        void check_out_of_range();

        bool SpShot = false;

            double Hitx = 0;
            double Hity = 0;

        SDL_Point* center = NULL; //IDK

        double speed = 0;

        int side = 0; // zero is player and 1 is bad guys. anything else idk yet

        int damage = 1;

        bool dead = false;

        double Angel = 0;

        SDL_Texture *Shot_texture;
};

struct Blaster
{
    pos From_ships_loc;

    double angel = 0;
    double speed = 0;
    int side = 0;

    bool Active = true;
};

#endif // SHOT_H
