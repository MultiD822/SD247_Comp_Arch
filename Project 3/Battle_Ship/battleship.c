
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
/*
- Programmer: Kai Schenkel
- Class: SD-247 Computer Architecture
- Data: 2/21/2024
- Project 3: Implementing Battleship in C
- Sources: Book from class: Computer Systems, Bro code on Youtube and Geeks for Geeks
- Objective: This program is a simple implementation of the game Battleship. The game is played on a 10x10 grid. 
    The game is played between the user and the computer. The user will place their ships on the board and then the computer will place their ships on the board. 
    The user will then take a turn and guess where the computer's ships are. The computer will then take a turn and guess where the user's ships are. 
    The game will continue until all the ships are sunk. The game will then display who won the game.
*/
#define BOARD_SIZE 10
#define NUM_SHIPS 5
#define SHIP_LENGTHS{5, 4, 3, 3, 2}

typedef struct
{
  int x;
  int y;
} Coordinate;

typedef struct
{
  Coordinate start;
  Coordinate end;
  int length;
  bool isSunk;
} Ship;

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
  // initialize the board
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      board[i][j] = '.';
    }
  }
}
void printEdge()
{
  printf("[]===|===|===|===|===|===|===|===|===|===[]\n");
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
  // display the board
  //printEdge();
  printEdge();
  printf("[] A | B | C | D | E | F | G | H | I | J []\n");
  printEdge();
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("[]");
    for (int j = 0; j < BOARD_SIZE; j++){
      if (j < 9){
        printf(" %c |", board[i][j]);
      } else {
        printf(" %c ", board[i][j]);
      }
    }
    printf("[]\n");
  }
  printEdge();
}

bool isValidPlacement(char board[BOARD_SIZE][BOARD_SIZE], Ship shipToPlace, char shipDirection)
{
  // logic to check if a ship placement is valid
  //If the ship overlaps with another ship then return false
  //If the ship is not horizontal or vertical then return false
  //If the ship is not the correct length then return false
  //If the ship placement is not valid then return false
  if (shipToPlace.start.x < 0 || shipToPlace.start.x >= BOARD_SIZE || shipToPlace.start.y < 0 || shipToPlace.start.y >= BOARD_SIZE){
    return false;
  }
  //If the ship is horizontal then we need to check if the ship is going off the board
  if (shipDirection == 'H') {
    if(shipToPlace.start.x + shipToPlace.length > BOARD_SIZE){
      return false; //ship is going off the board
      //Then we need to check if the ship will over lap with another ship
      for (int i = 0; i < shipToPlace.length; i++){
        if(board[shipToPlace.start.x][shipToPlace.start.y] != 0){
        return false; //overlapping
        }
      }
    }
  } else if (shipDirection == 'V') {
    if(shipToPlace.start.y + shipToPlace.length > BOARD_SIZE){
      return false; //ship is going off the board
      //Then we need to check if the ship will over lap with another ship
      for (int i = 0; i < shipToPlace.length; i++){
        if(board[shipToPlace.start.x][shipToPlace.start.y] != 0){
        return false; //overlapping
        }
      }
    }

  } else {
    return false; //ship is not horizontal or vertical
  }
  
  return true;
}

bool isValidGuess(char board[BOARD_SIZE][BOARD_SIZE], Coordinate guess)
{
  // check if the guess is valid placement on the game board
  //the guess corrdinate x needs to be greater than or equal to 0 and less than the board size
  //And the same thing for the y coordinate
  if (guess.x >= 0 && guess.x < BOARD_SIZE && guess.y >= 0 && guess.y < BOARD_SIZE)
  {
    return true;
  }
  return false;
}

void placeShips(char board[BOARD_SIZE][BOARD_SIZE], Ship ships[]){
  // place the ship on the board
  //We need to place the ship on the board by setting the start and end coordinates to 'S'
  //When we hit the start and end coordinates we need to check if the ship is horizontal or vertical
  //If the ship is horizontal then we need to set the start x coordinate to 'S' and the end x coordinate to 'S'
  //If the ship is vertical then we need to set the start y coordinate to 'S' and the end y coordinate to 'S'
  
  for (int shipIndex = 0; shipIndex < NUM_SHIPS; shipIndex++) {
    displayBoard(board);
    printf("Placing ship %d of length %d\n", shipIndex + 1, ships[shipIndex].length);
    // Ask the user for the orientation of the ship
    printf("Do you want to place the ship horizontally or vertically? (Enter 'H' for Horizontal, 'V' for Vertical):\n");
    char orientation;
    scanf(" %c", &orientation);
        
    // Ask the user for the starting coordinate of the ship
    printf("Enter the starting coordinate for the ship (x y): \n");
    scanf(" %d", &ships[shipIndex].start.x);
    scanf (" %d", &ships[shipIndex].start.y);

    // Check if the placement is valid
    if (isValidPlacement(board, ships[shipIndex], orientation)) {
            // Place the ship on the board
            if (orientation == 'V') {
                for (int i = 0; i < ships[shipIndex].length; i++) {
                    board[ships[shipIndex].start.x + i][ships[shipIndex].start.y] = 'S';
                }
            } else { // 'V'
                for (int i = 0; i < ships[shipIndex].length; i++) {
                    board[ships[shipIndex].start.x][ships[shipIndex].start.y + i] = 'S';
                }
            }
            printf("Ship placed.\n");
    } else {
      printf("Invalid placement. Please try again.\n");
      shipIndex--; // Decrement the index to retry
    }
  }
}

//Place Ships randomly
void placeShipsRandomly(char board[BOARD_SIZE][BOARD_SIZE], Ship ships[]) {
    srand(time(NULL)); // Seed the random number generator

    for (int shipIndex = 0; shipIndex < NUM_SHIPS; shipIndex++) {
        bool placed = false;
        while (!placed) {
            // Randomly choose orientation
            char orientation = rand() % 2 == 0 ? 'H' : 'V';
            // Randomly choose starting coordinates
            if (orientation == 'H') {
                ships[shipIndex].start.x = rand() % (BOARD_SIZE - ships[shipIndex].length + 1);
                ships[shipIndex].start.y = rand() % BOARD_SIZE;
            } else { // 'V'
                ships[shipIndex].start.x = rand() % BOARD_SIZE;
                ships[shipIndex].start.y = rand() % (BOARD_SIZE - ships[shipIndex].length + 1);
            }

            // Check if the placement is valid
            if (isValidPlacement(board, ships[shipIndex], orientation)) {
                // Place the ship on the board
                for (int i = 0; i < ships[shipIndex].length; i++) {
                    if (orientation == 'H') {
                        board[ships[shipIndex].start.x + i][ships[shipIndex].start.y] = 'S';
                    } else { // 'V'
                        board[ships[shipIndex].start.x][ships[shipIndex].start.y + i] = 'S';
                    }
                }
                placed = true;
            }
        }
    }
}



void initializeShips(Ship ships[]) {
  // initialize the ships
  //We need to initialize the ships by setting the start and end coordinates to 0
  //We also need to set the length of the ship
  //We also need to set the ship to not sunk

  for (int i = 0; i < NUM_SHIPS; i++)
  {
    ships[i].start.x = 0;
    ships[i].start.y = 0;
    ships[i].end.x = 0;
    ships[i].end.y = 0;
    ships[i].isSunk = false;
  }
  //We need to set the length of the ships
  for (int i = 0; i < NUM_SHIPS; i++)
  {
    if (i == 0)
    {
      ships[i].length = 5;
    }
    else if (i == 1)
    {
      ships[i].length = 4;
    }
    else if (i == 2)
    {
      ships[i].length = 3;
    }
    else if (i == 3)
    {
      ships[i].length = 3;
    }
    else if (i == 4)
    {
      ships[i].length = 2;
    }
  }
}


bool isHit(char board[BOARD_SIZE][BOARD_SIZE], Coordinate guess)
{
  // check if the guess is a hit
  if (board[guess.x][guess.y] == 'H' || board[guess.x][guess.y] == 'S'){
    return true;
  }
  return false;  
}

bool isSunk(char board[BOARD_SIZE][BOARD_SIZE], Ship ship){
  // check if the ship is sunk
  if (ship.start.x == ship.end.x){
    for(int y = ship.start.y; y <= ship.end.y; y++){
      if(board[ship.start.x][y] != 'H'){  //If any part of the ship is not hit
        return false;
      }
    }
  } else if (ship.start.y == ship.end.y){
    for(int x = ship.start.x; x <= ship.end.x; x++){
      if(board[x][ship.start.y] != 'H'){  //If any part of the ship is not hit
        return false;
      }
    }
  }
  return true;
}

void takeTurn(char shipBoard[BOARD_SIZE][BOARD_SIZE], char guessingBoard[BOARD_SIZE][BOARD_SIZE],  Ship ships[], bool isUserTurn)
{
  // logic for a turn (user or computer)
  //If it is the user's turn then we need to ask the user for a guess
  //If the user's guess is a hit then we need to set the board to 'H'
  //If the user's guess is a miss then we need to set the board to 'O'
  //If the user's guess is a hit then we need to check if the ship is sunk
  //If the ship is sunk then we need to set the ship to sunk
  //If it is the computer's turn then we need to generate a random guess, if it is a hit do the samw thing as the user's turn
  Coordinate guess;
  if (isUserTurn) {
    printf("Enter your guess (ex. 2 , 5): ");
    scanf(" %d", &guess.x);
    scanf(" %d", &guess.y);
    if(!isValidGuess(shipBoard, guess)){
      printf("Invalid guess\n");
      return;
    }
  } else {
    guess.x = rand() % BOARD_SIZE;
    guess.y = rand() % BOARD_SIZE;
  }

  // Check if the guess is a hit or miss
    if (shipBoard[guess.x][guess.y] == 'S') { 
        printf("%s\n", isUserTurn ? "Hit!" : "The computer hits!");
        guessingBoard[guess.x][guess.y] = 'H'; // Mark hit on the guessing board
        shipBoard[guess.x][guess.y] = 'H'; 
        // Check if the ship is sunk
        for (int i = 0; i < NUM_SHIPS; i++) {
            if (ships[i].start.x <= guess.x && ships[i].end.x >= guess.x && ships[i].start.y <= guess.y && ships[i].end.y >= guess.y) {
                if (isSunk(shipBoard, ships[i])) {
                    ships[i].isSunk = true;
                    printf("%s\n", isUserTurn ? "You sunk a ship!" : "The computer sunk your ship!");
                }
            }
        }
        
    } else {
        printf("%s\n", isUserTurn ? "Miss." : "The computer misses.");
        guessingBoard[guess.x][guess.y] = 'O'; // Mark miss on the guessing board
    }

}

bool isGameOver(Ship ships[NUM_SHIPS])
{
  // is the game over?
  //Game is over when all the ships are sunk so we need to check if all the ships are sunk
  //If all the ships are sunk then the game is over and we return true
  int shipsSunk = 0;

  for (int i = 0; i < NUM_SHIPS; i++)
  {
    if (ships[i].isSunk == true)
    {
      shipsSunk++;
    }
  }
  //If the number of ships sunk is equal to the number of ships then the game is over
  if (shipsSunk == NUM_SHIPS)
  {
    return true;
  } else {
    return false;
  }
}

void printMenu()
{
  // print the menu
  printf("Welcome to Battleship\n");
  printf("1. Play Game\n");
  printf("2. Quit\n");
}



int main()
{
  // Initialize the game board
  char plays_Ship_Board[BOARD_SIZE][BOARD_SIZE];
  char players_Guess_Board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(plays_Ship_Board);
    initializeBoard(players_Guess_Board);
  char computers_Ship_Board[BOARD_SIZE][BOARD_SIZE];
  char computers_Guess_Board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(computers_Ship_Board);
    initializeBoard(computers_Guess_Board);
   

    // Define and initialize ships
    Ship playerShips[NUM_SHIPS];
    initializeShips(playerShips); 

    Ship computerShips[NUM_SHIPS];
    initializeShips(computerShips); 
    
    printMenu();
    int choice;
    scanf(" %d", &choice);
    if (choice == 2)
    {
      return 0;
    }
    // Place ships on the board
    placeShips(plays_Ship_Board, playerShips);
    // Place ships on the board for the computer
    placeShipsRandomly(computers_Ship_Board, computerShips);
  
    // Main game loop
    bool gameRunning = true;
    while (gameRunning) {
    // Player's turn: Make a guess against the computer's ships
    displayBoard(players_Guess_Board);
    displayBoard(plays_Ship_Board);
    takeTurn(computers_Ship_Board, players_Guess_Board, playerShips, true);
    
    // Check for game over condition after each turn
    if (isGameOver(playerShips)) {
        printf("Player wins!\n");
        gameRunning = false;
        break;
    }
    printf("Computer's turn: \n");
    // Computer's turn: Implement logic for the computer to make a guess against the player's ships
    takeTurn(plays_Ship_Board, computers_Guess_Board, computerShips, false);

    // Again, check for game over condition
    if (isGameOver(computerShips)) {
        printf("Computer wins!\n");
        gameRunning = false;
    }
}


    return 0;
}
