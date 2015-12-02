/*********************************************************************************
**Program: echo.cpp
**Author: Holly Harmon
**Description: This program asks the user for an integer and then tells them what 
 integer they entered.
**Input: User inputs an integer
**Output: Tells the user what they input
*********************************************************************************/

#include <iostream>
using namespace std;

int main ( )
{
	int userNumber;
	
	cout << "Please input an integer: ";
	cin >> userNumber;
	
	
	cout << "The integer you entered is " << userNumber << endl;

	return 0;
}
