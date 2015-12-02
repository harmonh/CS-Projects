/*********************************************************************************
**Program: project_one.cpp
**Author: Holly Harmon
**Description: Project One. A guessing game where player one inputs a number and player two tries to guess the number.
**Input: Player one: an integer, player two: guesses numbers until they are out of turns.
**Output: Tells player two how many turns they have left, if they are too high or too low, and how close they were if they do not win.
*********************************************************************************/ 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main ( )
{
	char playAgain;
	
	//do-while loop to let the player choose to play again
	do
	{
		int secretNumber;
		int userGuess;
		int numberOfGuesses;
		int lowNumber, highNumber; //Range of possible numbers
	
		lowNumber = 1; //Starts with 1 to 100
		highNumber = 100;
		numberOfGuesses = 6; //number of guesses for player 2

		srand(time(0));
		secretNumber = rand( ) % (highNumber - 1) + lowNumber;
	
		cout << "The computer has chosen a secret number from 1 to 100 (inclusive).\n";
		cout << "Try to guess what it is!\n";
		
		//loop for player 2 to keep guessing until he/she is correct
		//or they are out of guesses.
		//increments number of gueses down by 1 each time.
		while ((userGuess != secretNumber) && (numberOfGuesses > 0))
		{
			cout << "You have " << numberOfGuesses
				<< " tries to guess the secret number.\n";
			//updates player 2's guessing range
			cout << "Guess a number between " 
				<< lowNumber << " and " << highNumber << endl;
			cin >> userGuess;
			numberOfGuesses--;
			
			//lets the player know if they are too high or too low
			if ((userGuess < secretNumber) && (numberOfGuesses > 0))
			{
				cout << "Your guess is too low, try again.\n";
			}
			else if ((userGuess > secretNumber) && (numberOfGuesses > 0))
			{
				cout << "Your guess is too high, try again.\n";
			}
			
			//loop to adjust the guessing range after each try
			if (userGuess < secretNumber)
			{
				lowNumber = userGuess + 1;
			}
			else if (userGuess > secretNumber)
			{
					highNumber = userGuess - 1;
			}
		}
		
		//if the player guesses the correct number
		if (userGuess == secretNumber)
		{
			cout << "Congratulations! You've guessed the Secret Number!\n"
				"Would you like to play again? (y/n): ";
			cin >> playAgain;
			cout << endl;
		}
		
		//runs if the player is out of guesses
		else
		{
			int lowDifference;
			int highDifference;
			
			lowDifference = secretNumber - (lowNumber - 1);
			highDifference = (highNumber + 1) - secretNumber;
			
			cout << "Nice try, but you have run out of guesses.\n";
			cout << "The secret number was " << secretNumber;
			
			if (lowDifference < highDifference)
			{
				cout << " and your closest guess was " << lowDifference 
					<< " away.\n";
			}
			else
			{	
				cout << " and your closest guess was " << highDifference 
					<< " away.\n"; 
			}
		
			cout << "Would you like to play again? (y/n): ";
			cin >> playAgain;
			cout << endl;
		}
	} while ((playAgain == 'y') || (playAgain == 'Y'));
	
	return 0;
}