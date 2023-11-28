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
}

Food::~Food()
{
    // delete[] myFood;
}

void Food::generateFood(objPos blockOff)
{
    srand(time(NULL));

    int xPos;
    int yPos;

    while(true)
    {
        int x = mainGameMechsRef->getBoardSizeX();
        int y = mainGameMechsRef->getBoardSizeY();


        xPos = (rand() %  (x - 2)) + 1;
        yPos = (rand() %  (y - 2)) + 1;

    // validate

        if(xPos != blockOff.x && yPos != blockOff.y)
        {
            // foodPos.x = xPos;
            // foodPos.y = yPos;
            // foodPos.symbol = 'o';
            foodPos.setObjPos(xPos,yPos,'o');
            break;
        }
    }

}
    

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);
}


// debugging key -- REMOVE LATER
    // generating new food position O pressed


void Food::updateFood()
{
    char input = mainGameMechsRef->getInput();

    switch(input)
    {
        case 'o':
            generateFood(foodPos);
            break;
    }


}
    