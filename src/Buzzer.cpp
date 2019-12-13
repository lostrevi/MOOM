#include "Buzzer.h"
#include "MAP.h"

Buzzer::Buzzer()
{
    //ctor
}

Buzzer::~Buzzer()
{
    //dtor
}

void Buzzer::initShip()
{
    Fire_timer.init(25);

    hp = 1;

    if(rand() % 2 == 1)
        xchange = 1;
    else
        xchange = -1;

    LOC_SHIP.w = 30;
    LOC_SHIP.h = 35;

    HIT_SHIP.x = LOC.x + 6;
    HIT_SHIP.y = LOC.y;
    HIT_SHIP.w = 30 - 11;
    HIT_SHIP.h = 33;


        Blaster NEWBLASTER;
        NEWBLASTER.angel = 90 ;
        NEWBLASTER.From_ships_loc.x = LOC_SHIP.x + (LOC_SHIP.w/2) - 2;
        NEWBLASTER.From_ships_loc.y = LOC_SHIP.y + LOC_SHIP.h;
        NEWBLASTER.speed = 5;
        NEWBLASTER.side = 1;

        Blasters.push_back(NEWBLASTER);


}


void Buzzer::update()
{
    Fire_timer.update();
    if(!firstupdate)
    {
        firstupdate = true;
        initShip();
    }



    if(LOC_SHIP.x < 2)
        xchange = 1;
    else if(LOC_SHIP.x > (screenWidth - LOC_SHIP.w) - 2)
        xchange = -1;


    LOC_SHIP.x += xchange;
    HIT_SHIP.x += xchange;

    LOC_SHIP.y ++;
    HIT_SHIP.y ++;

    for(int i = 0; i < Blasters.size(); i++)
    {
        Blasters[i].From_ships_loc.y ++;
        Blasters[i].From_ships_loc.x += xchange;
    }

    if(Fire_timer.Check_clock())
    {
        for(int i = 0; i < Blasters.size(); i++)
        {
            Map_Pointer->Create_shot(Blasters[i]);
        }
    }

}
