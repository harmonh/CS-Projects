/*********************************************************************************
**Program: projecttwo_final.cpp
**Author: Holly Harmon
**Description: Program for Project 2, week 3. Program runs a game where player one inputs
a secret word and player two guesses letters that may be in that word. Player Two wins if 
they guess the secret word and loses if they fail to guess the secret word before they 
run out of turns.
**Input: User One (Player One) inputs a string that will be a secret word. User Two 
(Player Two) inputs letters they think are in the secret word, or the whole word when 
they are ready to guess.
**Output: The program will output the letters in the word user two has gotten correct, 
the letters in the alphabet they have not yet guessed and how many turns they have left. 
The number of turns is based on the length of the secret word + 2 (if the secret word 
were "apple" the number of guesses would be 5+2=7). The program also tests user one's 
string to make sure it only contains letters and outputs an error message if it does not. 
It tests user two's letter guess to make sure it is a letter and not more than one 
character in length. An error message is output if either case is true and user two must 
enter a new guess. If user two's guess is in the secret word, the program prints a 
confirmation and the number of times the guess appears in the secret word. If user two 
guesses the secret word the program will print a congratulatory message and ask the user 
if they want to play again. If user two runs out of guesses before guessing the secret 
word, the program will output the secret word and what letters user two had not guessed.
*********************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void word_guess_game(); //Function runs most of the game program

//function to test word for alphabetical characters
//call by reference in case player one needs to enter a new word within the function
void valid_word (string& secretWordTest); 

int main ()
{
	char playAgain;
	
	//loop runs main game function while user chooses 'y' (yes) to playing again
	do
	{
		word_guess_game(); //call to game function
		cout << "Would you like to play again? (y/n): ";
		cin >> playAgain;
		cout << endl;
		
	} while ((playAgain == 'y') || (playAgain == 'Y'));
	
	cout << "Thanks for playing!\n";
	
	return 0;
			
}

void word_guess_game()
{
	string secretWord; //player one input, single word (string)
	string secretWordVoid; //place holder for unguessed letters
	string playerTwoGuess; //player two input, single letter
	//Letters player two has not guessed yet
	string alphaGuesses = " a b c d e f g h i j k l m n o p q r s t u v w x y z";
	char readyGuess;
	int numberOfGuesses;  //player two guesses
	int i = 0;
	int letterCount = 0; //increments when player two guess matches letter in secretWord
	
	//Player one input for secret word
	cout << "Player One, please enter a secret word for Player Two to guess.\n";
	cout << "Keep it to one word with no spaces: ";
	cin >> secretWord;
	cout << endl;
	
	valid_word(secretWord); //call to function to test for valid characters
	cout << endl << endl << endl << endl;
	
	//Converts secretWord to all lowercase letters
	for (string::size_type i = 0; i < secretWord.length(); i++)
	{
		secretWord[i] = tolower (secretWord[i]);
	}	
	
	//assigns secretWord to secretWordVoid and number of guesses
	secretWordVoid = secretWord;
	numberOfGuesses = (secretWord.length() + 2);
	
	//Prints number of letters in word as underscores to Player Two
	cout << "Player Two, these are the letters of the secret word you have so far: \n";
	for(i = 0; i < secretWord.length(); i++)
	{
		secretWordVoid.at(i) = '_';
		cout << secretWordVoid.at(i) << " ";
	}
	cout << endl << endl;
	
	//while loop that runs Player Two guessing section of program
	//Loops until player two guesses word or number of guesses is up
	while ((playerTwoGuess != secretWord) && (numberOfGuesses > 0) && (secretWordVoid != secretWord))
	{		
		
		
		cout << "You have " << numberOfGuesses << " guesses left\n";
		cout << "and the letters you have not guessed yet are: \n";
		cout << alphaGuesses << endl;
		cout <<	"Guess a letter that may be in the secret word: ";
		cin >> playerTwoGuess; //player two input
		cout << endl;
		
		//check if guess is a letter or more than one character in length
		int j = 0;
		while(!isalpha(playerTwoGuess[j]) || (playerTwoGuess.length() > 1))
		{
			cout << "That is not a valid entry, try again"
				"(no spaces or special characters!).\n";
			cin >> playerTwoGuess;
		}
		
		//removes letters from guess pool (alphaGuesses string)
		for(int i = 0; i < alphaGuesses.length(); i++)
			if (playerTwoGuess.at(0) == alphaGuesses.at(i))
			{
				alphaGuesses.erase (i - 1, 2); //removes letter and " " space before letter
			}
		
		//count times letter occurs
		for(int i = 0; i < secretWord.length(); i++)
			if (playerTwoGuess.at(0) == secretWord.at(i))
			{
				letterCount++;
			}
		
		//Prints times letter is in word OR tells player letter is not in word
		if(letterCount > 0)
		{
			cout << playerTwoGuess << " is in the secret word "
				<< letterCount << " time(s).\n";
		}
		else
		{
			cout << "Sorry, that letter is not in the secret word.\n";
		}
		cout << endl;
		
		//adds correct guesses to secretWordVoid to print out player two progress
		cout << "Here is what you have so far:\n";
		for(int n = 0; n < secretWord.length(); n++)
		{
			if(playerTwoGuess.at(0) == secretWord.at(n))
			{
				secretWordVoid.at(n) = playerTwoGuess.at(0);
			}
			cout << secretWordVoid.at(n) << " ";
		}
		cout << endl << endl;
		
		//Gives player two a chance to guess the word
		if(secretWordVoid != secretWord)
		{
			cout << "Are you ready to guess the secret word? (y/n): ";
			cin >> readyGuess;
			if((readyGuess == 'y') || (readyGuess == 'Y'))
			{
				cout << "Enter your guess: ";
				cin >> playerTwoGuess;
				if(playerTwoGuess == secretWord)
				{
					playerTwoGuess = secretWord; //exits while loop
				}
				else
				{
					cout << "That is not the correct word, keep guessing.\n";
				}
			}
		}
		
		cout << endl;
		letterCount = 0; //reset letterCount to 0 for next guess
		numberOfGuesses--; //decrement guesses by 1
		
	}
	
	//Congratulates the player if they guess the word right or guess all of the correct letters
	if((playerTwoGuess == secretWord) || (secretWordVoid == secretWord))
	{
		cout << "Congratulations!!! You guessed the secret word '" << secretWord << "'!\n";
		cout << "Go brag to all your friends!\n";
	}
	//Player two loses if they run out of turns and have not guessed the word
	else
	{
		cout << "Too bad, you are out of turns and did not guess the secret word.\n";
		cout << "The secret word was \"" << secretWord << "\"\n";
		cout << "You were missing the letters:\n";
		//loop prints letters player two was missing from secret word
		for(int i = 0; i < secretWord.length(); i++)
		{
			if(secretWordVoid.at(i) == '_')
			{
				cout << secretWord.at(i) << " ";
			}
		}
	}
	cout << endl;
}

void valid_word (string& secretWordTest)
{	
	int i;
	//check for word validity
	for(i = 0; i < secretWordTest.length(); i++)
	{
		if (!isalpha(secretWordTest[i]))
		{
			cout << "Not a valid word, input a word using only" 
				" alphabetical characters: \n";
			cin >> secretWordTest;
			i = 0;
			valid_word(secretWordTest); //calls function again to test new word
		}
	}
}