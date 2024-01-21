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
    int guessingNumber;
    int guessMade;

    srand(time(0));
    guessingNumber = (rand() % MAX) + MIN;
    printf("%d", guessingNumber);
    return 0;
}