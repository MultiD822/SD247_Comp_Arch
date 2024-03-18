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
#include <ctype.h>
#include <time.h>

int shift_Value = 3;

//Help Function that print out all the Commond
// printf("[] Enter (COMMOND) ______________________________________________ []\n");
void help_Function(){
    printf("[]===================================================================[]\n");
    printf("[] Enter (append) to add more text to the end of an existing file    []\n");
    printf("[] Enter (cls) to clear the terminal screen                          []\n");
    printf("[] Enter (encrypt) to encrypt a file using Caesar cipher             []\n");
    printf("[] Enter (decrypt) to decrypt a file encrypted with Caesar cipher    []\n");
    printf("[] Enter (math) to add two numbers and get their sum back            []\n");
    printf("[] Enter (pwd) to print the current working directory                []\n");
    printf("[] Enter (ls) to list files and directories in the current directory []\n");
    printf("[] Enter (rename) to change the name of a file                       []\n");
    printf("[] Enter (read) to display the contents of a file                    []\n");
    printf("[] Enter (time) show currnet time                                    []\n");
    printf("[] Enter (write) to create a new file or overwrite an existing one   []\n");
    printf("[] Enter (quit/exit) to exit the terminal application                []\n");
    printf("[]===================================================================[]\n");
}


//Append Function
void append_to_file() {
    char filename[1040];
    printf("Enter the file name to append to:\n");
    scanf("%99s", filename); // Limit input to avoid buffer overflow
    getchar(); // Consume the newline character left by scanf

    FILE *file = fopen(filename, "a"); // Open the file in append mode

    if (file == NULL) {
        printf("Failed to open file\n");
        return;
    }

    printf("Enter text to append. Enter ~ on a new line to stop.\n");
    
    int ch;
    while (1) {
        ch = getchar(); // Read a character

        if (ch == '~') {
            getchar(); // Consume the newline character after '~'
            break; // Exit the loop if '~' is entered
        }

        fputc(ch, file); // Append the character to the file
    }

    fclose(file); // Close the file
    printf("Content appended successfully.\n");
}

//Rename Funcnion
void rename_File() { 
    char file_Name[100];

    printf("Enter the file name to read from:\nEx: hello.txt\n\n");

    scanf("%99s", file_Name);
    while ((getchar()) != '\n'); // Clear the input buffer
    
    FILE *p = fopen(file_Name, "r");
    
    if (p == NULL) {
        printf("Failed to open file\n");
        return;
    }
    
    printf("File contents:\n");
    
    int ch;
    
    while ((ch = fgetc(p)) != EOF) { // Read until the end of file
        putchar(ch); // Print the character
    }
    
    fclose(p); // Close the file
}

//Need a funcion that will write to a file
void write_To_File() {
    char incoming_Text[100];
    printf("To write to a file use a file with .txt or any other extension to write\nEx: hello.txt\n\n");
    system("COLOR???");

    FILE *p;

    printf("Enter File Name to write to: ");
    scanf("%s", incoming_Text);

    p = fopen(incoming_Text, "w");

    fflush(stdin);

    printf("Enter ~ to exit from writing\n");
    printf("Start writing: \n");

    int ch = 0;

    while (ch != '~'){
        ch = getchar();

        if (ch != '~'){
            fputc(ch, p);
        }
    }

    fclose(p); // Close the file
}

//Read a file and print it to the terminal
void read_File() {
    char filename[100];
    printf("Enter the file name to read from:\nEx: hello.txt\n\n");
    
    scanf("%99s", filename); // Limit input to avoid buffer overflow
    
    while ((getchar()) != '\n'); // Clear the input buffer
    
    FILE *p = fopen(filename, "r");
    
    if (p == NULL) {
        printf("Failed to open file\n");
        return;
    }
    
    printf("File contents:\n");
    
    int ch;
    
    while ((ch = fgetc(p)) != EOF) { // Read until the end of file
        putchar(ch); // Print the character
    }
    
    fclose(p); // Close the file
}

//Need a clear function so we can claer the terminal 
void clear_Terminal() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

//Getting the time from the computer and display it
void show_Time(){
    // Get current time
    time_t now = time(NULL);
    
    // Convert to local time format
    struct tm *local_time = localtime(&now);
    
    // Buffer to store formatted date and time
    char time_str[100];
    
    // Format time as "Day, Month Date Year HH:MM:SS"
    strftime(time_str, sizeof(time_str), "%A, %B %d %Y %H:%M:%S", local_time);
    
    // Print formatted time
    printf("Current time: %s\n", time_str);
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

//Function to encrypt the text using Caesar cipher
void encrypt_File(const char* source_filename, const char* target_filename, int key) {
    // Open the source file for reading
    FILE* source_file = fopen(source_filename, "r");
    if (!source_file) {
        printf("Failed to open source file for reading.\n");
        return;
    }

    // Open the target file for writing
    FILE* target_file = fopen(target_filename, "w");
    if (!target_file) {
        printf("Failed to open target file for writing.\n");
        fclose(source_file);  // Close the source file before exiting
        return;
    }

    char ch;
    while ((ch = fgetc(source_file)) != EOF) {
        // Encrypt character
        if (islower(ch)) {
            ch = (ch - 'a' + key) % 26 + 'a';
        } else if (isupper(ch)) {
            ch = (ch - 'A' + key) % 26 + 'A';
        } else if (isdigit(ch)) {
            ch = (ch - '0' + key) % 10 + '0';
        }

        // Write the encrypted character to the target file
        fputc(ch, target_file);
    }

    // Close both files
    fclose(source_file);
    fclose(target_file);
    printf("Message encrypted and written to %s\n", target_filename);
}


//Decrypt Function
void decrypt_File(const char* source_filename, const char* target_filename, int key) {
    // Open the source file for reading
    FILE* source_file = fopen(source_filename, "r");
    if (!source_file) {
        printf("Failed to open source file for reading.\n");
        return;
    }

    // Open the target file for writing
    FILE* target_file = fopen(target_filename, "w");
    if (!target_file) {
        printf("Failed to open target file for writing.\n");
        fclose(source_file);  // Close the source file before exiting
        return;
    }

    char ch;
    while ((ch = fgetc(source_file)) != EOF) {
        // Decrypt character
        if (islower(ch)) {
            ch = (ch - 'a' - key + 26) % 26 + 'a';
        } else if (isupper(ch)) {
            ch = (ch - 'A' - key + 26) % 26 + 'A';
        } else if (isdigit(ch)) {
            ch = (ch - '0' - key + 10) % 10 + '0';
        }

        // Write the decrypted character to the target file
        fputc(ch, target_file);
    }

    // Close both files
    fclose(source_file);
    fclose(target_file);
    printf("Message decrypted and written to %s\n", target_filename);
}

//Excute a commond 
void excute_Command(char* incomeing_Argument){
    if(strcmp(incomeing_Argument, "math") == 0){
        calculation_Factory();
    } else if (strcmp(incomeing_Argument, "help") == 0){
        help_Function();
    } else if (strcmp(incomeing_Argument, "ls") == 0){
        list_Files();
    } else if (strcmp(incomeing_Argument, "pwd") == 0){
        print_Working_Directory();
    } else if (strcmp(incomeing_Argument, "read") == 0){
        read_File();
    } else if (strcmp(incomeing_Argument, "write") == 0){
        write_To_File();
    } else if (strcmp(incomeing_Argument, "cls") == 0){
        clear_Terminal();
    } else if (strcmp(incomeing_Argument, "rename") == 0){
        rename_File();
    } else if (strcmp(incomeing_Argument, "append") == 0){
        append_to_file();
    } else if (strcmp(incomeing_Argument, "encrypt") == 0){
        char source_File_Name[100];
        char target_File[100];
        int the_Key = 0;

        printf("Name of Source file: ");

        scanf("%99s", source_File_Name);

        printf("Key of Source File: ");

        scanf("%d", the_Key);

        printf("Name of Target File: ");

        scanf("%99s", target_File);

        encrypt_File(source_File_Name, target_File, the_Key);
    } else if (strcmp(incomeing_Argument, "decrypt") == 0){
        char source_File_Name[100];
        char target_File[100];
        int the_Key = 0;
        printf("Name of Source file: ");

        scanf("%99s", source_File_Name);

        printf("Key of Source File: ");

        scanf("%d", the_Key);

        printf("Name of Target File: ");

        scanf("%99s", target_File);

        decrypt_File(source_File_Name, target_File, the_Key);
    } else if (strcmp(incomeing_Argument, "time") == 0){
        show_Time();
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
    printf("[]   Enter (help) to see all the Commands  []\n");
    printf("[]=========================================[]\n");


    while (1) //Start of the loop might change the 1 into the perment var
    {   
        
        //Show that computer is waiting for prompt
        printf("[]< "); 
        
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