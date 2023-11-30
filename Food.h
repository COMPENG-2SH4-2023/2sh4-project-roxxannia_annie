#ifndef FOOD_H
#define FOOD_H
// provides srand() and rand()
#include <cstdlib> 
// provides time
#include <time.h> 

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h" 

using namespace std;

class Food
{
    private:
        objPos foodPos; 
        GameMechs* mainGameMechsRef;
        //heap data members
        int **myFood; 
        // bonus
        objPosArrayList* foodBucket;


    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
        // bonus
        objPosArrayList *getFoodBucket();
};


#endif