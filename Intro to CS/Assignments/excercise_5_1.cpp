/*********************************************************************************
**Program: exercise_5_1.cpp
**Author: Holly Harmon
**Description: For exercise set 5 question 1. Generates a random number between a
user's chosen range and sets that value to the &val parameter/val argument. 
**Input: Random number max and min range. 
**Output: A random number between the users max and min is set to the value "val"
*********************************************************************************/

#include <iostream>
#include <cstdlib> //needed for rand function
#include <ctime> //needed for the srand-time function
using namespace std;

//random number generator function declaration with a call-by-reference parameter
int rand_int(int min, int max, int &val); 

int main ( )
{
	int minNumber, maxNumber;
	int	val = 0;
	
	cout << "Enter a top and bottom integer range for the random"
		<< " number generator.\n";
	cout << "Minimum: ";
	cin >> minNumber;
	cout << "Maximum: ";
	cin >> maxNumber;
	cout << endl;
	
	//random number function call
	rand_int(minNumber, maxNumber, val);
	
	//val will be set as whatever random number the rand_int function provides
	cout << "'val' is now set to " << val << ".\n";
}

//the function inputs the user's minimum and maximum range for the random
//number they want and that random number is set to "val"
int rand_int(int min, int max, int &val)
{
	srand(time(0));
	val = rand() % ((max + 1) - min) + min;
}

















