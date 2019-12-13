#ifndef RESORCEMAN_H
#define RESORCEMAN_H

#include "../input.h"




class RESORCEMAN //this gets all the restorces and junk
{
    public:
        void init(SDL_Renderer *Ren0);

        void Add_Texture(std::string Name, std::string PATH);

        SDL_Texture* Get_Texture(int index);

        void List_texture_index();

    private:
        SDL_Texture* loadTexture(std::string path);

        SDL_Renderer *RenA;

        std::vector<SDL_Texture*> Textures; //i guess mapper will just call it based on index.
        std::vector<std::string> Textures_T; //this is a ref

};



//public
static bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}




#endif // RESORCEMAN_H
