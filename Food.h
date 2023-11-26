#ifndef FOOD_H
#define FOOD_H

#include <cstdlib> //provides srand() and rand()
#include <time.h> //provides time

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h" 

using namespace std;


class Food
{
    private:
        objPos foodPos; 
        GameMechs* mainGameMechsRef;

        int **myFood; //heap data members

    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
        void updateFood();



    
};


#endif