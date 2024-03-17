/*
- Programmer: Kai Schenkel
- Class: SD-247 Computer Architecture
- Data: 3/17/2024
- Project 4: C Terminal
- Sources: Book from class: Computer Systems, Bro code on Youtube and Geeks for Geeks
- Objective: The objective of this assignment is to reinforce your understanding of basic C programming concepts 
    and to enhance your skills in handling input/output operations, string manipulation, and command execution.
- Task: You are required to develop a simple terminal application in C that mimics the basic functionalities of a standard terminal
     found in most operating systems. Your terminal should be capable of accepting user input, parsing commands, and executing them accordingly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Need a Function that is for (pwd) Print Working Directory this will prints the full pathname of the current working directory

//Need a Function for (ls) List without any arguments this will list the files and directories in the current directory



//The Main where all thing run from
int main () 
{
    //The array of char that make or great String 
    char incomeing_Argument[100];
    
    while (1)
    {   
        printf("[]=========================================[]\n");
        printf("[]  Hello this is my Terminal Menu where   []\n");
        printf("[]  You can run commands like get the      []\n");
        printf("[]  List or or Print Working Directory     []\n");
        printf("[]  or Encryption or Decryption of a file  []\n");
        printf("[]=========================================[]\n");
        //Show that computer is waiting for prompt
        printf(">> "); 
        
        //Read the users input 
        fgets(incomeing_Argument, sizeof(incomeing_Argument), stdin);

        //Remove the new line character 
        incomeing_Argument[strcspn(incomeing_Argument, "\n")] = 0;

        if (strcmp(incomeing_Argument, "exit") == 0 || strcmp(incomeing_Argument, "quit") == 0)
        {
            //Breck out of the while loop so we are not here for ever
            break;
        }
        
    }
    

    return 0;
}