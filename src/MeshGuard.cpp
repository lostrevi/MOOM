#include "MeshGuard.h"
#include "Map.h"

MeshGuard::MeshGuard()
{
    //ctor
}

void MeshGuard::initShip()
{
    Fire_timer.init(25);

    hp = 300;



    LOC_SHIP.w = 300;
    LOC_SHIP.h = 100;

    HIT_SHIP.x = LOC.x + 6;
    HIT_SHIP.y = LOC.y;
    HIT_SHIP.w = 300 - 11;
    HIT_SHIP.h = 100;


        /*Blaster NEWBLASTER;
        NEWBLASTER.angel = 90 ;
        NEWBLASTER.From_ships_loc.x = LOC_SHIP.x + (LOC_SHIP.w/2) - 2;
        NEWBLASTER.From_ships_loc.y = LOC_SHIP.y + LOC_SHIP.h;
        NEWBLASTER.speed = 5;
        NEWBLASTER.side = 1; */
        //Blasters.push_back(NEWBLASTER);

        for(int i = 0; i < 6; i++)
        {
            Blaster newBlaster;
            newBlaster.angel = Angle_turn_amount * (i+1);
            newBlaster.From_ships_loc.x = LOC_SHIP.x + 50 * i;
            newBlaster.From_ships_loc.y = LOC_SHIP.y + LOC_SHIP.h;
            newBlaster.speed = 5;
            newBlaster.side = 1;

            Blasters.push_back(newBlaster);
        }




}


void MeshGuard::update()
{
    Fire_timer.update();
    if(!firstupdate)
    {
        firstupdate = true;
        initShip();
    }




    if(Enter && firstupdate)
    {
        if(LOC_SHIP.y < 10)
        {
            LOC_SHIP.y ++;
            HIT_SHIP.y ++;
            for(int i = 0; i < Blasters.size(); i++)
            {
                Blasters[i].From_ships_loc.y ++;
            }
        }
        else
        {
            Enter = false;
            AttackMode = true;
        }

    }





    if(Fire_timer.Check_clock() && AttackMode )
    {
        for(int i = 0; i < Blasters.size(); i++)
        {
            Map_Pointer->Create_shot(Blasters[i]);
        }
            Cycle_Targeting();
    }

}



void MeshGuard::Cycle_Targeting()
{
    for( int i = 0 ; i < Blasters.size(); i++ )
    {
        Blasters[i].angel += Angle_turn_amount;
        if(Blasters[i].angel > (Angle_turn_amount*6) )
            Blasters[i].angel = Angle_turn_amount;
    }

}










