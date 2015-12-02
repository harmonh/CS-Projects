/*********************************************************************************
**Program: excercise_3_getline.cpp
**Author: Holly Harmon
**Description: Program for Excercise Set 3, Question 1: using getline instead of
just cin. The user inputs any string (can include multiple words) and the
program prints the string back one character at a time forwards and backwards,
then prints the number of letters in the string.
**Input: User is asked to input a string, it can be any length or number of words.
**Output: The string is printed to the user one letter at a time, then printed
one letter at a time in reverse order. Finally the program counts the number of
letters in the string and outputs that number to the user.
*********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main ( )
{
	string my_str; //string input by user
	int i;
		
	cout << "Input a string: ";
	getline(cin, my_str);
	
	//prints string one character at a time
	for (i = 0; i < my_str.length( ); i++)
	{	
		cout << my_str.at(i) << " ";
	}
	
	cout << endl;
	
	//prints string one character at a time from back to front
	//Not sure if this was the most efficient way to write this for loop
	for (i = (my_str.length( ) - 1); i >= 0; i--)
	{
		cout << my_str.at(i) << " ";
	}
	
	cout << endl;
	
	int x;
	x = 0;
	//increments x by the number of characters in the string
	for (i = 0; i < my_str.length ( ); i++)
	{
		x++;
	}
	
	cout << "Your string contains " << x << " letters." << endl;

	return 0;
}