#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic    

    //this input should be from the GameMechs
    switch(mainGameMechsRef->getInput())
    {
        case 'w':
        case 'W':
            if(myDir != UP && myDir != DOWN)
            {
                myDir = UP;
            }
            break;
        case 's':
        case 'S':
            if(myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
            break;
        case 'a':
        case 'A':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;

        case 'd':
        case 'D':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = RIGHT;
            }
            break;

        case ' ':
            myDir = STOP;
            mainGameMechsRef->setExitTrue();
            break;
        default:
            break;
    }   
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch ((myDir))
    {
        case UP:
            playerPos.y--;
            if(playerPos.y <=0)
            {
                playerPos.y = mainGameMechsRef->getBoardSizeY()-2;
            }
            break;
        case DOWN:
            playerPos.y++;
            if(playerPos.y >= mainGameMechsRef->getBoardSizeY())
            {
                playerPos.y = 1;
            }
            break;
        case LEFT:
            playerPos.x--;
            if(playerPos.x <= 0)
            {
                playerPos.x = mainGameMechsRef->getBoardSizeX()-2;
            }
            break;
        case RIGHT:
            playerPos.x++;
            if(playerPos.x >= mainGameMechsRef->getBoardSizeX())
            {
                playerPos.x = 1;
            }            
        case STOP:
        default:
            break;
    }
}

