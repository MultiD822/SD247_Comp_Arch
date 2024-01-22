//Programmer: Kai Schenkel
//Class CS 141
//Data 5/15/2023
//Lab 4: Guessing Game   
//Sources: In class lectur, and watching youtube to understanding thing better

import java.util.Random;
import java.util.Scanner;

public class KS_GuessingGame {//Start of Main method 
    public static void main(String[] args) {
        intro();
        boolean keepGameGoing = true;
        int gamesPlayed = 0;
        int totalGuesses = 0;
        int bestGuess = Integer.MAX_VALUE;
        double averageGuess = 0.0;

        while (keepGameGoing) {//This while loop holds the game and the prosing of games played and totalguess 
            int amountOfGuess = playGame();
            totalGuesses += amountOfGuess;
            gamesPlayed++;
            if (amountOfGuess < bestGuess) {
                bestGuess = amountOfGuess;
            }
            averageGuess = (double) totalGuesses / gamesPlayed;
            keepGameGoing = playerChoice();
        }
        endScreen(gamesPlayed, bestGuess, averageGuess);
    }//End of main method 

    public static int playGame() {// This method is ment for dealing with the player guess and telling them if they are right or not 
        Random makeNum = new Random();
        int guessingNum = makeNum.nextInt(100) + 1;
        Scanner playerInput = new Scanner(System.in);
        int playerGuess;
        int guessingCounter = 0;

        do {//This will take the players guess and see if the players guess 
            System.out.print("Enter your guess: ");
            playerGuess = playerInput.nextInt();
            guessingCounter++;
            if (guessingNum > playerGuess) {
                System.out.println("It is higher than what you guessed.");
            } else if (guessingNum < playerGuess) {
                System.out.println("It is lower than what you guessed.");
            }
        } while (guessingNum != playerGuess);
        System.out.println("You got it right!");

        return guessingCounter;
    }//End of playGame method

      public static void intro() {
        System.out.println("This program allows you to play a guessing game.");
        System.out.println("I will think of a number between 1 and 100 and will allow you to guess until you get it.");
        System.out.println("For each guess, I will tell you whether the right answer is higher or lower than your guess.");
    }//End of intor method

      public static void endScreen(int gamesPlayed, int bestGuess, double averageGuess) {//This method is meant to show the results of n amount of game 
        System.out.println("Overall results:");
        System.out.println("Total games   = " + gamesPlayed);
        System.out.println("Total guesses = " + bestGuess);
        System.out.println("Guesses/game  = " + averageGuess);
    }//End of endScreen method

      public static boolean playerChoice() {//This method is meant for allowing the play to play again or end and see results
        Scanner input = new Scanner(System.in);
        System.out.println("Do you want to play again? (yes/no)");
        String response = input.nextLine();
        return response.equalsIgnoreCase("yes");
    }//End of playerChoice method
}

