//Define Libraries
#include <stdio.h>
#include "minesweeperFunctions.h"
#include <stdint.h>
#include <stdint.h>

//Define special commands
#define clrscr() printf("\e[1;1H\e[2J")

int main(void)
{
  //Declarations
  int menuChoice = 0;
  int userPrefferedMines = 0;
  uint8_t gameEnd = 0;

  uint8_t chessboard[8][8] = {
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'}}; //Declare empty hidden minefield

  enum state {bootWelcome, mainMenu, loadUserGame, loadNewGame, gameOver, closeGame}; //Declare states
  enum state currentState = bootWelcome; //Assign states

  while(1)
    {
      switch (currentState)
        {
        case bootWelcome: //Welcome + game manual
          clrscr();
          loadingBar(3, 15);
          welcome();

          currentState = mainMenu;
          break;

        case mainMenu: //asks user to load, start a new game or close the terminal
          menuChoice = startMenu();

          switch (menuChoice)
          {
          case 1:
            currentState = loadUserGame; //Load saved game
            break;

          case 2:
            currentState = loadNewGame; //Load new game
            break;

          case 3:
            currentState = closeGame; //close terminal
            break;
          
          default:
            printf("Unexpected error occured");
            break;
          }

          break;

        case loadUserGame: //Load game
          /*code*/
          currentState = gameOver;

          break;

        case loadNewGame: //Load new game

          userPrefferedMines = 0;

          printf("How many bombs would you like to place in the minefield?\n");
          scanf("%d", &userPrefferedMines);
          makeMineField(userPrefferedMines);
          clrscr();

          while(gameEnd == 0)
          {
            printMinefield();
            gameEnd = userCoordinate();
           
          }

          currentState = gameOver;
          gameEnd = 0;

          break;

        case closeGame:
          clrscr();
          printf("Closing terminal...");
          delay(3);

          exit(0);

        case gameOver: //Gameover screen
          printGameOver();

          currentState = mainMenu;
          break;

        default: //Unexpected state
          printf("Unexpected error occured");

          break;
        }
    }
    return 0;
}
