/********************************************************************************
**Program: pp18_2.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Project 18.2. This program calls a 
recursive function that calls to a depth of 10 (0 being the main function, where
the recursive function has not yet been called). The user inputs a depth level
at which an exception is to be thrown and when the function is called, an 
exception is thrown at the specified level, then caught in the main function.
**Input: User inputs an intger fron 0 to 10 inclusive. If user puts in anything
else they are prompted to try again.
**Output: The user's input is assigned to int variable e which lets the program
know at which level it should throw int i (i indicating the current depth level).
********************************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int rec_function(int e, int i);
//Function calls itself recursively until int i reaches 10.
int valid_entry(int &e);
//check if user input e is an integer from 0 to 10.

int main( )
{
	int e;
	int i = 1;

	try
	{
		cout << "What calling depth would you like the exception to be thrown?\n";
		cout << "(Choose a number between 0 and 10 inclusive)\n";
		cin >> e;

		while(cin.fail() || (e > 10) || (e < 0)) {
			valid_entry(e);
		}

		//if user chooses level 0, the recursive funtion never needs to be called.
		if(e == 0) {
			i = 0;
			throw i;
		}
		rec_function(e, i);
	}
	catch (int i)
	{
		cout << "Exception was thrown at level " << i << endl;
	}
}

int rec_function(int e, int i)
{
	if(i < 11)
	{
		if(e == i)
		{
			throw i;
		}
		else
		{
			return rec_function(e, (i+1));
		}
	}
}

int valid_entry(int &e)
{
	cin.clear();
	cin.ignore(255, '\n');
	cout << "That is not a number between 0 and 10 inclusive. Try again: ";
	cin >> e;

}