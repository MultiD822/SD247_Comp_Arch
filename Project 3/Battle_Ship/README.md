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
```Person Notes
To design the Battleship game board, a 2D char array was chosen to represent the grid, with each cell initially holding a '.' to signify an unoccupied or unknown state. This structure efficiently maps the board's spatial layout, allowing for an intuitive representation of ships' positions and the outcomes of players' guesses. The array is populated at the start of the game through nested for loops, setting up a blank slate. Functions were then implemented to handle the core gameplay mechanics: initializing the board to its starting state, placing ships by marking their coordinates on the array, visually displaying the board to players, and updating cell statuses to reflect hits, misses, and the presence of vessels. This approach provides a clear, manageable way to track the dynamic state of the game, facilitating interactions between the user and the program.
```

### 2. Ship Placement:
- - The program should place ships for the user and computer. Ensure that ships cannot overlap or extend beyond the boundaries of the board.
```Person Notes
To design the game board, I utilized a 2D character array, where each cell represents a part of the game grid and is initially filled with '.' to denote an unoccupied or unknown state. This choice allowed for a straightforward depiction of the game's state, where ships' positions and the outcomes of players' guesses could be quickly recorded and updated. Through nested loops, I systematically initialized the board at the start of the game, ensuring a clean slate for gameplay. This structure facilitated the implementation of functions to place ships on the board—ensuring they neither overlap nor exceed the grid's boundaries—and to display the current board state to players, keeping them informed of the game's progress and standing.
```

### 3. Turn-Based Gameplay:

- - Implement a turn-based system where players take turns guessing the coordinates of their opponent's ships.
- - Validate each guess to ensure it falls within the acceptable range and has not been previously guessed.
- - Detect hits, misses, and the sinking of ships to determine the outcome of each guess.
```Person Notes
To implement the turn-based system for guessing the coordinates of opponents' ships, I focused on ensuring each guess was within the board's range rather than previously attempted. This involved creating a validation function to check guesses against the game's rules. I developed functions to update the game board accordingly after each turn to manage hits, misses, and ships sinking. This approach allowed me to accurately determine the outcome of guesses, providing immediate feedback on the game's state and maintaining the gameplay's competitive and strategic nature.
```

### 4. User Interface:
- - Display appropriate messages and prompts to guide players through the game, including notifications of hits, misses, and sunk ships.
- - Develop a console interface that displays the game board and allows players to input their guesses.
- - The board printout should be defined as follows:
- - - No action > .
- - - Ship present > S
- - - Ship hit > H
- - - Misses > O or 0
```Person Notes
In enhancing the game board's visual presentation, I aimed to incorporate ASCII art, intending to label rows with letters (A-J) and columns with numbers (0-9) for a more intuitive coordinate system, such as A1 or J9. However, I encountered challenges in converting characters to integers for this mixed coordinate system. As a result, the current implementation uses numeric coordinates (e.g., 2,5) for simplicity and clarity. This approach maintains the functionality of displaying hits ('H'), misses ('O'), and ship positions ('S') effectively while still leaving room for future improvements in user interface design.
```
### 5. Opponent: 
- - The computer should make random guesses on the board each turn.
```Person Notes
To ensure the game's unpredictability and challenge, I designed the computer's turn to involve making random guesses on the board. This randomness mimics a human opponent's unpredictability, enhancing the gameplay experience. At each turn, the computer randomly selects a coordinate, adhering to the board's dimensions, to guess the player's ship locations. This strategy keeps the player engaged and requires them to place their ships strategically, anticipate potential computer guesses, and plan their moves accordingly to outmaneuver the computer's randomized strategy.
```