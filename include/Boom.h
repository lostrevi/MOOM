#ifndef BOOM_H
#define BOOM_H

#include "RESORCEMAN.h"




class Boom
{
    public:
        void init(SDL_Texture *Texture,pos LOC);
        void init(SDL_Texture *Texture,pos LOC,int SIZEB);

        void update();
        void draw(SDL_Renderer *Ren0);

        bool is_done()
        {
            return done;
        }

    private:
        SDL_Texture *texture;
        SDL_Rect LOC_R;
        SDL_Rect Clip_R;

        int sizeB = 0;

        double ANGLE = 270;

        simple_timer DelayBetween_Frames;

        bool done = false;


};

#endif // BOOM_H
