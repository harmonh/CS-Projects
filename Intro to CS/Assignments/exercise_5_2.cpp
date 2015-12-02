/*********************************************************************************
**Program: exercise_5_2.cpp
**Author: Holly Harmon
**Description: From Exercise Set 5, Question 2. This program excepts two strings 
from the user and tells them if the strings are the same or not.
**Input: User inputs two strings.
**Output: The user input is accepted by a function that checks if the user's two strings
have the same contents. If the contents are the same, the program prints that they have the
same contents. If the contents are NOT the same, the program prints that they do not have
the same contents.
*********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//function declaration, compares two strings
void same_strings(string str1, string str2);
int main ()
{
	string input1;
	string input2;
	
	//user inputs two strings of their choice
	cout << "Input two strings:\n";
	cin >> input1 >> input2;
	same_strings(input1, input2); //calls function to compare strings input by user
	
	return 0;
}

void same_strings(string str1, string str2)
{
	if(str1 == str2)
	{
		cout << "These strings have the same contents.\n";
	}
	else
	{
		cout << "These strings do not have the same contents.\n";
	}
}