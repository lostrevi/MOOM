#ifndef GAME_H
#define GAME_H

#include "MAP.h"

class Game
{
private:
    static const int SCREEN_WIDTH = 520;
    static const int SCREEN_HEIGHT = 650; //I want these to be change able via an ini or somthing but this is fine for now.
    bool Running = true; //this condition will be set to false if the game loop falls or stops working.

    std::string Name_of_app = "MOON 0.0.0a";

    input INPUTS;

    void updatekeys();
    void updatemouse();
    void drawmouse();
    void initmouse();

    //SDL objects
    SDL_Window* win0 = NULL;
    SDL_Renderer* Ren0 = NULL;
    SDL_Texture* Tex0 = NULL;
    SDL_Event e;

    SDL_Rect TargetMouse;

    void run(); //starts to run all of the other game loops and such

    void draw(); // handles all the drawing
    void update(); //handles like changing hp or checking for a hit
    void input(); // handles input such as key presses and such
    void commandline(); // stuff with the command line if it used at all.
    void init(); //init's stuff like filling vars.

    //tool
     SDL_Texture* loadTexture(std::string path);

    MAP GameMap;


    //testing
    std::vector<Shot> SHOTs_TEST;
    int angle = 0;


public:

    void Startup();

};


#endif
