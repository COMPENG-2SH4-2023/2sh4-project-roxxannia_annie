#include "GameMechs.h"
#include "MacUILib.h"



GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 20;
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
// did not use heap?
// will use when we do food
// GameMechs::~GameMechs()
// {

// }


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {

        input = MacUILib_getChar();
        // maybe dont need this line?
        
    }
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::incrementScore()
{
    score++;
}

// food generation functions
void GameMechs::generateFood(objPos blockOff)
{

    int item_drawn = 1; // No item generated yet


    do {
        item_drawn = 0;
        foodPos.x = (rand() % (boardSizeX - 2)) + 1; // range to edge of game board
        foodPos.y = (rand() % (boardSizeY - 2)) + 1; // range to edge of game board

        // check if the generated item's coordinates overlap with player
        if (foodPos.x == blockOff.x && foodPos.y == blockOff.y) 
        {
            item_drawn = 1;
        }

    } while (item_drawn); // repeat if an item has been drawn at this position

    foodPos.setObjPossetObjPos(foodPos.x, foodPos.y, 'O');

}


void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos;
}