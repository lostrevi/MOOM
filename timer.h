#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <sstream>
#include <memory>
#include <set>
#include <fstream>

#define PI 3.14159265

static const int screenWidth = 520;
static const int screenHeight = 650;

struct pos
{
    double x;
    double y;
};

class simple_timer
{
    public:
    void init(int time_amount)
    {
        timeset = true;
        Time_A = Time_A_MAX = time_amount;
    }
    void update()
    {
        if(timeset && !unset)
        {
            Time_A++;
            if(Time_A >= Time_A_MAX)
            {
                Time_A = 0;
                unset = true;
            }
        }
    }

    bool Check_clock()
    {
        bool temp = unset;
        if(unset)
            unset = false;

        return temp;
    }

    private:
        bool timeset = false;
        int Time_A = 0;
        int Time_A_MAX = 0;
        bool unset = false;

};

class GTimer
{
    public:
        //Initializes variables
        GTimer();

        //The various clock actions
        void start();
        void stop();
        void pause();
        void unpause();

        //Gets the timer's time
        Uint32 getTicks();

        //Checks the status of the timer
        bool isStarted();
        bool isPaused();

    private:
        //The clock time when the timer started
        Uint32 mStartTicks;

        //The ticks stored when the timer was paused
        Uint32 mPausedTicks;

        //The timer status
        bool mPaused;
        bool mStarted;
};



#endif // TIMER_H
