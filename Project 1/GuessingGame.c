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
    //Print intro
    gameIntro();

    //Setting the difficulty of the game
    int MAX = difficultyLevel();
    //Setting int vars to then have values stored in
    int guessCounter;
    int guessingNumber;
    int guessMade;

    //Making the random number to then guess on
    srand(time(0));
    guessingNumber = (rand() % MAX) + MIN;
    
    //This do while loop will always need at least one guess to be right and if it is not eqaul to the
    //Guessing number we do everything in the do scoop again
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
    //Setting a char var to be the input of the difficulty 
    char difficultyInput;
    int MAX;
    printf("[]==============================================================================================[]\n");
    printf("[] Enter the Difficulty Level you wish to play with: (E) for Easy, (M) for Medium, (H) for Hard []\n");
    printf("[]==============================================================================================[]\n");
    printf("Select ->  ");
    scanf("%c", &difficultyInput);
    //cast what ever char to be the upper case version of the char
    difficultyInput = toupper(difficultyInput);
    //Have this swtich case instead of a if else tower 
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
    printf("[] Then when you enter a guess the computer will tell you if your guess is  []\n");
    printf("[] less than or greater than the number you are trying to guess.            []\n");
    printf("[]==========================================================================[]\n");
    printf("\n");
}