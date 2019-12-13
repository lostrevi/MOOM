#include "input.h"

    void input::update()
    {
                            MouseWheelDown = false;
                            MouseWheelUP = false;
             //Poll for events
        while( SDL_PollEvent( &Event0 ) )
        {



            //If mouse event happened
                        if( Event0.type == SDL_MOUSEMOTION || Event0.type == SDL_MOUSEBUTTONDOWN || Event0.type == SDL_MOUSEBUTTONUP )
                        {
                            MouseMOVEMENT = true;
                            //Get mouse position
                            int x, y;
                            //mousex = x;
                            //mousey = y;

                            SDL_GetMouseState( &x, &y );

                            mousex = x;
                            mousey = y;

                               //std::cout << "X : " << x << " " << "Y : " << y << std::endl;





                        }
                        // mouse clicks

                        if (Event0.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (Event0.button.button == SDL_BUTTON_LEFT)
                                LCTru = true;
                            if (Event0.button.button == SDL_BUTTON_RIGHT)
                                RCTru = true;
                            if (Event0.button.button == SDL_BUTTON_MIDDLE)
                                MCTru = true;
                        }

                        else if (Event0.type == SDL_MOUSEBUTTONUP)
                        {
                            if (Event0.button.button == SDL_BUTTON_LEFT)
                                LCTru = false;
                            if (Event0.button.button == SDL_BUTTON_RIGHT)
                                RCTru = false;
                            if (Event0.button.button == SDL_BUTTON_MIDDLE)
                                MCTru = false;
                        }

                        if(Event0.type == SDL_MOUSEWHEEL)
                        {


                            if( Event0.wheel.y > 0)
                                MouseWheelUP = true; //+1 so up
                            else if(Event0.wheel.y < 0)
                                MouseWheelDown = true; // -1 so down

                        }










                                //User requests quit
                    if( Event0.type == SDL_QUIT )
                    {
                        quit = true;
                    }


                switch( Event0.type )
                {
            /* Look for a keypress */
                case SDL_KEYDOWN:
                /* Check the SDLKey values and move change the coords */
                switch( Event0.key.keysym.sym )
                {


                    case SDLK_q:
                        Qtru = true;
                        break;
                    case SDLK_p:
                        Ptru = true;
                        break;
                    case SDLK_w:
                        Wtru = true;
                        break;

                    case SDLK_e:
                        Etru = true;
                        break;
                    case SDLK_r:
                        Rtru = true;
                        break;
                    case SDLK_t:
                        Ttru = true;
                        break;
                    case SDLK_y:
                        Ytru = true;
                        break;
                    case SDLK_u:
                        Utru = true;
                        break;
                    case SDLK_i:
                        Itru = true;
                        break;
                    case SDLK_o:
                        Otru = true;
                        break;
                    case SDLK_f:
                        Ftru = true;
                        break;
                    case SDLK_g:
                        Gtru = true;
                        break;
                    case SDLK_h:
                        Htru = true;
                        break;
                    case SDLK_j:
                        Jtru = true;
                        break;
                    case SDLK_k:
                        Ktru = true;
                        break;
                    case SDLK_l:
                        Ltru = true;
                        break;
                    case SDLK_v:
                        Vtru = true;
                        break;
                    case SDLK_b:
                        Btru = true;
                        break;
                    case SDLK_n:
                        Ntru = true;
                        break;
                    case SDLK_m:
                        Mtru = true;
                        break;



                    case SDLK_a:
                        Atru = true;
                        break;
                    case SDLK_s:
                        Stru = true;
                        break;
                    case SDLK_d:
                        Dtru = true;
                        break;
                    case SDLK_SPACE:
                        SPACEtru = true;
                        break;
                    case SDLK_z:
                        Ztru = true;
                        break;
                    case SDLK_x:
                        Xtru = true;
                        break;
                    case SDLK_c:
                        Ctru = true;
                        break;

                    case SDLK_LEFT:
                        LEFTtru = true;
                        break;
                    case SDLK_RIGHT:
                        RIGHTtru = true;
                        break;
                    case SDLK_UP:
                        UPtru = true;
                        break;
                    case SDLK_DOWN:
                        DOWNtru = true;
                        break;
                    case SDLK_1:
                        NUM1tru = true;
                        break;
                    case SDLK_2:
                        NUM2tru = true;
                        break;
                    case SDLK_3:
                        NUM3tru = true;
                        break;
                    case SDLK_4:
                        NUM4tru = true;
                        break;
                    case SDLK_5:
                        NUM5tru = true;
                        break;
                    case SDLK_6:
                        NUM6tru = true;
                        break;
                    case SDLK_7:
                        NUM7tru = true;
                        break;
                    case SDLK_8:
                        NUM8tru = true;
                        break;
                    case SDLK_9:
                        NUM9tru = true;
                        break;
                    case SDLK_0:
                        NUM0tru = true;
                        break;
                    default:
                        break;
                }
                break;

                case SDL_KEYUP:
                      switch( Event0.key.keysym.sym ){
                    case SDLK_LEFT:
                        /* We check to make sure the alien is moving */
                        /* to the left. If it is then we zero the    */
                        /* velocity. If the alien is moving to the   */
                        /* right then the right key is still press   */
                        /* so we don't tocuh the velocity            */
                        LEFTtru = false;
                        break;
                    case SDLK_RIGHT:
                        RIGHTtru = false;
                        break;
                    case SDLK_UP:
                        UPtru = false;
                        break;
                    case SDLK_DOWN:
                        DOWNtru = false;
                        break;


                    case SDLK_e:
                        Etru = false;
                        break;
                    case SDLK_r:
                        Rtru = false;
                        break;
                    case SDLK_t:
                        Ttru = false;
                        break;
                    case SDLK_y:
                        Ytru = false;
                        break;
                    case SDLK_u:
                        Utru = false;
                        break;
                    case SDLK_i:
                        Itru = false;
                        break;
                    case SDLK_o:
                        Otru = false;
                        break;
                    case SDLK_f:
                        Ftru = false;
                        break;
                    case SDLK_g:
                        Gtru = false;
                        break;
                    case SDLK_h:
                        Htru = false;
                        break;
                    case SDLK_j:
                        Jtru = false;
                        break;
                    case SDLK_k:
                        Ktru = false;
                        break;
                    case SDLK_l:
                        Ltru = false;
                        break;
                    case SDLK_v:
                        Vtru = false;
                        break;
                    case SDLK_b:
                        Btru = false;
                        break;
                    case SDLK_n:
                        Ntru = false;
                        break;
                    case SDLK_m:
                        Mtru = false;
                        break;


                    case SDLK_q:
                        Qtru = false;
                        break;
                    case SDLK_p:
                        Ptru = false;
                        break;
                    case SDLK_w:
                        Wtru = false;
                        break;
                    case SDLK_a:
                        Atru = false;
                        break;
                    case SDLK_s:
                        Stru = false;
                        break;
                    case SDLK_d:
                        Dtru = false;
                        break;
                    case SDLK_SPACE:
                        SPACEtru = false;
                        break;
                    case SDLK_z:
                        Ztru = false;
                        break;
                    case SDLK_x:
                        Xtru = false;
                        break;
                    case SDLK_c:
                        Ctru = false;
                        break;
                    case SDLK_1:
                        NUM1tru = false;
                        break;
                    case SDLK_2:
                        NUM2tru = false;
                        break;
                    case SDLK_3:
                        NUM3tru = false;
                        break;
                    case SDLK_4:
                        NUM4tru = false;
                        break;
                    case SDLK_5:
                        NUM5tru = false;
                        break;
                    case SDLK_6:
                        NUM6tru = false;
                        break;
                    case SDLK_7:
                        NUM7tru = false;
                        break;
                    case SDLK_8:
                        NUM8tru = false;
                        break;
                    case SDLK_9:
                        NUM9tru = false;
                        break;
                    case SDLK_0:
                        NUM0tru = false;
                        break;
                    default:
                        break;
                }
                break;

            default:
                break;
            }
        }
    }

    bool input::Quit()
    {   //it needs to flip it because this bool will be used by running witch is true when it is flipped.
        if(quit)
            return false;
        else
            return true;
    }
    bool input::Qispressed() //Q
    {
        return Qtru;
    }
    bool input::Wispressed() //W
    {
        return Wtru;
    }
    bool input::Eispressed() //E
    {
        return Etru;
    }
    bool input::Rispressed() //R
    {
        return Rtru;
    }
    bool input::Tispressed() //T
    {
        return Ttru;
    }
    bool input::Yispressed() //Y
    {
        return Ytru;
    }
    bool input::Uispressed() //U
    {
        return Utru;
    }
    bool input::Iispressed() //I
    {
        return Itru;
    }
    bool input::Oispressed() //O
    {
        return Otru;
    }
    bool input::Pispressed() //P
    {
        return Ptru;
    }
    bool input::Aispressed() //A
    {
        return Atru;
    }
    bool input::Sispressed() //S
    {
        return Stru;
    }
    bool input::Dispressed() //D
    {
        return Dtru;
    }
    bool input::Fispressed() //F
    {
        return Ftru;
    }
    bool input::Gispressed() //G
    {
        return Gtru;
    }
    bool input::Hispressed() //H
    {
        return Htru;
    }
    bool input::Jispressed() //J
    {
        return Jtru;
    }
    bool input::Kispressed() //K
    {
        return Ktru;
    }
    bool input::Lispressed() //L
    {
        return Ltru;
    }
    bool input::Zispressed() //Z
    {
        return Ztru;
    }
    bool input::Xispressed() //X
    {
        return Xtru;
    }
    bool input::Cispressed() //C
    {
        return Ctru;
    }
    bool input::Vispressed() //V
    {
        return Vtru;
    }
    bool input::Bispressed() //B
    {
        return Btru;
    }
    bool input::Nispressed() //N
    {
        return Ntru;
    }
    bool input::Mispressed() //M
    {
        return Mtru;
    }

    bool input::UPispressed() //UP
    {
        return UPtru;
    }
    bool input::DOWNispressed() //DOWN
    {
        return DOWNtru;
    }
    bool input::LEFTispressed() //LEFT
    {
        return LEFTtru;
    }
    bool input::RIGHTispressed() //RIGHT
    {
        return RIGHTtru;
    }
    bool input::SPACEispressed() //Space
    {
        return SPACEtru;
    }
    bool input::NUM0ispressed() //0
    {
        return NUM0tru;
    }
    bool input::NUM1ispressed() //1
    {
        return NUM1tru;
    }
    bool input::NUM2ispressed() //2
    {
        return NUM2tru;
    }
    bool input::NUM3ispressed() //3
    {
        return NUM3tru;
    }
    bool input::NUM4ispressed() //4
    {
        return NUM4tru;
    }
    bool input::NUM5ispressed() //5
    {
        return NUM5tru;
    }
    bool input::NUM6ispressed() //6
    {
        return NUM6tru;
    }
    bool input::NUM7ispressed() //7
    {
        return NUM7tru;
    }
    bool input::NUM8ispressed() //8
    {
        return NUM8tru;
    }
    bool input::NUM9ispressed() //9
    {
        return NUM9tru;
    }
    bool input::LCPressed() //LEFTCLICK
    {
        return LCTru;
    }
    bool input::RCPressed() //RIGHTCLICK
    {
        return RCTru;
    }
    bool input::MCPressed() //MIDDLECLICK
    {
        return MCTru;
    }
    bool input::GetWheelDown()
    {
        return MouseWheelDown;
    }
    bool input::GetWheelUp()
    {
        return MouseWheelUP;
    }

//////////////////////////////////////////////////////////////////
    int input::GetxFOROFFSET(int Lastlock)
    {
        if(MoveMemoryX != mousex)
        {
            int Change = MoveMemoryX - mousex;
            MoveMemoryX = mousex;
            Change = Change * -1;
            if(Change < 500 )//|| Change > -500)
            return (Change);
            else
                return 0;
        }
        if(MoveMemoryX == mousex)
        return 0;
    }
    int input::GetyFOROFFSET(int Lastlock)
    {
         if(MoveMemoryY != mousex)
        {
            int Change = MoveMemoryY - mousey;
            MoveMemoryY = mousey;
            Change = Change * -1;
            if(Change < 500 )//|| Change > -500)
            return Change;
            else
                return 0;
        }
        if(MoveMemoryY == mousey)
        return 0;
    }

    void input::ClearFORSET()
    {
        MoveMemoryX = mousex;
        MoveMemoryY = mousey;
    }


    bool input::MouseMovement()
    {
        if(MouseMOVEMENT)
        {
            MouseMOVEMENT = false;
            return true;
        }
        else if(!MouseMOVEMENT)
        {
            return false;
        }

    }








