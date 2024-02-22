# Project 3: Implementing Battleship in C

## Assignment Overview:
In this assignment, I will design and implement the classic game of Battleship using the C programming language. Battleship is a two-player guessing game where each player strategically places a fleet of ships on a grid and attempts to sink their opponent's ships by guessing their locations. My task is to create a console-based version of the game that simulates the gameplay experience and allows two players or in this case computer to compete against each other.

## Assignment Objectives:
- Develop proficiency in C programming language.
- Practice problem-solving and algorithmic thinking.
- Gain experience in handling arrays, functions, loops, and conditional statements in C.
- Understand the implementation of game logic and user interaction.
- Improve debugging and testing skills.

## Assignment Tasks:

### 1. Game Setup:
- - Design a data structure to represent the game board. The board should accurately depict the positions of ships and record the status of each grid cell.
- - Implement functions to initialize the game board, place ships on the board, and display the board to players.

### 2. Ship Placement:
- - The program should place ships for the user and computer. Ensure that ships cannot overlap or extend beyond the boundaries of the board.

### 3. Turn-Based Gameplay:

- - Implement a turn-based system where players take turns guessing the coordinates of their opponent's ships.
- - Validate each guess to ensure it falls within the acceptable range and has not been previously guessed.
- - Detect hits, misses, and the sinking of ships to determine the outcome of each guess.

### 4. User Interface:
- - Display appropriate messages and prompts to guide players through the game, including notifications of hits, misses, and sunk ships.
- - Develop a console interface that displays the game board and allows players to input their guesses.
- - The board printout should be defined as follows:
- - - No action > .
- - - Ship present > S
- - - Ship hit > H
- - - Misses > O or 0
```Person Notes

```
### 5. Opponent: 
- - The computer should make random guesses on the board each turn.