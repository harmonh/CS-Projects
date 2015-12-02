/*********************************************************************************
**Program: excercise_3.cpp
**Author: Holly Harmon
**Description: Program for Exercise Set 3, Question 1. The user inputs any
string and the program prints the string back one character at a time forwards
and backwards, then prints the number of letters in the string.
**Input: User is asked to input a string.
**Output: The string is printed to the user one letter at a time, then printed
one letter at a time in reverse order. Finally the program counts the number of
letters in the string and outputs that number to the user.
*********************************************************************************/ 

#include <iostream>
#include <string>  //so we can use strings
using namespace std;

int main ( )
{
	string my_str; //string input by user
	int i;
		
	cout << "Input a string: ";
	cin >> my_str;
	
	//increments i up to length of string
	//prints string one character at a time
	for (i = 0; i < my_str.length( ); i++)
	{	
		cout << my_str.at(i) << " ";
	}
	cout << endl;
	
	//prints string one character at a time in reverse order
	for (i = (my_str.length( ) - 1); i >= 0; i--)
	{
		cout << my_str.at(i) << " ";
	}
	cout << endl;
	
	int x;
	x = 0;
	
	//counts the number of letters(characters) in the string
	for (i = 0; i < my_str.length ( ); i++)
	{
		x++;
	}
	
	cout << "Your string contains " << x << " letters." << endl;

	return 0;
}