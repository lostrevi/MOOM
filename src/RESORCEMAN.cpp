#include "RESORCEMAN.h"

void RESORCEMAN::init(SDL_Renderer *Ren0)
{
    RenA = Ren0;
    Add_Texture("Boom","Data/Boom.png");
    Add_Texture("Shot","Data/Shot.png");
    Add_Texture("BlastShip","Data/BlastShip.png");
    Add_Texture("PlayerShip","Data/P_SHIP.png");
    Add_Texture("Buzzer","Data/Buzzer.png");
    Add_Texture("LazyGround","Data/Lazyground.png");
    Add_Texture("Powerup","Data/Powerup.png");
    Add_Texture("MeshGuard","Data/MeshGuard.png");

    //for(int i = 0; i < Textures.size(); i++)
    //{
    //    std::cout << "size of : " << Textures_T[i] << "  | size : " << sizeof(Textures[i]) << " \n";
    //}

}

void RESORCEMAN::Add_Texture(std::string Name, std::string PATH)
{
    SDL_Texture* TEMP = loadTexture(PATH);

    Textures.push_back(TEMP);
    Textures_T.push_back(Name);
}

SDL_Texture* RESORCEMAN::Get_Texture(int index)
{
    if(index > Textures.size() || index < 0)
        std::cout << "WARRNING! RESORCEMAN.cpp Get_Texture(int index) might be calling a null value."
        << " Make sure that anything that uses this methoid is not calling out of range\n";

    return Textures[index];
}

void RESORCEMAN::List_texture_index()
{
    std::cout << "List of Loaded Textures :\n\n" << std::endl;
    for(int i = 0; i < Textures.size(); i++)
    {
        if(i > 9)
        std::cout << i << " ";
        else
        std::cout << i << "  ";

        std::cout << Textures_T[i] << "\n";
    }
}



SDL_Texture* RESORCEMAN::loadTexture(std::string path)
{
            //The final texture
            SDL_Texture* newTexture = NULL;

            //Load image at specified path
            SDL_Surface* loadedSurface = IMG_Load( path.c_str() );


            if( loadedSurface == NULL )
            {
                std::cout <<  "Unable to load image" << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
            }
            else
            {
                //Create texture from surface pixels
                newTexture = SDL_CreateTextureFromSurface( RenA, loadedSurface );
                if( newTexture == NULL )
                {
                    std::cout << "Unable to create texture from" <<  path << "! SDL Error: " << SDL_GetError() << std::endl;
                }

                //Get rid of old loaded surface
                SDL_FreeSurface( loadedSurface );
            }

            return newTexture;
}
