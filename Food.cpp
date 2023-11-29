#include "Food.h"
#include "MacUILib.h"
#include <iostream>
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

Food::Food(GameMechs* thisGMRef) // using the same guidelines as player.cpp
{
    mainGameMechsRef = thisGMRef;
    foodPos.setObjPos(-1, -1, 'o'); //initialize foodPos outside game board
    // bonus 
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

    // while(true)
    // {
    //     int x = mainGameMechsRef->getBoardSizeX();
    //     int y = mainGameMechsRef->getBoardSizeY();


    //     xPos = (rand() %  (x - 2)) + 1;
    //     yPos = (rand() %  (y - 2)) + 1;

    // // validate

    //     // if(xPos != blockOff.x && yPos != blockOff.y)
    //     // {
    //     //     foodPos.setObjPos(xPos,yPos,'o');
    //     //     break;
    //     // }

       
    // }

    // bonus 


    // for (int i = 0; i < 5; i++)
    // {
    //     do
    //     {
    //         int x = mainGameMechsRef->getBoardSizeX();
    //         int y = mainGameMechsRef->getBoardSizeY();

    //         xPos = (rand() % (x - 2)) + 1;
    //         yPos = (rand() % (y - 2)) + 1;

    //     } while (xPos == blockOff.x && yPos == blockOff.y);

    //     foodPos.setObjPos(xPos, yPos, 'o');

    //     objPos foodItem;
    //     foodItem.setObjPos(xPos, yPos, 'o');
    //     foodBucket->insertTail(foodItem);
    // }

    int numSpecialFood = 0;

    while (numSpecialFood < 2)
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

        // Determine the symbol based on the count
        char symbol = (numSpecialFood < 2) ? '$' : 'o';

        // Set the food position
        // foodPos.setObjPos(xPos, yPos, symbol);

        // Create a new food item and insert it into the bucket
        // objPos foodItem;
        // foodItem.setObjPos(xPos, yPos, symbol);
        // foodBucket->insertTail(foodItem);
        objPos foodItem{xPos, yPos, '$'};
        // foodItem.setObjPos(xPos, yPos, symbol);
        foodBucket->insertHead(foodItem);
        

        // Increment the count of special food items
        numSpecialFood++;
    }

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

        // Set the food position
        // foodPos.setObjPos(xPos, yPos, 'o');

        // Create a new food item and insert it into the bucket
        // objPos foodItem;
        // foodItem.setObjPos(xPos, yPos, 'o');
        // foodBucket->insertTail(foodItem);
        objPos foodItem{xPos, yPos, 'o'};
        // foodItem.setObjPos(xPos, yPos, symbol);
        foodBucket->insertHead(foodItem);
        // foodBucket->removeHead();
    }

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


// debugging key -- REMOVE LATER
    // generating new food position O pressed


// void Food::updateFood()
// {
//     char input = mainGameMechsRef->getInput();

//     switch(input)
//     {
//         case 'o':
//             generateFood(foodPos);
//             break;
//     }
// }


// bonus 
objPosArrayList* Food::getFoodBucket()
{
    return foodBucket;
}