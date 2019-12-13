#ifndef BLASTSHIP_H
#define BLASTSHIP_H

#include "Enemy.h"


class BlastShip : public Enemy
{
    public:
        BlastShip();
        virtual ~BlastShip();

        void initShip();
        void update();

    private:
        std::vector<Blaster> Blasters;
        bool firstupdate = false;

        simple_timer Fire_timer;
};

#endif // BLASTSHIP_H
