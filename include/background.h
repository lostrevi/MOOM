#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Player.h"

class background
{
    public:
        void init(SDL_Renderer* Ren0, SDL_Texture *_LazyZone1, int zoneid);
        void update();
        void draw();

    private:
        SDL_Renderer* RenA;
        SDL_Texture *LazyZone1;
        simple_timer Tick_tock;

        SDL_Texture* Current_texture;

        int Zone_id = 0;

        SDL_Rect Tile_1;
        SDL_Rect Tile_2;



};

#endif // BACKGROUND_H
