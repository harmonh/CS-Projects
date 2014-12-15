#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <cstdio>
#include "harmonh.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::stringstream;

namespace Harmonh
{
	//I originally wrote the game as seperate missions and then combined them
	//into one game. The "mission #" notes are purely for my own reference.
	//mission 1
	void user_name(int argc, char *argv[], string& userName)
	{
		string first;
		string last;

		try
		{
			//Means the user did not enter their name
			if(argc == 1)
				throw argc;

			else if (argc == 2) {
				userName = argv[1];
				userName[0] = toupper(userName[0]);
			}
			
			else if (argc == 3) {
				first = argv[1];
				last = argv[2];
				userName = first + " " + last;
				//Making sure the names are capitalized
				userName[0] = toupper(userName[0]);
				for(int i = 0; i < userName.length(); i++) {
					if(isspace(userName.at(i))) {
						userName[i+1] = toupper(userName[i+1]);
					}
				}
			}
			
			//The user cannot enter more than two strings for their name.
			else {
				cout << "You have enetered too many values into the command line.\n";
				cout << "Exit and enter at most your First and Last names or\n";
				cout << "enter it here: ";
				getline(cin, userName);
				cout << endl;

				userName[0] = toupper(userName[0]);
				for(int i = 0; i < userName.length(); i++) {
					if(isspace(userName.at(i))) {
						userName[i+1] = toupper(userName[i+1]);
					}
				}
			}	
		}
		catch(int argc)
		{
			cout << "Welcome, it looks like you did not enter your name in the command line.\n";
			cout << "Either quit the program and enter your name (First or Last or Both) or\n";
			cout << "enter it here:: ";
			getline(cin, userName);
			cout << endl;

			userName[0] = toupper(userName[0]);
			for(int i = 0; i < userName.length(); i++) {
				if(isspace(userName.at(i))) {
					userName[i+1] = toupper(userName[i+1]);
				}
			}
		}
	}

	//For binary question portion
	void answer_check(int& userAns, int answer)
	{
		while(userAns != answer) {
			cout << "Wrong. Try Again: ";
			cin >> userAns;
			while(cin.fail()) {
				check_int(userAns);
			}
		}

		if(userAns == answer) {
			cout << "Correct. Excellent Work!\n";
		}
	}

	//For binary question portion ALSO Overloaded function :D
	void answer_check(string& userAns, string answer)
	{
		while(userAns != answer) {
			cout << "Wrong. Try Again: ";
			cin >> userAns;
		}

		if(userAns == answer) {
			cout << "Correct. Excellent Work!\n";
		}
	}

	//For binary question portion
	void check_int(int& userAns)
	{
		cout << "That is not an integer. Try again: ";
		cin.clear();
		cin.ignore(255, '\n');
		cin >> userAns;
	}

	//mission 2
	void ship_menu(int& shipChoice)
	{
		char choice;
		starship x1, x2, x3, x4; //struct
		do {
			cout << "Enter a ship number to see its stats and information.\n";
			cout << endl;
			cout << "(1) X-1\n";
			cout << "(2) X-2\n";
			cout << "(3) X-3\n";
			cout << "(4) X-4\n";
			cout << ":: ";
			cin >> shipChoice;

			//Checks if user input is not a choice in the switch
			while(cin.fail() || shipChoice > 4 || shipChoice < 1) {
				cout << "That is not a menu selection. Choose again: ";
				cin.clear();
				cin.ignore(255, '\n');
				cin >> shipChoice;
			}

			//The ships have cool struct member variables, but they do not really
			//play a part in the game. Sorry.
			switch(shipChoice) {
				case 1:
					cout << "The X-1 has the following stats:\n";
					setStarship(x1, 2, "Cargo Freighter", 3, "Heavy Laser");
					printStarship(x1);
					break;

				case 2: 
					cout << "The X-2 has the following stats:\n";
					setStarship(x2, 3, "Battlestar", 5, "Anti-ship Cannon");
					printStarship(x2);
					break;

				case 3:
					cout << "The X-3 has the following stats:\n";
					setStarship(x3, 2, "Stealth Cruiser", 2, "Glaive Beam");
					printStarship(x3);
					break;

				case 4:
					cout << "The X-4 has the following stats:\n";
					setStarship(x4, 5, "Civilian Transport", 6, "Photon Torpedoes");
					printStarship(x4);
					break;
				}
			
			cout << endl << endl;
			cout << "Would you like to select this ship (y) or choose "
					<< "another (n)? ";
			cin >> choice;
		}while((choice == 'n') || (choice == 'N'));
		//Something was not working correctly in this section of code
		//and using cin.clear fixed the issue.
		cin.clear();
		cin.ignore(255, '\n');
	}

	void setStarship(starship& star, int crew, string type, int shields, 
						string weapon)
	{
		//from Starship struct
		star.crew = crew;
		star.type = type;
		star.shields = shields;
		star.weapon = weapon;
	}

	void printStarship(starship star)
	{
		cout << "Number of crew members: " << star.crew << endl;
		cout << "Ship Type: " << star.type << endl;
		cout << "Shield Level: " << star.shields << endl;
		cout << "Weapon: " << star.weapon << endl;
	}

	//mission 3

	void fill_map_array(char **main)
	{
		//Fills with blanks
		int i, j;
		for(i = 0; i < 10; i++) {
			for(j = 0; j < 40; j++) {
				main[i][j] = ' ';
			}
		}
		//Creates a border
		for(j = 0; j < 40; j++) {
			main[0][j] = '-';
			main[9][j] = '-';
		}
		for(int k = 0; k < 10; k++) {
			main[k][0] = '|';
			main[k][39] = '|';
		}
		//Randomly places stars :D
		srand(time(0));
		for(i = 0; i < 10; i++) {
			int x = (rand() % 8 + 1);
			int y = (rand() % 38 + 1);
			if(main[x][y] == ' ') {
				main[x][y] = '*';
			}
		}
		//Places the sector points
		main[3][3] = 'E';
		main[5][20] = 'A';
		main[2][30] = 'T';
		main[8][12] = 'I';
	}

	void print_map(char **main)
	{
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 40; j++) {
				cout << main[i][j];
			}
			cout << endl;
		}

	}

	char map_menu(char **main, char& visit)
	{
		cout << "Below is a map of the surrounding sector.\n";
		print_map(main);

		cout << "E is always Earth and your starting location. To exit, enter 'X'.\n";
		cout << "Which sector would you like to visit?  ";
		cin >> visit;
		visit = toupper(visit); //easier for error checking

		while(visit != 'E' && visit != 'A' && visit != 'I' && 
				visit != 'T' && visit != 'X')
		{
			cout << "That is not a point on the map. Pick again: ";
			cin >> visit;
			visit = toupper(visit);
		}

		cout << "You chose to visit sector " << visit << endl << endl;
		//E does not actually go anywhere/do anything
		//A neat thing to add in the future would be an option to go back
		//and change your name, ship, etc.
		while(visit == 'E') {
			cout << "You are already at Earth. Pick another destination: ";
			cin >> visit;
			visit = toupper(visit);
			while(visit != 'E' && visit != 'A' && visit != 'I' && visit != 'T')
			{
				cout << "That is not a point on the map. Pick again: ";
				cin >> visit;
				visit = toupper(visit);
			}
		}
	}

	void trading_post(int& spaceBucks)
	{
		char tradeAns;
		string buyItem;
		vector<string> hold; //What user has in their hold
		vector<string> trade; //What trader has for sale

		open_items(hold, trade);

		cout << "You have come upon some traders.\n";
		cout << "Here is what you currently have in your hold:\n";
		for(int i = 0; i < hold.size(); i++) {
			cout << hold[i] << endl;
		}

		cout << "*************************************\n";
		cout << "Would you like to puchase some items?\n";
		cout << "(y/n):: ";
		cin >> tradeAns;

		trade_function(tradeAns, trade, hold, spaceBucks);	

		add_print_items(hold);

		cout << "You have finished trading and decide to move on to another sector.\n";
		cout << "Press ENTER to continue...";
		//For some reason this only works sometimes if I use it twice...
		//Something to go back and figure out next week.
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
	}

	int asteroid_assault()
	{
		int asts = 4;
		string* a;
		string ast_array[16] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", 
								"13", "14", "15", "16"};
		a = ast_array;

		cout << "You've jumped into the middle of an asteroid field!\n";
		cout << "One has made impact and your sensors are off-line. You're shooting blind!!!\n";
		cout << "You need to destroy the asteroids before they get to you!\n";
		cout << "You have 8 shots before they reach the ship and it is too late." << endl << endl;

		cout << "Choose a numbered location to shoot at\n";

		print_array(a);
		cout << endl;
	
		asteroid_shoot(a, asts);

		//If all the asteroids get shot
		if(asts == 0) {
			cout << "You did it! The ship makes it safely through the asteroid field\n";
			cout << "and you are free to move on to a different sector.\n";
			cout << "Press ENTER to continue...";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
			return 1;
		}
		//If some are missed
		else {
			cout << "You ran out of time and the ship was impacted by " << asts << " asteroids\n";
			cout << "It is too damaged to go on and you must return to Earth for repairs.\n";
			cout << "Press ENTER to continue...";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
			return 0;
		}
	}

	int alien_attack()
	{
		Human *cap;
		cap = new Human(35, 20);

		Alien *al;
		al = new Alien(20, 30);

		cout << "Oh no! An intruder has somehow beamed aboard your ship!\n";
		cout << "I wonder how they made it past the shields...\n";
		cout << "Quick, you need to attack." << endl << endl;

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
		//As long as both you and the alien are alive:
		while((cap->getLife() > 0) && (al->getLife() > 0)) {
			cout << "Press ENTER to attack.";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
			cout << endl;

			//Gets user damage and adjusts the alien's life points
			al->setLife(al->getLife() - cap->getDamage());
			//If lifepoints go below 0, alien is dead (cannot have neg lifepoints)
			if(al->getLife() < 0) {
				al->setLife(0);
			}
			else {
				cout << "The alien's life is now " << al->getLife() << " points." << endl << endl;
				cap->setLife(cap->getLife() - al->getDamage());
				if(cap->getLife() < 0) {
					cap->setLife(0);
				}
				cout << "Your life is now " << cap->getLife() << " points." << endl;
			}
		}
		//user wins the battle
		if(al->getLife() == 0) {
			cout << endl;
			cout << "You've killed the intruder! I guess we'll never know what it\n";
			cout << "was really here for...\n";
			cout << "You are now ready to move on to a different sector.\n";
			cout << "Press ENTER to continue...";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
			return 1;
		}
		//user loses the battle :(
		else {
			cout << endl;
			cout << "You have been gravely wounded by the alien's razor sharp claws.\n";
			cout << "Your crew managed to save you at the last minute, but you must\n";
			cout << "return to Earth for medical attention and recuperation.\n";
			cout << "Press ENTER to continue...";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
			return 0;
		}
	}

	//mission 4
	//Base class:
	Creature::Creature( )
	{
		strength = 10;
		lifePoints = 10;
	}

	Creature::Creature(int newLife, int newStrength)
	{
		lifePoints = newLife;
		strength = newStrength;
	}

	int Creature::setLife(int newLife)
	{
		lifePoints = newLife;
	}

	int Creature::setStrength(int newStrength)
	{
		strength = newStrength;
	}

	int Creature::getLife( )
	{
		return lifePoints;
	}

	int Creature::getStrength( )
	{
		return strength;
	}

	int Creature::getDamage( )
	{
		int damage;
		//**10**USE AT LEAST ONE RANDOM NUMBER
		damage = (rand( ) % strength) + 1;
		return damage;
	}

	Human::Human( ) : Creature( )
	{
		//empty
	}

	Human::Human(int newLife, int newStrength) : Creature(newLife, newStrength)
	{
		//empty
	}

	int Human::getDamage( )
	{
		int damage = Creature::getDamage();
		cout << "You attack for " << damage << " points!\n";
		
		//**10**USE AT LEAST ONE RANDOM NUMBER
		//Humans have less strength than aliens, but can sometimes
		//get a critical hit
		if ((rand( ) % 10) == 0)
		{
			cout << "**The phaser blast hits a critical spot.\n";
			cout << "**You do 5 extra points of damage!\n";
			damage = damage + 5;
		}
		return damage;
	}

	Alien::Alien( ) : Creature( )
	{
		//empty
	}

	Alien::Alien(int newLife, int newStrength) : Creature(newLife, newStrength)
	{
		//empty
	}

	int Alien::getDamage( )
	{
		//Aliens do not get extra damage for anything
		int damage = Creature::getDamage();
		cout << "The alien attacks for " << damage << " points!\n";
		return damage;
	}

	Human::~Human( )
	{
		//empty
	}

	Alien::~Alien( )
	{
		//empty
	}

	//mission 5
	void print_array(string a[])
	{
		for(int i = 0; i < 9; i++) {
			cout << " " << a[i] << " ";
			if((i == 3)||(i == 7)) {
				cout << endl;
			}
		}

		for(int i = 9; i < 16; i++) {
			if(a[i] == "X" || a[i] == "*") {
				cout << " " << a[i] << " ";
			}
			else {
				cout << a[i] << " ";
			}
			if((i == 11)) {
				cout << endl;
			}
		}
	}

	void asteroid_shoot(string a[], int& asts)
	{
		int astShot;
		int shots = 8;
		while((asts > 0) && (shots > 0)) {
			cout << ":: ";
			cin >> astShot;
			shots--; //Counting down the shots
			//Error checking
			while((astShot < 1) || (astShot > 16) || cin.fail())
			{
				cout << "That is not a coordinate to target. Try again:: ";
				cin.clear();
				cin.ignore(255, '\n');
				cin >> astShot;
			}
			while((a[astShot-1] == "X")||(a[astShot-1] == "*"))
			{
				cout << "You have already shot that location. Try again:: ";
				cin >> astShot;
			}
			if((astShot == 4)||(astShot == 7)||(astShot == 9)||(astShot == 12))
			{
				asts--;
				cout << "You got one! There are " << asts << " asteroids and "
						<< shots << " shots left\n";
				a[astShot-1] = "*";	
			}
			else {	
				cout << "You missed! You shot at empty space.\n";
				cout << "There are still " << asts << " asteroids and " << shots << " shots left\n";
				a[astShot-1] = "X";
			}

			print_array(a);

			cout << endl;
		}
	}

	//mission 6
	void open_items(vector<string>& hold, vector<string>& trade)
	{
		ifstream ins;
		string next;

		ins.open("newHold.txt");
		if(ins.fail( )) {
			ins.open("holdItems.txt");
			if(ins.fail( )) {
				cout << "Input file opening failed.\n";
				exit(1);
			}
		}

		//puts the elements of the input file into a vector
		while(ins >> next) {
			hold.push_back(next);
			//cout << next << endl; <-error checking for debugging
		}
		ins.close(); //close file

		ins.open("tradeItems.txt");
		if(ins.fail( )) {
			cout << "Input file opening failed.\n";
			exit(1);
		}

		while(ins >> next) {

			trade.push_back(next);
			//cout << next << endl;
		}
		ins.close(); //close file
	}

	void trade_function(char tradeAns, vector<string>& trade, vector<string>& hold, int& spaceBucks)
	{
		string buyItem;

		if(tradeAns == 'y'||tradeAns == 'Y') {
			//FYI: Blorgons are not actually muscular or scruffy
			cout << "\"Greetings!\" A muscular, scruffy looking Blorgon\n";
			cout << "steps up to the counter.\n";
			cout << "\"Would you like to see what we have for sale?\"\n";
			cout << "(y/n):: ";
			cin >> tradeAns;
			while(tradeAns == 'y'||tradeAns == 'Y') {
				int price = 0;
				//The items in the trade vector are an item followed by it's price
				cout << "Here are our wares and their cost in Space Bucks:\n";
				for(int i = 0; i < trade.size(); (i += 2)) {
					cout << "Item: " << trade[i] << "    Cost: $$" << trade[i+1] << endl;
				}
				cout << endl;
				cout << "You currently have " << spaceBucks << " Space Bucks.\n";
				cout << "Which item would you like:: ";
				cin >> buyItem;
				//Needed for user input to match trade vector strings
				boost::algorithm::to_lower(buyItem);
				buyItem[0] = toupper(buyItem[0]);
				
				int k = trade.size();
				for(int i = 0; i < trade.size(); (i += 2)) {
					
					if(trade[i] == buyItem) {
						stringstream ss(trade[i+1]);
						ss >> price;
						//Checking is the user has enough $$
						if(price > spaceBucks) {
							cout << "You do not have enough Space Bucks to buy that.\n";
							cout << "Balance: $$" << spaceBucks << endl;
						}
						else {
							hold.push_back(trade[i]); //ads item to hold
							trade.erase(trade.begin() + i); //deletes item from trade
							trade.erase(trade.begin() + i); //deletes price from trade
						}
					}
				}

				//If there is no price, the item does not exist
				if(price == 0) {
						cout << "Sorry. That is not an item we sell.\n";
					}
				else if(price < spaceBucks) {
					spaceBucks = spaceBucks - price;
					cout << "You bought a " << buyItem << " for $$" << price << endl;
					cout << "You have $$" << spaceBucks << " left." << endl << endl;
				}
			

				cout << "Would you like to look at the list again?(y/n): ";
				cin >> tradeAns;
			}
		}
	}

	void add_print_items(vector<string>& hold)
	{
		ofstream outs;
		outs.open("newHold.txt");
		if(outs.fail()) {
			cout << "Output file opening failed.\n";
			exit(1);
		}
		cout << endl;
		cout << "You now have the following items in your hold: \n";
		for(int i = 0; i < hold.size(); i++) {
			cout << hold[i] << endl;
			outs << hold[i] << endl;
		}
		outs.close();
	}
}


