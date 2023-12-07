//Define Libraries
#include <stdio.h>

//Define special commands
#define clrscr() printf("\e[1;1H\e[2J")

void welcome();
void printLine();
void printGameOver();

void welcome() // Welcomes you to the game, and prints game manual.
{
  printf(" _    _      _\n");
  printf("| |  | |    | |\n");
  printf("| |  | | ___| | ___ ___  _ __ ___   ___\n");
  printf("| |/\\| |/ _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\\n");
  printf("\\  /\\  /  __/ | (_| (_) | | | | | |  __/\n");
  printf(" \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|\n\n\n");

  printf(" _____\n");
  printf("|_   _|\n");
  printf("  | | ___\n");
  printf("  | |/ _ \\\n");
  printf("  | | (_) |\n");
  printf("  \\_/\\___/\n\n\n");

  printf("___  ____\n");
  printf("|  \\/  (_)\n");
  printf("| .  . |_ _ __   ___  _____      _____  ___ _ __   ___ _ __\n");
  printf("| |\\/| | | '_ \\ / _ \\/ __\\ \\ /\\ / / _ \\/ _ \\ '_ \\ / _ \\ ""'__|\n");
  printf("| |  | | | | | |  __/\\__ \\  V  V /  __/  __/ |_) |  __/ |\n");
  printf("\\_|  |_/_|_| |_|\\___||___/ \\_/\\_/ \\___|\\___| .__/ \\___|_|\n");
  printf("                                           | |\n");
  printf("                                           |_|\n");

  printLine();

  printf("Press ENTER to continue...\n\n");
  getchar();

  clrscr();

  printf("Game manual:\n\n\nTo win Minesweeper, you have to type in a coordinate.\n\nWhen given a coordinate, there will be numbers in the surrounding positions that indicate how many mines are the given coordinates surroudings.\n\nIf you type a coordinate with a mine underneath, it will be game over.\n\n\n\n\n\n");
  printf("Press ENTER to continue...\n\n");
}

void printLine() // Prints a line
{
  printf("_____________________________________________________________________________\n\n");
}

void printGameOver() // Prints "Game Over"
{
  clrscr();

  printf(" _____   ___  ___  ___ _____   _____  _   _ ___________\n");
  printf("|  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | |  ___| ___ \\\n");
  printf("| |  \\// /_\\ \\| .  . || |__   | | | || | | | |__ | |_/ /\n");
  printf("| | __ |  _  || |\\/| ||  __|  | | | || | | |  __||    /\n");
  printf("| |_\\ \\| | | || |  | || |___  \\ \\_/ /\\ \\_/ / |___| |\\ \\ \n");
  printf(" \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/\\____/\\_| \\_| \n");

  printf("\n\nThe given coordinate contained a mine!");
}
