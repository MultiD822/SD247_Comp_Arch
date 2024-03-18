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
#include <unistd.h>
#include <time.h>

//Help Function that print out all the Commond
// printf("[] Enter (COMMOND) ______________________________________________ []\n");
void help_Function(){
    printf("[]================================================================[]\n");
    printf("[] Enter (math) to then add two numbers and get there sum back    []\n");
    printf("[] Enter (pwd) ______________________________________________ []\n");
    printf("[] Enter (ls) ______________________________________________ []\n");
    printf("[] Enter (COMMOND) ______________________________________________ []\n");
    printf("[] Enter (COMMOND) ______________________________________________ []\n");
    printf("[] Enter (COMMOND) ______________________________________________ []\n");
    printf("[]================================================================[]\n");
}

//Need a Math function so if the user want to some number calutaion
void calculation_Factory()
{
    int a, b;
    printf("Enter two numbers separated by a space; ");
    scanf("%d %d", &a, &b);
    printf("Sum: %d\n", a + b);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* code */
    }
    
}
//Need a Function that is for (pwd) Print Working Directory this will prints the full pathname of the current working directory
void print_Working_Directory(){
    char current_Working_Directory[1024];
    if (getcwd(current_Working_Directory, sizeof(current_Working_Directory)) != NULL) {
        printf("Current working directory: %s\n", current_Working_Directory);
    } else {
        perror("getcwd() error");
    }
    
}
//Need a Function for (ls) List without any arguments this will list the files and directories in the current directory
void list_Files() {
    system("ls");
}

//Excute a commond 
void excute_Command(char* incomeing_Argument){
    if(strcmp(incomeing_Argument, "math") == 0){
        calculation_Factory();
    } else if (strcmp(incomeing_Argument, "help") == 0){
        help_Function();
    }
    
}

//The Main where all thing run from
int main () 
{
    //The array of char that make or great String 
    char incomeing_Argument[100];

    printf("[]=========================================[]\n");
    printf("[]  Hello this is my Terminal Menu where   []\n");
    printf("[]  You can run commands like get the      []\n");
    printf("[]  List or or Print Working Directory     []\n");
    printf("[]  or Encryption or Decryption of a file  []\n");
    printf("[]=========================================[]\n");


    while (1) //Start of the loop might change the 1 into the perment var
    {   
        
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
        excute_Command(incomeing_Argument);
    }
    

    return 0;
}