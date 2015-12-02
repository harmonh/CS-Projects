/*********************************************************************************
**Program: exercise_4_2.cpp
**Author: Holly Harmon
**Description: Write a simple function that accepts two strings and returns whether
they have the same contents.
**Input: User is asked to input two strings.
**Output: Tells the user if the two strings contain the same content or not.
*********************************************************************************/ 

#include <iostream>
#include <string>
using namespace std;

void sameString (string wordOne, string wordTwo);
int main ()
{
	string wordOne, wordTwo;
	
	cout << "Please enter two strings: \n";
	cin >> wordOne >> wordTwo;

	sameString(wordOne, wordTwo);
}

void sameString (string wordOne, string wordTwo)
{
	if (wordOne == wordTwo)
	{
		cout << "These strings are the same.\n";
		return;
	}
	else {
		cout << "These strings are not the same.\n";
		return;
	}
}