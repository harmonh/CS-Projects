/*********************************************************************************
**Program: pp12_25.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Projects 12.25. This program contains
a function that reads in a user integer as a string and converts it to an integer
using stringstream.
**Input: User inputs an integer which is read as a string.
**Output: If the user inputs something other than an integer, an error message will
show and ask to try a new input. If the user has input an int it will be converted
from a string to an integer and output to the screen.
*********************************************************************************/
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

int stringstream_integer();
/*User inputs a number and the function uses getline to assign that number to
a string. Stringstream is used to extract the integer from the string.*/

int main( )
{
	
	cout << "Your integer is: " << stringstream_integer() << endl;
	return 0;
}

int stringstream_integer()
{
	int error; //to aid in error handling
	int userInt;
	do {
	error = 1;
	string userStr; //user input

	cout << "Type in an integer: ";
	getline(cin, userStr);

	stringstream ss(userStr);
	
	if((ss >> userInt).fail()) {
		cout << "That is not an integer. Try again.\n";
		error = 0;
	}
	} while(error == 0);
	
	return userInt;
}