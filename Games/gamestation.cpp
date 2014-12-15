#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib> //needed for rand function
#include <ctime> //need for time(0) seed in rand function
#include <algorithm> //for random_shuffle function
using namespace std;

char main_game_menu();
void game_center_num_guess();
void game_center_num_guess_comp();
void game_center_word_guess();
void game_center_phrase_guess();

void word_guess_game(); //inside word guess
//function to test word for alphabetical characters
//call by reference in case player one needs to enter a new word within the function
void valid_word (string& secretWordTest);
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
char mainMenu;

int main ()
{
	main_game_menu();
	if(mainMenu != 'x')
	{
		do
		{
			cout << "Would you like to play a different game? (y/n) ";
			cin >> mainMenu;
			if ((mainMenu == 'y') || (mainMenu == 'Y'))
			{ main_game_menu(); }
		} while ((mainMenu == 'y') || (mainMenu == 'Y'));
	}
	
	cout << "Thanks for playing!\n";
	
	return 0;
}

char main_game_menu()
{
	int playerChoice;
	cout << "Greetings! Welcome to the Game Center!\n";
	cout << "Choose the number of the game you would like to play from the Menu:\n" << endl;
	cout << "(1) Number Guess *2P*\n";
	cout << "(2) Number Guess vs Computer *1P*\n";
	cout << "(3) Word Guess *2P*\n";
	cout << "(4) Phrase Guess *1P*\n";
	cout << "(5) Mystery Game\n";
	cout << "(6) Exit Game Center\n" << endl;
	cout << "Which Game Would You Like: ";
	cin >> playerChoice;
	
	while((playerChoice > 6) || (playerChoice < 1) || (cin.fail()))
	{
		cout << "There is no game with that number, choose again: ";
		cin.clear();
		cin.ignore(255, '\n');
		cin >> playerChoice;
	}
	
	switch(playerChoice)
	{
		case 1:
			cout << "Welcome to the Number Guess game!\n";
			game_center_num_guess();//function for number guess
			break;
		case 2:
			cout << "Welcome to the Number Guess vs Computer game!\n";
			game_center_num_guess_comp();
			break;
		case 3:
			cout << "Welcome to the Word Guess game!\n";
			game_center_word_guess(); //function for phrase guess
			break;
		case 4:
			cout << "Welcome to the Phrase Guess game!\n";
			game_center_phrase_guess();
			break;
		case 5:
			cout << "Mystery Game is a MYSTERY!\n";
			break;
		case 6:
			return mainMenu = 'x';
			break;
	}
}

void game_center_num_guess()
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
}

void game_center_num_guess_comp()
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
}

void game_center_word_guess()
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

void game_center_phrase_guess()
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