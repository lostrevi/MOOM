#include "Enemy.h"

void Enemy::init(SDL_Renderer *Ren0, SDL_Texture *Texture, pos _LOC, MAP *MapPointer, char type)
{
    Type = type;
    RenA = Ren0;
    Ship_Texture = Texture;
    LOC = _LOC;
    Map_Pointer = MapPointer;

    LOC_SHIP.x = LOC.x;
    LOC_SHIP.y = LOC.y;
}
void Enemy::update()
{

}


void Enemy::draw()
{
    if(!dead)
        SDL_RenderCopy(RenA,Ship_Texture,NULL,&LOC_SHIP);

    //SDL_SetRenderDrawColor(RenA, 255,0,0,255);
    //SDL_RenderDrawRect(RenA,&HIT_SHIP);
}

void Enemy::initShip()
{
    std::cout << "Wrong call!. This is the base class.\n";
}



/*
doing somthing like this or the first on on this site || https://stackoverflow.com/questions/18223036/i-want-a-vector-of-derived-class-pointers-as-base-class-pointers

You can do what you really want to do with no problems at all! That is, simply do:

class Animal {
   public:
      std::string GetNoise() const = 0;
};
class Dog : public Animal {
   public:
      std::string GetNoise() const { return "Bark!"; }
};
class Cat : public Animal {
   public:
      std::string GetNoise() const { return "Meow"; }
      bool        LikesSleeping() const { return true; }
};

Dog* d = new Dog;
Cat* c = new Cat;
vector<Animal*> all_animals;
all_animals.push_back(d, c);

// then, later...

// this will print "Bark!"
std::cout << all_animals[0]->GetNoise() std::endl;

// if you know the type somehow
Cat* x = dynamic_cast<Cat*>(all_animals[1]);
const bool y = x->LikesSleeping();
The reason that your code didn't work the way you expect is that: std::vector<Dog*> is a totally different class from std::vector<Animal*>.

In other words, Dog inherits from Animal, yes, but a std::vector<X> does not inherit from std::vector<Y> -- no matter how X and Y are related!

Templates don't give the vector much intelligence; they just define a new class. You can think of it this way:

class vectorOfDogs {
    Dog* myDogs;
    //...
}

class vectorOfAnimals {
    Animal* myAnimals;
    //...
}
Does vectorOfDogs inhert from vectorOfAnimals? Clearly not! But all that's been done is changing the name of the class from std::vector<Dog*> to vectorOfDogs.

*/
