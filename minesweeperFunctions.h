//Define Libraries
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>
#include <stdint.h>

//Define special commands
#define clrscr() printf("\e[1;1H\e[2J") //Clears the consol

void welcome(); //Welcome screen and game manual
void printLine(); //Prints a line
void printGameOver(); //Prints game over
void loadingBar(int seconds, int steps); //Loading screen
int startMenu(); //Prints the main menu
void delay(int number_of_seconds); //Delay in seconds
void printMinefield(void); //prints the minefield for the user
void makeMineField(uint8_t userPrefferedMines); //Fills minefield with bombs
uint8_t userCoordinate(void); //Asks user for coordinate, when typed save the game will be saved
void saveGame(void); //Save game
void floodfill(void);

//Array minefield
uint8_t hiddenMineField[8][8]={0};//Fill field with zero's
uint8_t userField[8][8] = { //Userfield
    {35, 35, 35, 35, 35, 35, 35, 35},
    {35, 35, 35, 35, 35, 35, 35, 35},
    {35, 35, 35, 35, 35, 35, 35, 35},
    {35, 35, 35, 35, 35, 35, 35, 35},
    {35, 35, 35, 35, 35, 35, 35, 35},
    {35, 35, 35, 35, 35, 35, 35, 35},
    {35, 35, 35, 35, 35, 35, 35, 35},
    {35, 35, 35, 35, 35, 35, 35, 35}
};

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
printf("  \\_____|\\__,_|_| |_| |_|\\___|  |_|  |_|\\__,_|_| |_|\\__,_|\\__,_|_|\n\n\n");
                                                                  
                                                                  

  printf("To win Minesweeper, you have to type in a coordinate.\n\nWhen given a coordinate, there will be numbers in the surrounding positions that indicate how many mines are the given coordinates surroudings.\n\nIf you type a coordinate with a mine underneath, it will be game over.\n\n\n\n\n\n");
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

  printf("\n\nThe given coordinate contained a mine!\n\n");
  delay(3);
  printf("Returning to main menu...");
  delay(3);
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
            loadingBar(1, 10);

            break;

        case 2:
            clrscr();
            printf("Loding new game:\n");
            loadingBar(1, 10);

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

void makeMineField(uint8_t userPrefferedMines)
{
    uint8_t xAs = 0;
    uint8_t yAs = 0;
    uint8_t counter = 0;

        if (userPrefferedMines > 64)//sets the maximum input of mines
    {
        printf("Error: The maximum number of mines is 64. Setting mines to 64.\n");
        userPrefferedMines = 63;
    }

     for (int i = 0; i < 8; ++i) //clear the field and set it to 0
     {
        for (int j = 0; j < 8; ++j)
        {
            hiddenMineField[i][j] = 0;
        }
    }

    //Keep generating mines until the user precified amount of mines are in the field
    while (counter <= userPrefferedMines)
    {
        xAs = rand()%8; //generate random number between 0-7
        yAs = rand()%8; //generate random number between 0-7

        if(hiddenMineField[xAs][yAs] == 0) //Check if the coordinate contains a mine
        {
            hiddenMineField[xAs][yAs] = 1; //Place mine
            counter++;
        }
    }
    
}

void printMinefield(void) //Prints the field for the user
{
    printf("   A   B   C   D   E   F   G   H\n");
    printf(" +---+---+---+---+---+---+---+---+\n");

    for(int i = 0; i < 8; i++)
    {
        printf("%d|", i+1);

        for(int j = 0; j < 8; j++)
        {
            if(userField[i][j]==35)
            {
                printf(" %c |",userField[i][j]);
            }

            else
            {
                printf(" %d |",userField[i][j]);
            }
        }
        printf("\n");
    }
    printf(" +---+---+---+---+---+---+---+---+\n");
}

uint8_t userCoordinate(void)
{
    char userInput[10];
    int row; // Initialize to an invalid value
    int colum; // Initialize to an invalid value
    int c;

    memset(userInput, 0, sizeof(userInput)); //Empty buffer

    printf("Type a coordinate or type 'save' to save the game:\n");

    if (scanf("%9s", userInput) != 1)
    {
        printf("Error reading user input.\n");
    }

    while ((c = getchar()) != '\n' && c != EOF);//clear buffer
    clrscr();

    userInput[strlen(userInput) - 1] = '\0'; //\n is being removed

        for(int i = 0; i < strlen(userInput); i++)
    {
        if(isupper(userInput[i]) == 0) //Makes the whole string uppercase
        {
            userInput[i] = toupper(userInput[i]);
        }
    }

    // Check for save game
    if (strcmp("SAVE", userInput) == 0)
    {
        saveGame();
        return 1; // Indicate that the user saved the game
    }

    // Extract row and column outside the loop
    if (isalpha(userInput[0]))
    {
        colum = userInput[0] - 'A';
    }

    if (isdigit(userInput[1]))
    {
        row = atoi(&userInput[1]) - 1;
    }

    // Validate row and column values
    if (row < 0 || row >= 8 || colum < 0 || colum >= 8)
    {
        //clrscr();
        printf("Invalid coordinates. Please try again.\n");
        return 0; // Indicate that the user entered invalid coordinates
    }

    if (hiddenMineField[row][colum] == 1)
    {
        return 2; // Indicate that the user hit a mine
    }
    else
    {
        floodfill();
        return 0; // Indicate successful move
    }
}


void saveGame(void) //Save game
{

}

void floodfill(void)
{

}