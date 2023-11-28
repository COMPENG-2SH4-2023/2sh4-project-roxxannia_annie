#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFoodRef);
        ~Player();
        // Upgrade this in iteration 3.
        // void getPlayerPos(objPos &returnPos); 
        objPosArrayList* getPlayerPos();
        
        void updatePlayerDir();
        void movePlayer(objPos foodPos);

        bool checkFoodConsumption(objPos headPos, objPos foodPos);
        void increasePlayerLength();
        bool checkSelfCollision();

    private:
        // Upgrade this in iteration 3. 
        // objPos playerPos;   
              
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* mainGameFood;
        objPosArrayList* playerPosList;
};

#endif