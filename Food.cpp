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

void Food::generateFood(objPosArrayList* playerPos)
{
    srand(time(NULL));

    int xPos;
    int yPos;
    int k = 0;

    while (k < 5)
    {
        int x = mainGameMechsRef->getBoardSizeX();
        int y = mainGameMechsRef->getBoardSizeY();

        xPos = (rand() % (x - 2)) + 1;
        yPos = (rand() % (y - 2)) + 1;

        bool collidesWithPlayer = false;

        for (int i = 0; i < playerPos->getSize(); i++)
        {
            objPos tempPos;
            playerPos->getElement(tempPos, i);
            if (xPos == tempPos.x && yPos == tempPos.y)
            {
                collidesWithPlayer = true;
                break;
            }
        }

        if (!collidesWithPlayer) 
        {
        char symbol;
        if (k < 2) {
            symbol = '$';
        } else {
            symbol = 'o';
        }

        objPos foodItem{xPos, yPos, symbol};
        foodBucket->insertHead(foodItem);
        k++;
    }

    }

    // remove excess items from the bucket
    while (foodBucket->getSize() > 5)
    {
        foodBucket->removeTail();
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