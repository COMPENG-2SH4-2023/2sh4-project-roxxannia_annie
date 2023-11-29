#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include "Player.h"
#include "Food.h"
#include <time.h>

using namespace std;

#define DELAY_CONST 100000

//Global scope
GameMechs* myGM;
Player* myPlayer;
Food* myFood;
objPosArrayList* playerPosition;

// objPos boardPos;

// bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(DIMX, DIMY); //make board size
    myPlayer = new Player(myGM);

    // food generation
    myFood = new Food(myGM);

    objPos playPos;
    objPos foodPos;
    // myPlayer->getPlayerPos(playPos);
    myPlayer->getPlayerPos();
    myFood->generateFood(playPos);


    // bonus - generate five food items
    // for (int i = 0; i < 5; i++)
    // {
    //     objPos playPos;
    //     myPlayer->getPlayerPos();
    //     myFood->generateFood(playPos);
    // }

}

void GetInput(void)
{
    
    
}

void RunLogic(void)
{   
    objPos tempFood;
    myFood->getFoodPos(tempFood);

    myPlayer->updatePlayerDir();
    myPlayer->movePlayer(myFood);
    


    // myFood->updateFood();

    // input not repeatedly processed
    myGM->clearInput(); 

}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    
    //get the player pos. --> not used anymore after iteration 3
    // playerPosition = myPlayer->getPlayerPos();

    // objPos foodPos;
    // myFood->getFoodPos(foodPos);

    objPosArrayList* myPlayerList = myPlayer->getPlayerPos();
    objPosArrayList* foodBucket = myFood->getFoodBucket();

    objPos headPos;
    myPlayerList->getHeadElement(headPos);


    objPos bodyPos;

    // dimy is rows; dimx is columns
    for (int i = 0; i < myGM->getBoardSizeY(); i++) // rows
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++) // columns
        {
            // print player
            //print player in a loop 
            bool snakePrint = true;
            for (int k = 0; k<myPlayerList->getSize(); k++)
            {
                myPlayerList->getElement(bodyPos,k);
                if (bodyPos.y == i && bodyPos.x == j)
                {
                    MacUILib_printf("%c", bodyPos.symbol);
                    snakePrint = false; // havent finished printing
                    break;
                }
            }

            if(!snakePrint)
                continue;
            

            // print food
            // if (i == foodPos.y && j == foodPos.x)
            // {
            //     // gameBoard[i][j] = 'O';
            //     MacUILib_printf("%c", foodPos.symbol);
            // }
            bool foodPrint = true;
            
            for (int k = 0; k < foodBucket->getSize(); k++)
            {
                foodBucket->getElement(bodyPos, k);
                if (bodyPos.y == i && bodyPos.x == j)
                {
                    MacUILib_printf("%c", bodyPos.symbol);
                    foodPrint = false;
                    break;
                }
            }

            if (!foodPrint)
                continue;

            
            if (i == 0 || i == myGM->getBoardSizeY() - 1 ||j == 0 || j == myGM->getBoardSizeX() - 1)
            {
                // boardPos.setObjPos(j,i,'#');
                MacUILib_printf("%c", '#');

            }
            else
            {
                // boardPos.setObjPos(j,i,' ');;
                MacUILib_printf("%c", ' ');
            }
            // MacUILib_printf("%c", gameBoard[i][j]);

        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Player Score: %d\n", myGM->getScore());
    MacUILib_printf("Snake Length %d\n", myPlayerList->getSize());
    MacUILib_printf("Press spacebar to exit the game!\n");

    // debugging -- REMOVE
    // MacUILib_printf("Food Coordinates: (%d, %d)\n", foodPos.x, foodPos.y);
    // MacUILib_printf("Food Symbol: %c\n", foodPos.symbol);
    // MacUILib_printf("collision: %d\n", myPlayer->checkFoodConsumption(headPos, foodBucket ));

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    

    if(myGM->getLoseFlagStatus() == true)
    {
        MacUILib_clearScreen(); 
        MacUILib_printf("You have consumed yourself :( it's a suicide");
        MacUILib_uninit();
    }
    else if (myGM->getLoseFlagStatus() == false)
    {
        MacUILib_printf("Your final score is %d", myGM->getScore());
        MacUILib_uninit();
    }
  
    
}
