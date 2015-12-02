/*********************************************************************************
**Program: project3.cpp
**Author: Holly Harmon
**Description: Project 3 is a phrase guessing game. The user tries to guess a secret phrase one 
word at a time. If the user ever fails to guess one of the words before they run out of guesses 
the game is over.
**Input: User inputs letter characters one at a time to guess a random number and selection of 
words in a phrase. The user may also input a string is they think they know the word they are 
trying to guess. The user may at no point enter a number or special character and doing so will 
return an error message and a chance to input another choice. Once the user has won or lost the 
game they may enter 'y' if they wish to play again or 'n' ( actually any character other than 
'y') if they do not.
**Output: The program tells the user how many words are in the secret phrase and which word they 
are currently guessing. As the player inputs letter guesses the program prints blanks "_" for 
letters in the word that have not been guessed and fills in correct guesses as they arise. If the 
user guesses a correct letter, the program will tell them how many times that letter occurs in 
the word. The user is also told which letters they have or haven't yet guessed. If the user 
guesses a word correctly they are told what parts of the phrase they have guessed so far or the 
whole phrase if they are done. If the user fails to guess one of the secret words the game ends, 
letting the user know which letters they missed and what the secret phrase was. The user then has 
the option to play again, 'y/n'.
*********************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib> //needed for rand function
#include <ctime> //need for time(0) seed in rand function
#include <algorithm> //for random_shuffle function
using namespace std;

void phrase_game();
//Function that when called returns the main section of the phrase game program
int phrase_length(int &phraseLength);
//Precondition: phraseLength can be any value before function call, will not effect the outcome 
//(in case a player chooses to play game again).
//Postconditon: The int variable phraseLength is set to the value of a random number between 
//2 and 6.
void secret_phrase_fun(int length, string secret[], string phrase_orig[]);
//Precondition: length is the int value of phraseLength, secret[] is the empty array that will
//hold the secret phrase, and phrase_orig[] is an array of strings (in this case the array
//phrase_array).
//Postcondition: Fills the secret_phrase array with the appropriate number of strings from the
//phrase_array.

int main ()
{
	char playAgain;
	
	//loop runs main game function while user chooses 'y' (yes) to playing again
	do
	{
		phrase_game(); //call to game function
		cout << "Would you like to play again? (y/n): ";
		cin >> playAgain;
		cout << endl;
		
	} while ((playAgain == 'y') || (playAgain == 'Y'));
	
	cout << "Thanks for playing!\n";
	
	
	return 0;
	
}

void phrase_game()
{
	//array holds all of the possible phrase words
	string phrase_array[15] = {"the", "moose", "police", "monopoly", "shoe", "running", "kangaroo", "olympics", "jumped", "secret", "of", "traffic", "heart", "the", "godzilla"};
	//holds the letters the user is allowed to guess
	string alpha_array[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	//a version of "alpha_array" that substitutes a "-" for each 
	//letter the user has already guessed. Resets after each word.
	string alpha_temp_array[26];
	
	
	int phraseLength; //how many words will be in the secret phrase
	string secretWord; //the current word being guessed by user
	string secretPhrase = ""; //empty string to be updated each time the user guesses a word
	string playerGuess; //can hold a single letter or the user's word guess
	int numberOfGuesses; 
	int letterCount = 0; //to count occurence(s) of letter guess in the secret word
	string secretWordVoid; //place-holder for user's progress in guessing current word
	
	//rand function to determine how many words will be in the secret phrase
	phrase_length(phraseLength);
	cout << "Welcome to the Phrase Guess Game! Try to guess each secret word in the phrase.\n"; cout << "Your phrase this round has " << phraseLength << " words in it." << endl << endl;
	
	//holds the words randomly chosen from "phrase_array" to be the secret phrase
	string secret_phrase[phraseLength];
	
	random_shuffle(&phrase_array[0], &phrase_array[14]); //shuffles array elements
	
	//creates the random phrase array
	secret_phrase_fun(phraseLength, secret_phrase, phrase_array);
	
	//runs for each word in secret phrase (according to phraseLength)
	for(int i = 0; i < phraseLength; i++)
	{
		secretWord = secret_phrase[i]; //sets the secret word for each round
		numberOfGuesses = (secretWord.length() + 3); //chances to guess each word
		secretWordVoid = secretWord;
	
		cout << "It's time to guess word #" << i + 1 << "! Good Luck!\n";
		cout << "These are the letters of the secret word you have so far: \n";
		//prints blank spaces "_" for every letter in the word that has not been guessed
		for(int j = 0; j < secretWord.length(); j++)
		{
			secretWordVoid.at(j) = '_';
			cout << secretWordVoid.at(j) << " ";
		}
		
		cout << endl << endl;
		cout << "The letters you have left to choose from are:\n";
		
		//fills the temporary array with all alphabet letters in alpha_array
		//Prints letters user has not used
		for(int k = 0; k < 26; k++)
		{
			alpha_temp_array[k] = alpha_array[k];
			cout << alpha_temp_array[k] << " ";
		}
		cout << endl << endl;
		//loop runs while user has not guesses the secret word or run out of guesses
		while ((playerGuess != secretWord) && (numberOfGuesses > 0) && (secretWordVoid != secretWord))
		{
			cout << "You have " << numberOfGuesses << " guesses left.\n";
			cout <<	"Guess a letter that may be in secret word #" << i+1 << " OR" << endl;
			cout << "enter the word if you think you know it: ";
			cin >> playerGuess;
			cout << endl;
			
			//check if guess is not a letter
			while(!isalpha(playerGuess[0]))
			{
				cout << "That is not a valid entry, try again(no spaces or special characters!).\n";
				cin >> playerGuess;
			}
			cout << "*********************************************************\n";
			//If playerGuess is only one chracter it is a letter guess, not a word guess
			if(playerGuess.length() == 1)
			{
				//counts guess occurrences in secret word
				for(int n = 0; n < secretWord.length(); n++)
					if (playerGuess.at(0) == secretWord.at(n))
					{
						letterCount++;
					}
				
				//prints if guess is in the secret word
				if(letterCount > 0)
				{
					cout << playerGuess << " is in the secret word "
						<< letterCount << " time(s).\n";
				}
				else //prints if guess is NOT in secret word
				{
					cout << "Sorry, that letter is not in the secret word.\n";
				}
			
				//adds correct guesses to secretWordVoid to print out player two progress
				cout << "Here is what you have so far:\n";
				for(int n = 0; n < secretWord.length(); n++)
				{
					if(playerGuess.at(0) == secretWord.at(n))
					{
						secretWordVoid.at(n) = playerGuess.at(0);
					}
					cout << secretWordVoid.at(n) << " ";
				}
				cout << endl << endl;
				
				//replaces letters guessed by user with "-"
				for(int k = 0; k < 26; k++)
				{
					if(playerGuess == alpha_temp_array[k])
					{
						alpha_temp_array[k] = "-";
					}
					if(secretWordVoid != secretWord)
					{
						cout << alpha_temp_array[k] << " "; //prints updated array to user
					}
				}
				cout << endl;
			
				letterCount = 0; //reset for next guess
				numberOfGuesses--;
			}
			//If user guess is more than one character length it is considered a word guess.
			//If guess is incorrect, else-if runs, if the guess is correct the while loop is 
			//exited and user guesses next word OR has correctly guessed the whole phrase.
			else if(playerGuess != secretWord)
			{
				cout << "Nice try, but that is not the secret word. Try guessing more letters.\n";
				numberOfGuesses--;
			}
		}
		
		//If the user has gotten through every word
		if((i + 1) == phraseLength)
		{
			cout << "**Congratulations!** You've guessed the secret phrase!\n";
			cout << "The phrase was: ";
			for(int i = 0; i < phraseLength; i++)
			{
				cout << phrase_array[i] << " ";
			}
			cout << endl;
		}
		//If user has correctly guessed a word, but not the whole phrase
		else if((playerGuess == secretWord) || (secretWordVoid == secretWord))
		{
			cout << "**Congratulations!** You've guessed a word in the secret phrase!\n";
			cout << "The word was '" << secretWord << "' ";
			secretPhrase.append(secretWord); //adds to phrase user has guessed so far
			secretPhrase.append(" ");
			cout << "and the secret phrase so far is: " << secretPhrase << endl;
			cout << "There are " << phraseLength - (i + 1) << " words left to guess." << endl << endl << endl;
		}
		//Player two loses if they run out of turns and have not guessed the word
		else
		{
			cout << "Too bad, you are out of turns and did not guess the secret word.\n";
			cout << "You were missing the letters: ";
			//loop prints letters player two was missing from secret word
			for(int n = 0; n < secretWord.length(); n++)
			{
				if(secretWordVoid.at(n) == '_')
				{
					cout << secretWord.at(n) << " ";
				}
			}
			cout << endl;
			cout << "The secret phrase was \"";
			//print secret phrase
			for(int n = 0; n < phraseLength; n++)
			{
				cout << secret_phrase[n] << " ";
			}
			cout << "\"" << endl;
			i = 5; //cancels for loop and exits game function
		}
		
	}
}

int phrase_length(int &phraseLength)
{
	srand(time(0));
	phraseLength = (rand() % 5 + 2);
}

void secret_phrase_fun(int length, string secret[], string phrase_orig[])
{
	for(int i = 0; i < length; i++)
	{
		secret[i] = phrase_orig[i];
	}
}