#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cctype>
#include "harmonh.h"

using namespace Harmonh;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;

int main()
{
	string userName;
	string shipName;
	int shipChoice;
	string shipNum;
	srand(time(0));
	
	cout << "Please enter your name: ";
	getline(cin, userName);
	//change to except two names and only use last or one name
	userName[0] = toupper(userName[0]);
	
	for(int i = 0; i < userName.length(); i++) {
		if(isspace(userName.at(i))) {
			userName[i+1] = toupper(userName[i+1]);
		}
	}

	cout << endl;
	cout << "Welcome Captain " << userName << endl;

	cout << "You may choose a ship from the menu below.\n";

	ship_menu(shipChoice);

	cout << "You have chosen the X-" << shipChoice << ".\n";
	cout << "Enter a name for your ship and it will be assigned a number: ";
	
	getline(cin, shipName);

	shipName[0] = toupper(shipName[0]);
	
	for(int i = 0; i < shipName.length(); i++) {
		if(isspace(shipName.at(i))) {
			shipName[i+1] = toupper(shipName[i+1]);
		}
	}

	
	int Number = rand() % 2000 + 1000;
	ostringstream ss;
	ss << Number;
	shipNum = ss.str();
	shipName.append(" X");
	shipName.append(shipNum);

	cout << "You and your ship " << shipName 
			<< " are ready to disembark.\n";
	cout << "Good luck out there.\n";
	
	return 0;

}