/*********************************************************************************
**Program: ex_7_2.cpp
**Author: Holly Harmon
**Description: For exercise set 7 question 2. This program creates a dynamic array 
and asks the user to input values into the array. The largest and smallest value 
input by the user are printed to the screen.
**Input: The user will input integer values to fill up a dynamic array (in this case
the array holds 10 values). If the user input anything other than an integer an error
message occurs and a new value must be entered. 
**Output: The user input is sorted in the array from lowest value to highest value. 
The program prints the first value in the array and the last value in the array, 
which are the smallest and largest values respectively.
*********************************************************************************/

#include <iostream>
#include <algorithm> //for sort funct
using namespace std;

void fillArray(int dyn_array[], int size);
//Precondition: The dyn_array is an empty one dimensional dynamic array currently set to hold
//10 values.
//Postcondition: User will input integer values to fill the array

int main ()
{
	const int ARRAY_SIZE = 10;
	int *array_ptr;
	array_ptr = new int[ARRAY_SIZE];
	
	fillArray(array_ptr, ARRAY_SIZE);
	
	//sort function sorts the values in the array from smallest to largest
	sort(array_ptr, array_ptr + ARRAY_SIZE);
	
	cout << "The largest value is: " << array_ptr[ARRAY_SIZE - 1] << endl;
	cout << "The smallest value is: " << array_ptr[0] << endl;
	
	delete [] array_ptr;
	
	return 0;
}

void fillArray(int dyn_array[], int size)
{
	cout << "Please enter 10 integer values to fill in the array.\n";
		for (int i = 0; i < size; i++)
		{
			cin >> dyn_array[i];
			while(cin.fail())
			{	
				cout << "Not an integer, try again.\n";
				cin.clear();
				cin.ignore(255, '\n');
				cin >> dyn_array[i];
			}
		}
}
