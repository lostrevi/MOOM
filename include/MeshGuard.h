#ifndef MESHGUARD_H
#define MESHGUARD_H

#include "powerup.h"


class MeshGuard : public Enemy
{
    public:
        MeshGuard();

        void initShip();
        void update();

        const static int Angle_turn_amount = 26;

    private:

        bool Enter = true;

        bool AttackMode = false;

        void Cycle_Targeting();

        std::vector<Blaster> Blasters;
        bool firstupdate = false;


        simple_timer Fire_timer;
};

#endif // MESHGUARD_H
