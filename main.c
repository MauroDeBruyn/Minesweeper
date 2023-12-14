//Define Libraries
#include <stdio.h>
#include "minesweeperFunctions.h"
#include <stdint.h>

//Define special commands
#define clrscr() printf("\e[1;1H\e[2J")

int main(void)
{
  int menuChoice = 0;
  uint8_t chessboard[8][8] = {
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#'}};

  enum state {bootWelcome, mainMenu, loadUserGame, loadNewGame, gameOver, closeGame};
  enum state currentState = bootWelcome;

  while(1)
    {
      switch (currentState)
        {
        case bootWelcome:         //Welcome + game manual
          clrscr();
          loadingBar(3, 40);
          welcome();

          currentState = mainMenu;
          break;

        case mainMenu:         //asks user to load or start a new game (1 = load previous / 2 = start new)
          menuChoice = startMenu();

          switch (menuChoice)
          {
          case 1:
            currentState = loadUserGame;
            break;

          case 2:
            currentState = loadNewGame;
            break;

          case 3:
            currentState = closeGame;
            break;
          
          default:
            printf("Unexpected error occured");
            break;
          }

          break;

        case loadUserGame:         //Load game
          /*code*/
          currentState = gameOver;

          break;

        case loadNewGame:         //Load new game

          break;

        case closeGame:
          clrscr();
          printf("Closing terminal...");
          delay(3);

          exit(0);

        case gameOver:         //Game over screen
          printGameOver();

          currentState = mainMenu;
          break;

        default:
          printf("Unexpected error occured");

          break;
        }
    }
    return 0;
}
