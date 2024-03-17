# Project 4: C Terminal

## Objective: 
The objective of this assignment is to reinforce your understanding of basic C programming concepts and to enhance your skills in handling input/output operations, string manipulation, and command execution.

## Overview
This project aims to reinforce understanding of basic C programming concepts, focusing on input/output operations, string manipulation, and command execution. It mimics the basic functionalities of a standard terminal found in most operating systems, capable of handling user input, parsing commands, and executing them accordingly. Additionally, it includes a custom command for file encryption/decryption using the Caesar Cipher.

## Features
- User Interface: 
Displays a prompt (> or $ ) indicating readiness to accept commands.
- Command Execution: 
Executes basic system commands (ls, pwd, etc.) and custom commands.
- Custom Command: 
Includes a secure_file command for encryption/decryption of text files using the Caesar Cipher.
- Command Parsing: 
Parses the input to identify commands and arguments.
- Error Handling: 
Gracefully handles errors with appropriate messages.
- Exit Command: 
Allows exiting the terminal with exit or quit commands.

## Compiling Program
To compile the terminal application, navigate to the project directory and run the following command:
```
gcc -o bin/KS_C_Terminal KS_C_Terminal.c
```

## Running Application
After compilation, you can run the application by navigating to the bin directory and executing the program:
```
cd bin
./KS_C_Terminal 
```