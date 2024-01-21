/*
- Programmer: Kai Schenkel
- Class: SD-247 Computer Architecture
- Data: 1/21/2024
- Project 1: Introduction to C / Guessing Game 
- Sources: KS_GuessingGame.java, Book from class: Computer Systems
- Objective: This C program is meant to be a Guess the Number game, where our program will generate a random number between a explicit range like 1 to 100.
    Then the play will make a guess and see if it matchs the random number set by the computer.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int MIN = 1;
    const int MAX = 100;
    //difficultyLevel()
    int guessCounter;
    int guessingNumber;
    int guessMade;

    srand(time(0));
    guessingNumber = (rand() % MAX) + MIN;
    
    do{
        printf("Enter a Guess \t");
        scanf("%d", &guessMade);
        if (guessMade > guessingNumber)
        {
            /* code */
            printf("to big\n");
            printf("Your Guess made is great than the random number\n");
        }
        else if (guessMade < guessingNumber)
        {
            /* code */
            printf("to small\n");
            printf("Your Guess made is less than the random number\n");
        }
        else {
            printf("Your got the right Number good Job!\n");
        }
        guessCounter++;
    }while (guessMade != guessingNumber);
    printf("[]=======================[]\n");
    printf("[] Guessing Number: %d   []\n", guessingNumber);
    printf("[] Guessing Number: %d    []\n", guessCounter);
    printf("[]=======================[]\n");

    return 0;
}