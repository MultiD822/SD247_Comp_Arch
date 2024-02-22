#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
/*

*/
#define BOARD_SIZE 10
#define NUM_SHIPS 5
#define SHIP_LENGTHS \
  {                  \
    5, 4, 3, 3, 2    \
  }

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
  // print the edge of the board
  char wall = '=';
  printf("[]");
  for (int i = 0; i < 20; i++)
  {
    printf("%c", wall);
  }
  printf("[]\n");
}
void displayBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
  // display the board
  //printEdge();
  printf("[]===|===|===|===|===|===|===|===|===|===[]\n");
  printf("[] A | B | C | D | E | F | G | H | I | J []\n");
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
  printf("[]===|===|===|===|===|===|===|===|===|===[]\n");
}

bool isValidPlacement(char board[BOARD_SIZE][BOARD_SIZE], Ship shipToPlace, Coordinate start, Coordinate end)
{
  // logic to check if a ship placement is valid
  //If the ship overlaps with another ship then return false
  //If the ship is not horizontal or vertical then return false
  //If the ship is not the correct length then return false
  //If the ship placement is not valid then return false

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

void placeShip(char board[BOARD_SIZE][BOARD_SIZE])
{
  
  // place the ship on the board
  //We need to place the ship on the board by setting the start and end coordinates to 'S'
  //When we hit the start and end coordinates we need to check if the ship is horizontal or vertical
  //If the ship is horizontal then we need to set the start x coordinate to 'S' and the end x coordinate to 'S'
  //If the ship is vertical then we need to set the start y coordinate to 'S' and the end y coordinate to 'S'
  Ship ship;
  printf("Which ship do you want to place?\n");
  printf("1. Carrier (5)\n");
  printf("2. Battleship (4)\n");
  printf("3. Cruiser (3)\n");
  printf("4. Submarine (3)\n");
  printf("5. Destroyer (2)\n");
  int shipChoice;
  scanf("%d", &shipChoice);
  switch (shipChoice){
    case 1:
      ship.length = 5;
      break;
    case 2:
      ship.length = 4;
      break;
    case 3:
      ship.length = 3;
      break;
    case 4:
      ship.length = 3;
      break;
    case 5:
      ship.length = 2;
      break;

    default:
      printf("Invalid choice\n");
      char stillWantToPlay;
      printf("Do you still want to play? (Y/N)\n");
      scanf("%c", &stillWantToPlay);
      if (stillWantToPlay == 'N')
      {
        exit(0);
      }
      break;
  }
  //Now we ask the user if they want to place the ship horizontally or vertically
  printf("Do you want to place the ship horizontally or vertically?\n");

  

  printf("Enter 'H' for Horizontal\n");
  printf("Enter 'V' for Vertical\n");
  char playChoice;
    scanf("%c", &playChoice);

  switch (playChoice){
    case 'H':
      //If the ship is horizontal then we need to set the start x coordinate to 'S' and the end x coordinate to 'S'
      printf("Enter the start x coordinate\n");
      scanf("%d", &ship.start.x);
      printf("Enter the end x coordinate\n");
      scanf("%d", &ship.end.x);
      for (int i = ship.start.x; i < ship.end.x; i++)
      {
        board[i][ship.start.y] = 'S';
      }
      printf("The ship has been placed\n");
      break;
    case 'V':
      //If the ship is vertical then we need to set the start y coordinate to 'S' and the end y coordinate to 'S'
      printf("Enter the start y coordinate\n");
      scanf("%d", &ship.start.y);
      printf("Enter the end y coordinate\n");
      scanf("%d", &ship.end.y);

      for (int i = ship.start.y; i < ship.end.y; i++)
      {
        board[ship.start.x][i] = 'S';
      }
      break;

    default:
      printf("Invalid choice\n");
      char stillWantToPlay;
      printf("Do you still want to play? (Y/N)\n");
      scanf("%c", &stillWantToPlay);
      if (stillWantToPlay == 'N')
      {
        exit(0);
      }
      break;
  }
}

bool isHit(char board[BOARD_SIZE][BOARD_SIZE], Coordinate guess)
{
  // check if the guess is a hit
  if (board[guess.x][guess.y] == 'H')
  {
    return true;
  }
  return false;  
}

bool isSunk(char board[BOARD_SIZE][BOARD_SIZE], Ship ship)
{
  // check if the ship is sunk
  if (ship.isSunk == true)
  {
    return true;
  }
  return false;
}

void takeTurn(char board[BOARD_SIZE][BOARD_SIZE], Ship ships[NUM_SHIPS], bool isUserTurn)
{
  // logic for a turn (user or computer)
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
  // some main code
  char board[BOARD_SIZE][BOARD_SIZE];
  initializeBoard(board);
  displayBoard(board);
  placeShip(board);
  displayBoard(board);
}
