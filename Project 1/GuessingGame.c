/*
- Programmer: Kai Schenkel
- Class: SD-247 Computer Architecture
- Data: 1/21/2024
- Project 1: Introduction to C / Guessing Game 
- Sources: KS_GuessingGame.java, Book from class: Computer Systems, Bro code on Youtube and Geeks for Geeks
- Objective: This C program is meant to be a Guess the Number game, where our program will generate a random number between a explicit range like 1 to 100.
    Then the play will make a guess and see if it matchs the random number set by the computer.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int MIN = 1;
    gameIntro();
    int MAX = difficultyLevel();
    int guessCounter;
    int guessingNumber;
    int guessMade;

    srand(time(0));
    guessingNumber = (rand() % MAX) + MIN;
    
    do{
        printf("[]===============[]\n");
        printf("[] Enter a Guess []\n");
        printf("[]===============[]\n");
        printf("Guess ->  ");
        scanf("%d", &guessMade); 
        
        printf("\n");
        if (guessMade > guessingNumber)
        {
            /* code */
            printf("[]====================================================[]\n");
            printf("[] The guess you made is great than the random number []\n");
            printf("[]====================================================[]\n");
            printf("\n");
        }
        else if (guessMade < guessingNumber)
        {
            /* code */
            printf("[]===================================================[]\n");
            printf("[] The guess you made is less than the random number []\n");
            printf("[]===================================================[]\n");
            printf("\n");
        }
        else {
            printf("[]===================================================[]\n");
            printf("[] Your got the right Number good Job!               []\n");
            printf("[]===================================================[]\n");
            printf("\n");
        }
        guessCounter++;
    }while (guessMade != guessingNumber);
    printf("[]=======================[]\n");
    printf("[] Guessing Number: %d   []\n", guessingNumber);
    printf("[] Guessing Number: %d   []\n", guessCounter);
    printf("[]=======================[]\n");

    return 0;
}

int difficultyLevel() {
    char difficultyInput;
    int MAX;
    printf("[]==============================================================================================[]\n");
    printf("[] Enter the Difficulty Level you wish to play with: (E) for Easy, (M) for Medium, (H) for Hard []\n");
    printf("[]==============================================================================================[]\n");
    printf("Select ->  ");
    scanf("%c", &difficultyInput);
    difficultyInput = toupper(difficultyInput);
    switch (difficultyInput)
    {
    case 'E'/* Easy difficulty */:
        /* code */
        MAX = 100;
        break;
    
    case 'M'/* Medium difficulty */:
        /* code */
        MAX = 200;
        break;

    case 'H'/* Hard difficulty */:
        /* code */
        MAX = 300;
        break;    
    default:
        break;
    }
    return MAX;
}

void gameIntro() {
    printf("[]==========================================================================[]\n");
    printf("[] Wellcome to the Nubmer Guessing Game, The computer will grenert a random []\n");
    printf("[] number from 1 to the level of difficulty that you will select from.      []\n");
    printf("[] Easy is 1 to 100, Medium is 1 to 200, and Hard is 1 to 300               []\n");
    printf("[]==========================================================================[]\n");
    printf("\n");
}