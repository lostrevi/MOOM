#ifndef PLAYER_H
#define PLAYER_H

#include "Buzzer.h" //just stack them though since i cant think of a better why to set this up.



class Player
{
    public:
        void init(SDL_Renderer* Ren0, SDL_Texture *Texture, pos _LOC, input *_input, MAP *Map_pointer);
        void update();
        void draw();

        bool check_dead()
        {
            return dead;
        }

        bool Check_fire();

        void take_damage()
        {
            if(LEVEL > 0)
            {
                Levelup(true);
            }
            else
            {
                dead = true;
            }
        }

        void Levelup(bool loseallLevel);

        SDL_Rect get_hit()
        {
            return HIT;
        }

    private:

        //can remove this after done with ship level testings
        bool debugkeylock = true;

        bool dead = false;

        int LEVEL = 0;
        int MaxLEVEL = 3;

        int shottime = 6;

        MAP *Map_Pointer;

        Blaster MainGun;

        Blaster secondGUN1;
        Blaster secondGUN2;

        Blaster Cannon1;
        Blaster Cannon2;

        Blaster FarAngelGun1;
        Blaster FarAngelGun2;

        simple_timer Fire_timer;



        SDL_Renderer * RenA;
        input *Input;
        SDL_Texture *Ship_T;
        SDL_Rect LOC;
        SDL_Rect HIT;

        int Fire = 0;

        double X_move_var = 1;
        double Y_move_var = 1;
        double Max_move_X = 7;
        double Max_move_Y = 7;
        double Movement_x = 0;
        double Movement_y = 0;

        pos LOC_d;

        void movement_updater();


};

#endif // PLAYER_H
