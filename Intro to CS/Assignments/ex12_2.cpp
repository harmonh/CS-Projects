/******************************************************************************************************
**Program: ex12_2.cpp
**Author: Holly Harmon
**Description: For exercise 12 question 2. This program contains a vector that keeps track of the
visitors coming and going from a building. Visitors can be added (check-in), removed (check-out)
or searched to see if someone is in the building.
**Input: User chooses from a menu and can input "1" to check-in, "2" to check-out, or "3" to search
for a visitor. The user then inputs a first name to be added, removed, or searched.
**Output: Asks the user to choose from a menu of options. Confirms with the user that the visitor has
been checked in, checked out, or that they are in the building.
******************************************************************************************************/

#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class building_visitors
{
public:
	void add_visitor( ); //check-in a visitor
	void remove_visitor( ); //check-out a visitor
	void search_visitor(); //search the visitor vector (list)
	//assigns names to the visitor list/log
	void fill_log(string name1, string name2, string name3); 
private:
	string visitor;
	vector<string> visitorsLog;
};

int main()
{
	building_visitors building1; //creates a vector for building1
	int menuOption;

	building1.fill_log("alex", "josh", "karen");
	//User must choose a menu option.
	cout << "What would you like to do:\n";
	cout << "(1)Check-In a new visitor\n(2)Check-Out a visitor\n(3)See if a visitor is in the building\n";
	cout << "Enter a choice (1, 2, or 3): ";
	cin >> menuOption;
	//Calls a function depending on the users menu choice
	if(menuOption == 1) {
		building1.add_visitor( );
	}
	if(menuOption == 2) {
		building1.remove_visitor( );
	}
	if(menuOption == 3) {
		building1.search_visitor( );
	}

	return 0;

}

void building_visitors::add_visitor( )
{
	cout << "What is the visitor's name?\n";
	cin >> visitor;
	visitorsLog.push_back(visitor); //adds visitor to the vector
	cout << visitor << " has been added to the log.\n";
}

void building_visitors::remove_visitor( )
{
	string visitor;

	cout << "Which visitor would you like to check out?\n";
	cin >> visitor;
	//searches the visitor vector for a match and erases the match from the vector
	for(unsigned int i = 0; i < visitorsLog.size(); i++)
		if (visitor == visitorsLog[i]) {
			visitorsLog.erase(visitorsLog.begin() + i);
			cout << visitor << " has been removed from the log.\n";
		}
}

void building_visitors::search_visitor( )
{
	cout << "Enter the name of the visitor you are looking for: ";
	cin >> visitor;
	//Searches visitor vector for a match
	for(unsigned int i = 0; i < visitorsLog.size(); i++)
		if(visitor == visitorsLog[i]) {
			cout << visitor << " is in the building.";
			return;
		}
}

//Fills the visitor vector with three visitor names.
void building_visitors::fill_log(string name1, string name2, string name3)
{
	visitorsLog.push_back(name1);
	visitorsLog.push_back(name2);
	visitorsLog.push_back(name3);
	
}