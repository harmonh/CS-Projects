#include <iostream>
#include <fstream> //file I/O
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cctype>
#include <limits> //ENTER command
#include <vector>
#include <boost/algorithm/string.hpp> //string to all lower case
#include <cstdio> //remove .txt file (list of things in hold)
#include "harmonh.h"

using namespace Harmonh; //My namespace!
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;

typedef char* mapArrayPtr;

int main(int argc, char *argv[])
{	
	srand(time(0)); //for rand() function
	
	int ans; //variable for binary question answers
	string ansStr; //variable for binary answer beginning with 0
	string userName; //user input from command line or cin
	string shipName; //user input
	int shipChoice; 
	string shipNum; //random number assigned to ship name
	char visit; //variable for map points
	char tryAgain;
	int spaceBucks = 500; //space bucks...
	

	user_name(argc, argv, userName); //getting username from command line
	
	//**1**UNDERSTANDING OF BINARY NUMBERS
	cout << "Welcome Captain " << userName << endl;
	cout << "To demonstrate that you are capable of piloting M Class starships\n";
	cout << "you will need to complete a few calculations.\n";
	cout << "Question 1: What is the Decimal Number representation of the\n";
	cout << "Binary Number '101010'?\n";
	cin >> ans;
	//checking for user error, only allows ints
	while(cin.fail()) {
		check_int(ans);
	}

	answer_check(ans, 42);

	cout << endl;

	cout << "Question 2: What is the Binary Number representation of the\n";
	cout << "Decimal Number '163'?\n";
	cin >> ans;
	while(cin.fail()) {
		check_int(ans);
	}

	answer_check(ans, 10100011);

	//**2**UNDERSTANDING OF TWO'S COMPLIMENT
	cout << "What is the 5-bit Two's Compliment of the Decimal Number 12?\n";
	cin >> ansStr; 
	//using a string, because I could not figure out how to make it
	//accept an integer beginning in zero.

	answer_check(ansStr, "01100");

	cout << "What is the 5-bit Two's Compliment of the Decimal Number -12?\n";
	cin >> ans;
		while(cin.fail()) {
		check_int(ans);
	}

	answer_check(ans, 10100);

	cout << "Great! You have passed the exam portion.\n";
	cout << "Now you will choose a ship." << endl << endl;
	cout << "You may choose a ship from the menu below.\n";

	//runs the ship menu
	ship_menu(shipChoice);

	cout << "You have chosen the X-" << shipChoice << ".\n";
	cout << "Enter a name for your ship and it will be assigned a number: ";
	
	getline(cin, shipName);

	shipName[0] = toupper(shipName[0]);
	//Checking for more than one word in the string.
	//capitalizing each word in the string.
	for(int i = 0; i < shipName.length(); i++) {
		if(isspace(shipName.at(i))) {
			shipName[i+1] = toupper(shipName[i+1]);
		}
	}
	
	//**10**USE AT LEAST ONE RANDOM NUMBER
	int Number = rand() % 2000 + 1000;
	//Stringstream to convert int to str so it can be appended to the user's
	//ship name
	ostringstream ss;
	ss << Number;
	shipNum = ss.str();
	shipName.append(" X");
	shipName.append(shipNum);

	cout << "You and your ship " << shipName << " are ready to disembark.\n";
	cout << "Good luck out there.\n";

	//An array to display the space map to the user.
	//Did not actually NEED to be dynamically declared.
	mapArrayPtr *main = new mapArrayPtr[10];
	for(int i = 0; i < 10; i++) {
		main[i] = new char[40];
	}

	fill_map_array(main);

	//This loop allows the user to visit different points on the map
	//more than once and to retry levels they lost in
	do {
		map_menu(main, visit);

		//Sector I is the alien intruder
		if(visit == 'I') {
			do {
				tryAgain = ' ';
				//If the user wins
				if(alien_attack() == 1) {
					cout << "Great job out there! Try a different sector.\n";
				}
				//If the user loses
				else {
					cout << "Valiant effort. Would you like to try again or visit a\n";
					cout << "different sector?\n";
					cout << "Try Again (t) or Different Sector (d):: ";
					cin >> tryAgain;
					while (tryAgain != 't' && tryAgain != 'T' && tryAgain != 'd' && tryAgain != 'D') {
						cout << "That is not a choice. Enter 't' or 'd':: ";
						cin >> tryAgain;
					}
				}
			} while(tryAgain == 't' || tryAgain == 'T');
		}

		//Sector A is the asteroid belt
		if(visit == 'A') {
			do {
				tryAgain = ' ';
				//If the user wins
				if(asteroid_assault() == 1) {
					cout << "Great job out there! Try a different sector.\n";
				}
				//If the user loses
				else {
					cout << "Valiant effort. Would you like to try again or visit a\n";
					cout << "different sector?\n";
					cout << "Try Again (t) or Different Sector (d):: ";
					cin >> tryAgain;
					while (tryAgain != 't' && tryAgain != 'T' && tryAgain != 'd' && tryAgain != 'D') {
						cout << "That is not a choice. Enter 't' or 'd':: ";
						cin >> tryAgain;
					}
				}
			} while(tryAgain == 't' || tryAgain == 'T');
		}

		//Sector T is a trading post. This sector cannot be won or lost.
		if(visit == 'T') {
			trading_post(spaceBucks);
		}

	} while(visit == 'I' || visit == 'A' || visit == 'T');

	cout << "Farewell Captain " << userName << ".\n";
	//Deletes the file so it is not kept for a new game. The user's hold items
	//go back to default
	remove("newHold.txt");

	return 0;
}