#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include <time.h>

using namespace std;

#define DELAY_CONST 100000

//Global scope
GameMechs* myGM;
Player* myPlayer;
Food* myFood;

objPos boardPos;

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
    myPlayer->getPlayerPos(playPos);
    myFood->generateFood(playPos);
}

void GetInput(void)
{
    
    
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    
    myFood->updateFood();

    // input not repeatedly processed
    myGM->clearInput(); 
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    objPos tempPos; 
    myPlayer->getPlayerPos(tempPos);//get the player pos.

    objPos foodPos;
    myFood->getFoodPos(foodPos);

    // dimy is rows; dimx is columns
    for (int i = 0; i < myGM->getBoardSizeY(); i++) // rows
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++) // columns
        {
            // print player
            if (i == tempPos.y && j == tempPos.x)
            {
                // gameBoard[i][j] = player.symbol;
                MacUILib_printf("%c", tempPos.symbol);
            }
            // print food
            else if (i == foodPos.y && j == foodPos.x)
            {
                // gameBoard[i][j] = 'O';
                MacUILib_printf("%c", foodPos.symbol);
            }
            else if (i == 0 || i == myGM->getBoardSizeY() - 1 ||j == 0 || j == myGM->getBoardSizeX() - 1)
            {
                boardPos.setObjPos(j,i,'#');
                MacUILib_printf("%c", boardPos.symbol);

            }
            else
            {
                boardPos.setObjPos(j,i,' ');;
                MacUILib_printf("%c", boardPos.symbol);
            }
            // MacUILib_printf("%c", gameBoard[i][j]);

        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Player Score: %d\n", myGM->getScore());
    // MacUILib_printf("Player Direction\n", moveCnt);
    MacUILib_printf("Press spacebar to exit the game!\n");

    // debugging -- REMOVE
    // MacUILib_printf("Food Coordinates: (%d, %d)\n", foodPos.x, foodPos.y);
    // MacUILib_printf("Food Symbol: %c\n", foodPos.symbol);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
