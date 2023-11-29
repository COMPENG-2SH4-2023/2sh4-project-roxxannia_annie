#include "Player.h"
#include <iostream>
#include "Food.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    // mainGameFood = thisFoodRef;
    myDir = STOP;

    // more actions to be included
//    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@');
    playerPosList = new objPosArrayList();
    objPos newPos{mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*'};
    playerPosList->insertHead(newPos);

}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}



int Player::checkFoodConsumption(objPos headPos, objPosArrayList* foodBucket)
{
    // cout << "HeadPos: (" << headPos.x << ", " << headPos.y << "), FoodPos: (" << foodPos.x << ", " << foodPos.y << ")" << endl;

    // if (headPos.x == foodPos.x && headPos.y == foodPos.y)
    // {
    //     // cout << true << endl;
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    objPos foodPos;

    int score = 0;

    // bonus 
    for (int i = 0; i < foodBucket->getSize(); i++)
    {
        foodBucket->getElement(foodPos, i);

        if (headPos.x == foodPos.x && headPos.y == foodPos.y && foodPos.symbol == '$')
        {
           score = 5;
        //    foodPos.setObjPos(-1, -1, ' '); 
           break;
            
            // Remove consumed food
            // return 1;
        }
        else if (headPos.x == foodPos.x && headPos.y == foodPos.y && foodPos.symbol == 'o')
        {
           score = 1;
        //    foodPos.setObjPos(-1, -1, ' '); 
           break;
            // Remove consumed food
            // return 1;
        }
        
    }
    return score; // no food consumed

}

void Player::increasePlayerLength()
{
    objPos increPos;
    playerPosList->getHeadElement(increPos);
    playerPosList->insertHead(increPos);
}

// bonus
// void Player::increasePlayerLength(int length)
// {
//     for (int i = 0; i < length; i++)
//     {
//         objPos increPos;
//         playerPosList->getHeadElement(increPos);
//         playerPosList->insertHead(increPos);
//     }
// }

bool Player::checkSelfCollision()
{
    // return false;
    objPos headPos;
    objPos colliPos;

    playerPosList->getHeadElement(headPos);

    for (int i = 1; i<playerPosList->getSize(); i++)
    {
        playerPosList->getElement(colliPos,i);
        if(headPos.x == colliPos.x && headPos.y == colliPos.y)
        {
            return true;
            
        }
    }
    return false;

}

objPosArrayList* Player::getPlayerPos()
{
    // returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    return playerPosList;
    // playerPosList->getHeadElement(playerPosList);
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

// void Player::movePlayer(Food* foodRef)
// {
//     // PPA3 Finite State Machine logic
//     //need to get x and y
//     objPos currPos;
//     playerPosList->getHeadElement(currPos);

//     objPos foodPos;
//     foodRef->getFoodPos(foodPos);

//     // tempPos.getObjPos(tempPos);
//     int newY = currPos.y;
//     int newX = currPos.x;
//     switch ((myDir))
//     {
//         case UP:
            
//             if(newY <= 1)
//             {
//                 newY = mainGameMechsRef->getBoardSizeY()-1;
//             }
//             newY--;
//             break;
//         case DOWN:
            
//             if(newY >= mainGameMechsRef->getBoardSizeY()-2)
//             {
//                 newY = 0;
//             }
//             newY++;
//             break;
//         case LEFT:
            
//             if(newX <= 1)
//             {
//                 newX = mainGameMechsRef->getBoardSizeX()-1;
//             }
//             newX--;
//             break;
//         case RIGHT:
            
//             if(newX >= mainGameMechsRef->getBoardSizeX()-2)
//             {
//                 newX = 0;
//             } 
//             newX++;
//             break;           
//         case STOP:
//         default:
//             break;
//     }

//     // objPos currPos{newX, newY, '*'};
//     objPos newPos{newX,newY,'*'};
    
//     objPos tempPos;

//     if (checkSelfCollision())
//     {
//         mainGameMechsRef->setLoseFlag();
//         mainGameMechsRef->setExitTrue();
//     }


//     if (checkFoodConsumption(newPos,foodPos))
//     {
//         // playerPosList->insertHead(newPos);
//         playerPosList->insertHead(newPos);
//         // increasePlayerLength();
//         mainGameMechsRef->incrementScore();
        
//         foodRef->generateFood(newPos);
//     }
//     else{
//         playerPosList->insertHead(newPos);
//         playerPosList->removeTail();
//     }
    
// }

// annie for bonus
void Player::movePlayer(Food* foodRef)
{
    // PPA3 Finite State Machine logic
    //need to get x and y
    objPos currPos;
    playerPosList->getHeadElement(currPos);

    // objPos foodPos;
    // foodRef->getFoodPos(foodPos);


    // additional features
    objPosArrayList* foodBucket = foodRef->getFoodBucket();
    // int foodType = checkFoodConsumption(currPos, foodBucket); 
    // either special or norm

    // tempPos.getObjPos(tempPos);
    int newY = currPos.y;
    int newX = currPos.x;
    switch ((myDir))
    {
        case UP:
            if(newY <= 1)
            {
                newY = mainGameMechsRef->getBoardSizeY()-1;
            }
            newY--;
            break;
        case DOWN:
            if(newY >= mainGameMechsRef->getBoardSizeY()-2)
            {
                newY = 0;
            }
            newY++;
            break;
        case LEFT:
            if(newX <= 1)
            {
                newX = mainGameMechsRef->getBoardSizeX()-1;
            }
            newX--;
            break;
        case RIGHT:
            if(newX >= mainGameMechsRef->getBoardSizeX()-2)
            {
                newX = 0;
            } 
            newX++;
            break;           
        case STOP:
        default:
            break;
    }

    // objPos currPos{newX, newY, '*'};
    objPos newPos{newX,newY,'*'};
    
    // objPos tempPos;

    if (checkSelfCollision())
    {
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }

    // cout << checkFoodConsumption(newPos,foodBucket) <<endl;
    // if (foodType > 0)
    if (checkFoodConsumption(newPos,foodBucket) == 1)
    {
        playerPosList->insertHead(newPos);
        // increasePlayerLength();
        mainGameMechsRef->incrementScore(1);
        foodRef->generateFood(newPos);
    }
    else if (checkFoodConsumption(newPos,foodBucket) == 5)
    {
        playerPosList->insertHead(newPos);
        playerPosList->removeTail();
        // increasePlayerLength();
        mainGameMechsRef->incrementScore(5);
        foodRef->generateFood(newPos);
    }
    else
    {
        playerPosList->insertHead(newPos);
        playerPosList->removeTail();
    }
    
}
