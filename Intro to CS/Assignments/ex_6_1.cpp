/*********************************************************************************
**Program: ex_6_1.cpp
**Author: Holly Harmon
**Description: For excercise set 6 question 1. The user input 5 integer values 
and the program prints the sum of those values. 
**Input: User inputs 5 integer values that are entered into an array.
**Output: The values input by the user are added together and the sum is printed 
to the user.
*********************************************************************************/
#include <iostream>
using namespace std;

int main()
{
	int input[5];
	int sumArray = 0; //variable to be assaigned to the sum of the array values
	
	cout << "Input 5 integer values: \n";
	for(int i = 0; i < 5; i++)
	{
		cin >> input[i];
		
		//checks if user input is not an integer
		while(cin.fail())
		{
			cout << "Not an integer, try again.\n";
			cin.clear();
			cin.ignore(255, '\n');
			cin >> input[i];
		}
	}
	for(int i = 0; i < 5; i++)
	{
		sumArray = sumArray + input[i];
	}
	
	cout << "The sum of your values is " << sumArray << endl;
    
	return 0;
}