//Define Libraries
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>

//Define special commands
#define clrscr() printf("\e[1;1H\e[2J")

void welcome();
void printLine();
void printGameOver();
void loadingBar(int seconds, int steps);
int startMenu();
void delay(int number_of_seconds);

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

printf("   _____                         __  __                         _ \n");
printf("  / ____|                       |  \\/  |                       | |\n");
printf(" | |  __  __ _ _ __ ___   ___   | \\  / | __ _ _ __  _   _  __ _| |\n");
printf(" | | |_ |/ _` | '_ ` _ \\ / _ \\  | |\\/| |/ _` | '_ \\| | | |/ _` | |\n");
printf(" | |__| | (_| | | | | | |  __/  | |  | | (_| | | | | |_| | (_| | |\n");
printf("  \\_____|\\__,_|_| |_| |_|\\___|  |_|  |_|\\__,_|_| |_|\\__,_|\\__,_|_|\n\n\n\n");
                                                                  
                                                                  

  printf("Game manual:\n\n\nTo win Minesweeper, you have to type in a coordinate.\n\nWhen given a coordinate, there will be numbers in the surrounding positions that indicate how many mines are the given coordinates surroudings.\n\nIf you type a coordinate with a mine underneath, it will be game over.\n\n\n\n\n\n");
  printf("Press ENTER to continue...\n\n");

  getchar();

  clrscr();
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

void loadingBar(int seconds, int steps) //Loading screen
{
    int i, j;
    for (i = 0; i < steps; ++i) {
        printf("[");
        for (j = 0; j < i; ++j) {
            printf("=");
        }
        for (; j < steps; ++j) {
            printf(" ");
        }
        printf("] %d%%\r", (i * 100) / steps);
        fflush(stdout);
        usleep((seconds * 1000000) / steps); // Sleep to control the speed
    }
    printf("\n");
    clrscr();
}

int startMenu() //Asks user to load new or previous game
{
    int userInput;
    do {
      clrscr();

      printf("   _____ _                                        _   _            \n");
      printf("  / ____| |                                      | | (_)            \n");
      printf(" | |    | |__   ___   ___  ___  ___    ___  _ __ | |_ _  ___  _ __  \n");
      printf(" | |    | '_ \\ / _ \\ / _ \\/ __|/ _ \\  / _ \\| '_ \\| __| |/ _ \\| '_ \\ \n");
      printf(" | |____| | | | (_) | (_) \\__ \\  __/ | (_) | |_) | |_| | (_) | | | |\n");
      printf("  \\_____|_| |_|\\___/ \\___/|___/\\___|  \\___/| .__/ \\__|_|\\___/|_| |_|\n");
      printf("                                           | |                      \n");
      printf("                                           |_|                      \n"); 

      printf("\n1. Load game\n2. Start new game\n3. Exit minesweeper\n");

      scanf("%d", &userInput);
        while (getchar() != '\n');  // Clear the input buffer
    } while (userInput != 1 && userInput != 2 && userInput != 3);

    switch (userInput) {
        case 1:
            clrscr();
            printf("Loading game:\n");
            loadingBar(1, 40);

            break;

        case 2:
            clrscr();
            printf("Loding new game:\n");
            loadingBar(1, 40);

        case 3:
            break;

        default:
            printf("Error\n");
            break;
    }
    

    return userInput;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}