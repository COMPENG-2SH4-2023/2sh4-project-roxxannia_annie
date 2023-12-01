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
    char symbol;
    int k = 0;
    int flag =0;

    // bonus - create special $ food item and insert it into bucket
    while(k<5)
    {
        if(k<2)
        {
            int x = mainGameMechsRef->getBoardSizeX();
            int y = mainGameMechsRef->getBoardSizeY();

            xPos = (rand() % (x - 2)) + 1;
            yPos = (rand() % (y - 2)) + 1;

            // for (int i = 0; i < 2; i++)
            // {
            //     // check if the position is the same as the blockOff
            //      if (xPos == blockOff.x && yPos == blockOff.y)
            //     {
            //         flag = 1;
            //         break;
            //     }
            // }

            for(int i = 0; i<playerPos->getSize(); i++)
            {
                objPos tempPos;
                playerPos->getElement(tempPos, i);
                if (xPos == tempPos.x && yPos == tempPos.y)
                {
                    flag = 1;
                    break;
                }
                  
            }
        
            if (flag !=1)
            {
                objPos foodItem{xPos, yPos, '$'};
                foodBucket->insertHead(foodItem); 
                k++;
            }
        }    


        else
        {

            int x = mainGameMechsRef->getBoardSizeX();
            int y = mainGameMechsRef->getBoardSizeY();

            xPos = (rand() % (x - 2)) + 1;
            yPos = (rand() % (y - 2)) + 1;

            // for (int i = 0; i < 2; i++)
            // {
            //     // check if the position is the same as the blockOff
            //      if (xPos == blockOff.x && yPos == blockOff.y)
            //     {
            //         flag = 1;
            //         break;
            //     }
            // }

            for(int i = 0; i<playerPos->getSize(); i++)
            {
                objPos tempPos;
                playerPos->getElement(tempPos, i);
                if (xPos == tempPos.x && yPos == tempPos.y)
                {
                    flag = 1;
                    break;
                }
                  
            }
        
            if (flag !=1)
            {
                objPos foodItem{xPos, yPos, 'o'};
                foodBucket->insertHead(foodItem); 
                k++;
            }
        } 
    }
            
    // generating normal food items
    //     for (int i = 2; i < 5; i++)
    //     {
    //         int x = mainGameMechsRef->getBoardSizeX();
    //         int y = mainGameMechsRef->getBoardSizeY();

    //         xPos = (rand() % (x - 2)) + 1;
    //         yPos = (rand() % (y - 2)) + 1;

    //         // Check if the position is the same as the blockOff
    //         if (xPos == blockOff.x && yPos == blockOff.y)
    //         {
    //             continue;
    //         }

    //         objPos foodItem{xPos, yPos, 'o'};
    //         foodBucket->insertHead(foodItem);
    //     }
    // }
    
    
    if (foodBucket->getSize()>5)
    {
        for (int i = 0; i < 5; i++)
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