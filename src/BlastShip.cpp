#include "BlastShip.h"

#include "MAP.h"

BlastShip::BlastShip()
{

}

BlastShip::~BlastShip()
{
    //dtor
}

void BlastShip::initShip()
{
    Fire_timer.init(45);

    hp = 25;

    LOC_SHIP.w = LOC_SHIP.h = 60;

    HIT_SHIP.x = LOC.x + 11;
    HIT_SHIP.y = LOC.y;
    HIT_SHIP.w = 60 - 24;
    HIT_SHIP.h = 50;

    int angleofshot = 25;

    for(int i = 0 ; i < 6; i++)
    {
        Blaster NEWBLASTER;
        NEWBLASTER.angel = 180 - (angleofshot*(i+1));
        NEWBLASTER.From_ships_loc.x = LOC_SHIP.x + LOC_SHIP.w/2;
        NEWBLASTER.From_ships_loc.y = LOC_SHIP.y + LOC_SHIP.w/2;
        NEWBLASTER.speed = 4;
        NEWBLASTER.side = 1;

        Blasters.push_back(NEWBLASTER);
    }


}


void BlastShip::update()
{
    Fire_timer.update();
    if(!firstupdate)
    {
        firstupdate = true;
        initShip();
    }

    LOC_SHIP.y ++;
    HIT_SHIP.y ++;

    for(int i = 0; i < Blasters.size(); i++)
    {
        Blasters[i].From_ships_loc.y ++;
    }

    if(Fire_timer.Check_clock())
    {
        for(int i = 0; i < Blasters.size(); i++)
        {
            Map_Pointer->Create_shot(Blasters[i]);
        }
    }

}
