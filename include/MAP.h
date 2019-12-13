#ifndef MAP_H
#define MAP_H


#include "background.h"

struct Spawner
{
    //ok so here is my idea for this
    //this will only spawn on thing there will be an array of them they go off based on how far you are in the level
    //then they destory them selfs. I could even have them randomy gen if i want to go for that style of game.

    pos LOC;

    int Spawnat = 0; //i don't know what the trigger will be but i'll have this here for now untill testing is done

    bool Done = false;

    char Enemy_Code = '?';
};


class MAP //this will spawn things based on where you are on the map as well and draw the background set this up later
{
    public:
        void init(SDL_Renderer *Ren0, input *_INPUT, pos SS);

        void update();
        void draw();

        void Create_shot(Blaster Blast, bool First_shot_Playeronly);
        void Create_shot(Blaster Blast);

        void Create_Enemy(Spawner spawner);

        void Create_boom(SDL_Rect LOC);
        void Create_boom(SDL_Rect LOC,int sizeB);

        void load_Level(std::string PATH);

    private:

        void init2(); //this is stuff to init after map has inited its self

        void check_hits();

        void cleaner();

        int Map_distence = 0;

        background BK1;

        void spawner_creater(pos _LOC, int spawnat, char Enemycode);
        void spawner_creater(int spawnat, char Enemycode);
        void spawner_updater();

        void create_powerup(pos LOC);


        pos Screensize;

        SDL_Renderer *RenA;
        input *INPUT;
        RESORCEMAN RSM;

        std::vector<Shot> Shots;

        std::vector<Enemy*> Enemies;

        std::vector<Boom> Booms;

        std::vector<Spawner> Spawners;

        std::vector<powerup> Powerups;

        //Test Spawner
        Spawner TESTSPAWN;



        Player MainPlayer;
};

#endif // MAP_H
