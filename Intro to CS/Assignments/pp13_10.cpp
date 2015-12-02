/*********************************************************************************
**Program: pp13_10.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Project 13.10. This program tells the
user the number of bowling pins that would exist in a pyramid with n rows (if the
number of pins in row n is equal to n).
**Input: User inputs the number of rows of pins, which is assigned to n.
**Output: Program uses a recursive function that adds up the number of pins from row
1 to row n for the total number of pins. Then outputs the number of pins to the user.
*********************************************************************************/

#include <iostream>
using namespace std;

int pins(int n); //function to total number of pins

int main()
{
	int n;
	//input from user: number of rows
	cout << "How many rows of bowling pins are there?\n";
	cin >> n;
	cout << "There are " << pins(n) << " bowling pins.\n";
	
	return 0;
}

//recursive function for number of pins.
//Number of pins is n+(n-1)+(n-2)+(n-3)...etc until n reaches 0.
int pins(int n)
{
	if(n > 0)
	{
		return (n + pins(n-1));
	}
}