#include "MAP.h"

void MAP::init(SDL_Renderer *Ren0, input *_INPUT, pos SS)
{
    //init map first then init other junk;
    RenA = Ren0;
    INPUT = _INPUT;
    Screensize = SS;

    RSM.init(RenA); //this should be init as soon as posable so it up here



    init2();
}

void MAP::init2()
{
    pos temp = {(Screensize.x/2)- 45/2, Screensize.y -120};
    MainPlayer.init(RenA,RSM.Get_Texture(3),temp,INPUT,this);

    load_Level("Data/Level1");

    //testing
    //this is just going to load a buch of spawners
    /*
    int Delay = 10;
    for(int i = 0; i < 10000; i ++)
    {
        Delay += rand() % 120 + 20;
        if(rand() % 2 == 1)
        spawner_creater(Delay,'b');
        else
            spawner_creater(Delay,'z');
    }
    */

    BK1.init(RenA,RSM.Get_Texture(5),1);



    //note might make a level file with this format
/*
s00000000bnnnmmm (seting spawner for ships)
------------------
   s        00000000          b          nnn        mmm
commandid     timer        Ship code     Loc x      Loc y

z00000000Ziii (changeing zone)
-------------
   z        00000000         z           iii
commandid    timer         spacer       id of zone change
*/

}


void MAP::update()
{

    cleaner();

    spawner_updater();
    BK1.update();



    MainPlayer.update();
    for(int i = 0; i < Shots.size(); i++)
    {
        Shots[i].update();
    }

    for(int i = 0; i < Enemies.size(); i++)
    {
        Enemies[i]->update();
    }

    for(int i = 0; i < Booms.size(); i++)
    {
        Booms[i].update();
    }

    for(int i = 0; i < Powerups.size(); i++)
    {
        Powerups[i].update();
    }

    check_hits();




}

void MAP::draw()
{
    BK1.draw();

    MainPlayer.draw();

    for(int i = 0; i < Enemies.size(); i++)
    {
        Enemies[i]->draw();
    }

    for(int i = 0; i < Shots.size(); i++)
    {
        Shots[i].draw(RenA);
    }

    for(int i = 0; i < Powerups.size(); i++)
    {
        Powerups[i].draw();
    }



    for(int i = 0; i < Booms.size(); i++) //drawlast so there on top.
    {
        Booms[i].draw(RenA);
    }

}


void MAP::Create_shot(Blaster Blast, bool First_shot_Playeronly)
{
    if(Blast.Active)
    {
        Shot NewShot;

        NewShot.init(RSM.Get_Texture(1), Blast.From_ships_loc, Blast.angel, Blast.speed, Blast.side);

        if(First_shot_Playeronly)
            NewShot.is_SP_SHOT();

        Shots.push_back(NewShot);
    }

}

void MAP::Create_shot(Blaster Blast)
{
    if(Blast.Active)
    {
        Shot NewShot;

        NewShot.init(RSM.Get_Texture(1), Blast.From_ships_loc, Blast.angel, Blast.speed, Blast.side);

        Shots.push_back(NewShot);
    }

}




void MAP::Create_Enemy(Spawner spawner)
{

    if(!spawner.Done)
    {

        //spawn BlastShip
        switch(spawner.Enemy_Code)
        {
            case 'b':
                {
                BlastShip* NewShip = new BlastShip();

                NewShip->init(RenA,RSM.Get_Texture(2),spawner.LOC,this,'b');

                Enemies.push_back(NewShip);
                }


            break;
            case 'z':
                {
                Buzzer* NewShip = new Buzzer();

                NewShip->init(RenA,RSM.Get_Texture(4),spawner.LOC,this,'z');

                Enemies.push_back(NewShip);
                }
            break;

                case 'M': //cap for "boss" ships
                {
                MeshGuard* NewShip = new MeshGuard();

                NewShip->init(RenA,RSM.Get_Texture(7),spawner.LOC,this,'M');

                Enemies.push_back(NewShip);
                }
            break;

            default:
                {
                    std::cout << "Ship code not valid : " << spawner.Enemy_Code << " || add it to the MAP::Create_Enemy() or make sure its the right call\n";
                }
                break;



        }





    }


}

void MAP::check_hits() //will need to add damange code here as well a creating the bomb effect also i needs to check sides
{
    for(int i = 0; i < Shots.size(); i++)
    {
        for(int j = 0; j < Enemies.size(); j++)
        {
            if(Shots[i].Check_side() != 1)
            if(checkCollision(Shots[i].get_HIT_rect(), Enemies[j]->Get_hit() ) )// && !Shots[i].is_dead() && !Enemies[i]->is_dead() )
            {

                Shots[i].shot_dead();
                Create_boom(Shots[i].get_HIT_rect());

                Enemies[j]->Take_Damage(Shots[i].get_dmg());

            }


        }
        if(Shots[i].Check_side() != 0)
        if(checkCollision(Shots[i].get_HIT_rect(), MainPlayer.get_hit() ) && !Shots[i].is_dead() && !MainPlayer.check_dead() )
        {
            MainPlayer.take_damage();
            Shots[i].shot_dead();
            Create_boom(Shots[i].get_HIT_rect());


        }

    }

    for(int i = 0; i < Powerups.size(); i++)
    {
        if(!Powerups[i].Check_Done())
        {
            if(checkCollision(MainPlayer.get_hit(), Powerups[i].Get_rect()))
            {
                Powerups[i].Used();
                MainPlayer.Levelup(false);
            }
        }
    }



}

void MAP::Create_boom(SDL_Rect LOC)
{
    Boom newBOOM;

    pos LOCCC;
    LOCCC.x = LOC.x;
    LOCCC.y = LOC.y;

    newBOOM.init(RSM.Get_Texture(0), LOCCC);
    Booms.push_back(newBOOM);
}

void MAP::Create_boom(SDL_Rect LOC,int sizeB)
{
    Boom newBOOM;

    pos LOCCC;
    LOCCC.x = LOC.x;
    LOCCC.y = LOC.y;

    newBOOM.init(RSM.Get_Texture(0), LOCCC,sizeB);
    Booms.push_back(newBOOM);
}


void MAP::spawner_creater(pos _LOC, int spawnat, char Enemycode)
{
    Spawner NewSpawn;
    NewSpawn.LOC = _LOC;
    NewSpawn.Enemy_Code = Enemycode;
    NewSpawn.Spawnat = spawnat;
    NewSpawn.Done = false;
    Spawners.push_back(NewSpawn);
}
void MAP::spawner_creater(int spawnat, char Enemycode)
{
    Spawner NewSpawn;
    NewSpawn.LOC = {rand() % ((int)Screensize.x - 80) ,-70};
    NewSpawn.Enemy_Code = Enemycode;
    NewSpawn.Spawnat = spawnat;
    NewSpawn.Done = false;
    Spawners.push_back(NewSpawn);
}
void MAP::spawner_updater()
{
    for(int i = 0; i < Spawners.size(); i++)
    {
        Spawners[i].Spawnat --;
        if(Spawners[i].Spawnat < 1)
        {
            if(Spawners[i].Enemy_Code != 'p')
                Create_Enemy(Spawners[i]);
            else
            {
                //this makes a power up;
                create_powerup(Spawners[i].LOC);
            }

            Spawners[i].Done = true;
        }
    }
}



void MAP::cleaner()
{
    for(int i = 0; i < Enemies.size();i++)
    {
        if(Enemies[i]->is_dead())
        {
            Create_boom(Enemies[i]->Get_hit(),70);
            Create_boom(Enemies[i]->Get_hit(),70);
            Create_boom(Enemies[i]->Get_hit(),70);
            Create_boom(Enemies[i]->Get_hit(),70);
            Create_boom(Enemies[i]->Get_hit(),70);
            if(i != 0)
                Enemies.erase(Enemies.begin() + i);
            if(i == 0)
                Enemies.erase(Enemies.begin());
        }
        else if(Enemies[i]->Get_hit().y > 1000) //despawn when off screen it's own think incase i add score.
        {
            if(i != 0)
                Enemies.erase(Enemies.begin() + i);
            if(i == 0)
                Enemies.erase(Enemies.begin());
        }


    }

    for(int i = 0; i < Shots.size();i++)
    {
        if(Shots[i].is_dead())
        {
            if(i != 0)
                Shots.erase(Shots.begin() + i);
            if(i == 0)
                Shots.erase(Shots.begin());
        }
    }

    for(int i = 0; i < Booms.size();i++)
    {
        if(Booms[i].is_done())
        {
            if(i != 0)
                Booms.erase(Booms.begin() + i);
            if(i == 0)
                Booms.erase(Booms.begin());
        }
    }

    for(int i = 0; i < Spawners.size(); i++)
    {
        if(Spawners[i].Done)
                    {
            if(i != 0)
                Spawners.erase(Spawners.begin() + i);
            if(i == 0)
                Spawners.erase(Spawners.begin());
        }
    }
    for(int i = 0; i < Powerups.size(); i++)
    {
        if(Powerups[i].Check_Done())
        {
            if(i != 0)
                Powerups.erase(Powerups.begin() + i);
            if(i == 0)
                Powerups.erase(Powerups.begin());
        }

    }


}

///create powerup
void MAP::create_powerup(pos LOC)
{
     powerup NewPowerup;
     NewPowerup.init(RenA,RSM.Get_Texture(6),LOC);
     Powerups.push_back(NewPowerup);
}







//Level Load stuff
void MAP::load_Level(std::string PATH)
{
    std::ifstream infile(PATH);

    int delay = 0;
    char type = 0;
    int xpos = 0;
    int ypos = 0;

    std::string line;
    while (std::getline(infile, line))
    {
        if(line[0] == 's')
        {
            ///get delay
            std::string str1 = line.substr (1,8);
                //std::cout << "THIS : " << str1 << std::endl;
            std::istringstream ( str1 ) >> delay;

            ///get type
            type = line[9];
                //std::cout << "Type : " << type << "\n";

            ///get xloc
            std::string str2 = line.substr (10,3);
                //std::cout << "THIS  : " << str2 << std::endl;
            std::istringstream ( str2 ) >> xpos;

            ///get yloc
            std::string str3 = line.substr (13,3);
                //std::cout << "THIS2 : " << str3 << std::endl;
            std::istringstream ( str3 ) >> ypos;

            ypos = ypos * -1; //setting to negitive

            if(false) //turn to for debug
                std::cout << "Map data debug log\n MODE : SPAWN\n Delay : " << delay << "\n Type : " << type << "\n Xpos : " << xpos << "\n ypos : " << ypos << "\n";

            pos LOC = {xpos, ypos};
            spawner_creater(LOC,delay,type);


            delay = 0;
            type = 0;
            xpos = 0;
            ypos = 0;

        }
        else if(line[0] == 'p')
        {
            ///get delay
            std::string str1 = line.substr (1,8);
                //std::cout << "THIS : " << str1 << std::endl;
            std::istringstream ( str1 ) >> delay;

            ///get type
            type = line[9];
                //std::cout << "Type : " << type << "\n";

            ///get xloc
            std::string str2 = line.substr (10,3);
                //std::cout << "THIS  : " << str2 << std::endl;
            std::istringstream ( str2 ) >> xpos;

            ///get yloc
            std::string str3 = line.substr (13,3);
                //std::cout << "THIS2 : " << str3 << std::endl;
            std::istringstream ( str3 ) >> ypos;

            ypos = ypos * -1; //setting to negitive

            if(false) //turn to for debug
                std::cout << "Map data debug log\n MODE : Powerup\n Delay : " << delay << "\n Type : " << type << "\n Xpos : " << xpos << "\n ypos : " << ypos << "\n";

            pos LOC = {xpos, ypos};
            spawner_creater(LOC,delay,'p');


            delay = 0;
            type = 0;
            xpos = 0;
            ypos = 0;


        }
        else
        {
            std::cout << "Error: bad map call/ map call not setup.\n";
        }


    }
}


