#include "Player.h"

#include "MAP.h"

void Player::init(SDL_Renderer* Ren0, SDL_Texture *Texture, pos _LOC, input *_input, MAP *Map_pointer)
{
    RenA = Ren0;

    Map_Pointer = Map_pointer;

    LOC_d = _LOC;

    LOC.x = _LOC.x;
    LOC.y = _LOC.y;
    LOC.w = LOC.h = 45;

    HIT.x = LOC.x + 13;
    HIT.y = LOC.y + 20;
    HIT.w = 20;
    HIT.h = 15;

    Ship_T = Texture;

    Input = _input;

    Fire_timer.init(shottime);

    int shotspeedbase = 15;


    MainGun.angel = 270;
    MainGun.speed = shotspeedbase;
    MainGun.side = 0;
    MainGun.From_ships_loc.x = LOC.x + 45/2 - 4;
    MainGun.From_ships_loc.y = LOC.y;

    secondGUN1.angel = 270;
    secondGUN1.speed = shotspeedbase;
    secondGUN1.side = 0;
    secondGUN1.From_ships_loc.x = LOC.x + 3;
    secondGUN1.From_ships_loc.y = LOC.y + 12;
    secondGUN1.Active = false;

    secondGUN2.angel = 270;
    secondGUN2.speed = shotspeedbase;
    secondGUN2.side = 0;
    secondGUN2.From_ships_loc.x = LOC.x + 32;
    secondGUN2.From_ships_loc.y = LOC.y + 12;
    secondGUN2.Active = false;

    FarAngelGun1.angel = 260;
    FarAngelGun1.speed = shotspeedbase;
    FarAngelGun1.side = 0;
    FarAngelGun1.From_ships_loc.x = LOC.x + 3;
    FarAngelGun1.From_ships_loc.y = LOC.y + 12;
    FarAngelGun1.Active = false;

    FarAngelGun2.angel = 280;
    FarAngelGun2.speed = shotspeedbase;
    FarAngelGun2.side = 0;
    FarAngelGun2.From_ships_loc.x = LOC.x + 32;
    FarAngelGun2.From_ships_loc.y = LOC.y + 12;
    FarAngelGun2.Active = false;

    Cannon1.angel = 265;
    Cannon1.speed = shotspeedbase;
    Cannon1.side = 0;
    Cannon1.From_ships_loc.x = LOC.x + 1;
    Cannon1.From_ships_loc.y = LOC.y + 12;
    Cannon1.Active = false;

    Cannon2.angel = 275;
    Cannon2.speed = shotspeedbase;
    Cannon2.side = 0;
    Cannon2.From_ships_loc.x = LOC.x + 35;
    Cannon2.From_ships_loc.y = LOC.y + 12;
    Cannon2.Active = false;



}
void Player::update()
{
    movement_updater();
    Fire_timer.update();

    if(Input->SPACEispressed() && Fire == 0) //this is for the first shot thing
    {
        Fire = 1;
    }

    if(Input->SPACEispressed() && Fire_timer.Check_clock())
    {
        bool SP_SHOT = false;
        if(Fire == 1)
            SP_SHOT = true;

        if(!dead)
        {
            Map_Pointer->Create_shot(MainGun,SP_SHOT);
            Map_Pointer->Create_shot(secondGUN1,SP_SHOT);
            Map_Pointer->Create_shot(secondGUN2,SP_SHOT);
            Map_Pointer->Create_shot(Cannon1,SP_SHOT);
            Map_Pointer->Create_shot(Cannon2,SP_SHOT);
            Map_Pointer->Create_shot(FarAngelGun1,SP_SHOT);
            Map_Pointer->Create_shot(FarAngelGun2,SP_SHOT);
        }


        Fire = 2;

    }

    if(!Input->SPACEispressed() && Fire == 2)
    {
        Fire = 0;
    }

    //testing
    if(Input->NUM0ispressed())
    {
        Levelup(true);
        std::cout << "Debug Level up LEVEL is now : " << LEVEL << std::endl;
    }

    if(Input->NUM1ispressed() && !debugkeylock)
    {
        debugkeylock = true;
        Levelup(false);
        std::cout << "Debug Level up LEVEL is now : " << LEVEL << std::endl;
    }
    else if(!Input->NUM1ispressed() && debugkeylock)
    {
        debugkeylock = false;
    }




}
void Player::draw()
{
    if(!dead)
    SDL_RenderCopy(RenA,Ship_T,NULL,&LOC);

    //SDL_SetRenderDrawColor(RenA,255,0,0,255);
    //SDL_RenderDrawRect(RenA, &HIT);

}


void Player::movement_updater()
{

        //610 y max
        //0 x min
        //475 x max
        //100 y min

        double Y_BOUNDMAX = 600;
        double Y_BOUNDMIN = 100;
        double X_BOUNDMAX = 475;
        double X_BOUNDMIN = 0;



        //get transform

            if(Input->Wispressed() && LOC_d.y > Y_BOUNDMIN)
            {
                Movement_y -= Y_move_var;
            }
            else if(Input->Sispressed() && LOC_d.y < Y_BOUNDMAX)
            {
                Movement_y += Y_move_var;
            }
            if(Input->Aispressed() && LOC_d.x > X_BOUNDMIN)
            {
                Movement_x -= X_move_var;
            }
            else if(Input->Dispressed() && LOC_d.x < X_BOUNDMAX)
            {
                Movement_x += X_move_var;
            }

            if(Movement_x > Max_move_X)
                Movement_x = Max_move_X;
            else if(Movement_x < -Max_move_X)
                Movement_x = -Max_move_X;
            if(Movement_y > Max_move_Y)
                Movement_y = Max_move_Y;
            else if(Movement_y < -Max_move_Y)
                Movement_y = -Max_move_Y;


       if( ( !Input->Wispressed() || LOC_d.y <= Y_BOUNDMIN ) && ( !Input->Sispressed() || LOC_d.y > Y_BOUNDMAX )  )
        {
            if(Movement_y > 0)
                Movement_y -= Y_move_var;
            else if(Movement_y < 0)
                Movement_y += Y_move_var;

        }
        if( (!Input->Aispressed() || LOC_d.x < X_BOUNDMIN) && ( !Input->Dispressed() || LOC_d.x > X_BOUNDMAX ) )
        {
            if(Movement_x > 0)
                Movement_x -= X_move_var;
            else if(Movement_x < 0)
                Movement_x += X_move_var;
        }



        //Do cal
        LOC_d.x += Movement_x;
        LOC_d.y += Movement_y;

        //update hit
        HIT.x += Movement_x;
        HIT.y += Movement_y;

        //update blast loc
        MainGun.From_ships_loc.x += Movement_x;
        MainGun.From_ships_loc.y += Movement_y;
        secondGUN1.From_ships_loc.x += Movement_x;
        secondGUN1.From_ships_loc.y += Movement_y;
        secondGUN2.From_ships_loc.x += Movement_x;
        secondGUN2.From_ships_loc.y += Movement_y;
        Cannon1.From_ships_loc.x += Movement_x;
        Cannon1.From_ships_loc.y += Movement_y;
        Cannon2.From_ships_loc.x += Movement_x;
        Cannon2.From_ships_loc.y += Movement_y;
        FarAngelGun1.From_ships_loc.x += Movement_x;
        FarAngelGun1.From_ships_loc.y += Movement_y;
        FarAngelGun2.From_ships_loc.x += Movement_x;
        FarAngelGun2.From_ships_loc.y += Movement_y;


        LOC.x = LOC_d.x;
        LOC.y = LOC_d.y;

        //std::cout << "ship x, y : " << LOC.x << ", " << LOC.y << "\n";

        //610 y max
        //0 x min
        //475 x max
        //100 y min

}



void Player::Levelup(bool loseallLevel)
{
    if(LEVEL != MaxLEVEL)
    {
        LEVEL++;
    }

    if(loseallLevel)
        LEVEL = 0;

    switch(LEVEL)
    {
        case 0:
            MainGun.Active = true;
            secondGUN1.Active = false;
            secondGUN2.Active = false;
            Cannon1.Active = false;
            Cannon2.Active = false;
            FarAngelGun1.Active = false;
            FarAngelGun2.Active = false;
        break;
        case 1:
            MainGun.Active = true;
            secondGUN1.Active = true;
            secondGUN2.Active = true;
            Cannon1.Active = false;
            Cannon2.Active = false;
            FarAngelGun1.Active = false;
            FarAngelGun2.Active = false;
        break;
        case 2:
            MainGun.Active = true;
            secondGUN1.Active = true;
            secondGUN2.Active = true;
            Cannon1.Active = true;
            Cannon2.Active = true;
            FarAngelGun1.Active = false;
            FarAngelGun2.Active = false;
        break;
        case 3:
            MainGun.Active = true;
            secondGUN1.Active = true;
            secondGUN2.Active = true;
            Cannon1.Active = true;
            Cannon2.Active = true;
            FarAngelGun1.Active = true;
            FarAngelGun2.Active = true;
        break;
    }

}















