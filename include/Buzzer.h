#ifndef BUZZER_H
#define BUZZER_H

#include "MeshGuard.h"

class Buzzer : public Enemy
{
    public:
        Buzzer();
        virtual ~Buzzer();

        void initShip();
        void update();

    private:
        std::vector<Blaster> Blasters;
        bool firstupdate = false;
            int xchange = 0;

        simple_timer Fire_timer;
};

#endif // BUZZER_H
