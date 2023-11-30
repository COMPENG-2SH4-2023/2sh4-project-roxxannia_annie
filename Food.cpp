#include "Food.h"
#include "MacUILib.h"
#include <iostream>
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

// using the same guidelines as player.cpp
Food::Food(GameMechs* thisGMRef) 
{
    mainGameMechsRef = thisGMRef;
    // initialize foodPos outside game board
    foodPos.setObjPos(-1, -1, 'o'); 
    // above and beyond storage for 5 food pieces
    foodBucket = new objPosArrayList();
}

Food::~Food()
{
    delete foodBucket;
}

void Food::generateFood(objPos blockOff)
{
    srand(time(NULL));

    int xPos;
    int yPos;
    char symbol;
    
    // bonus - create special $ food item and insert it into bucket
    for (int i = 0; i < 2; i++)
    {
        int x = mainGameMechsRef->getBoardSizeX();
        int y = mainGameMechsRef->getBoardSizeY();

        xPos = (rand() % (x - 2)) + 1;
        yPos = (rand() % (y - 2)) + 1;

        // check if the position is the same as the blockOff
        if (xPos == blockOff.x && yPos == blockOff.y)
        {
            continue;
        }

        objPos foodItem{xPos, yPos, '$'};
        foodBucket->insertHead(foodItem);        
    }
    // generating normal food items
    for (int i = 2; i < 5; i++)
    {
        int x = mainGameMechsRef->getBoardSizeX();
        int y = mainGameMechsRef->getBoardSizeY();

        xPos = (rand() % (x - 2)) + 1;
        yPos = (rand() % (y - 2)) + 1;

        // Check if the position is the same as the blockOff
        if (xPos == blockOff.x && yPos == blockOff.y)
        {
            continue;
        }

        objPos foodItem{xPos, yPos, 'o'};
        foodBucket->insertHead(foodItem);
    }
}
    

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);
}

// bonus 
objPosArrayList* Food::getFoodBucket()
{
    return foodBucket;
}