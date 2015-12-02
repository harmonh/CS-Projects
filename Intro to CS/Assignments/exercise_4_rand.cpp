/*********************************************************************************
**Program: pp3_1.cpp
**Author: Holly Harmon
**Description:
**Input:
**Output:
*********************************************************************************/

#include <iostream>
#include <cstdlib> //needed for rand function
#include <ctime> //needed for the srand-time function
using namespace std;

//random number generator function declaration
int rand_int(int min, int max); 

int main ( )
{
	int minNumber, maxNumber, randNumber;
	
	cout << "Enter a top and bottom integer range for the random"
		<< " number generator.\n";
	cout << "Minimum: ";
	cin >> minNumber;
	cout << "Maximum: ";
	cin >> maxNumber;
	cout << endl;
	
	//random number function call
	randNumber = rand_int(minNumber, maxNumber);
	
	cout << "Your random number is " << randNumber << ".\n";
}

//the function inputs the user's minimum and maximum range for the random
//number they want. The function uses srand and time to produce a variable seed
//number, then the function finds a random number in the user's range and
//returns that number.
int rand_int(int min, int max)
{
	int randNumber;
	
	//using time as a random seed for srand
	srand(time(0));
	//defines the min and max range for the random number
	randNumber = rand() % ((max + 1) - min) + min;
	return randNumber;
}