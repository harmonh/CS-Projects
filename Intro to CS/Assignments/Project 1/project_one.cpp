/*********************************************************************************
**Program: project_one.cpp
**Author: Holly Harmon
**Description: Project One. A guessing game where player one inputs a number and 
player two tries to guess the number.
**Input: Player one: an integer, player two: guesses numbers until they are out of 
turns.
**Output: Tells player two how many turns they have left, if they are too high or 
too low, and how close they were if they do not win.
*********************************************************************************/ 

#include <iostream>
using namespace std;

int main ( )
{
	char playAgain;
	
	//do-while loop to let the player choose to play again
	do
	{
		int secretNumber;
		int userTwoGuess;
		int numberOfGuesses;
		int lowNumber, highNumber; //Range of possible numbers
	
		lowNumber = 1; //Starts with 1 to 100
		highNumber = 100;
		numberOfGuesses = 5; //number of guesses for player 2
	
		cout << "Player 1, Pick a number between 1 and 100"
			" to be the Secret Number: ";
		cin >> secretNumber;
		
		//to make sure player one chooses a number within range
		while ((secretNumber < 1) || (secretNumber > 100))
		{
			cout << "That is not a number between 1 and 100, pick again: ";
			cin >> secretNumber;
			cout << endl;
		}
		
		//loop for player 2 to keep guessing until he/she is correct
		//or they are out of guesses.
		//increments number of gueses down by 1 each time.
		while ((userTwoGuess != secretNumber) && (numberOfGuesses > 0))
		{
			cout << "Player 2, you have " << numberOfGuesses
				<< " tries to guess player 1's secret number.\n";
			//updates player 2's guessing range
			cout << "Guess a number between " 
				<< lowNumber << " and " << highNumber << endl;
			cin >> userTwoGuess;
			numberOfGuesses--;
			
			//lets the player know if they are too high or too low
			if ((userTwoGuess < secretNumber) && (numberOfGuesses > 0))
			{
				cout << "Your guess is too low, try again.\n";
			}
			else if ((userTwoGuess > secretNumber) && (numberOfGuesses > 0))
			{
				cout << "Your guess is too high, try again.\n";
			}
			
			//loop to adjust the guessing range after each try
			if (userTwoGuess < secretNumber)
			{
				lowNumber = userTwoGuess + 1;
			}
			else if (userTwoGuess > secretNumber)
			{
					highNumber = userTwoGuess - 1;
			}
		}
		
		//if the player guesses the correct number
		if (userTwoGuess == secretNumber)
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
