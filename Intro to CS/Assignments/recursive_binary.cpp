/*********************************************************************************
**Program: recursive_binary.cpp
**Author: Holly Harmon
**Description: The book was a little confusing on which section of code to use
for 16.1 and 16.2. This program uses the function from Display 13.7 and can be
used for either Excersize Set 16 question 1 or question 2.
Contains a template function for searching an array of variables. Can be used with
any types you can use in an array: int, double, char, and string. Since the values
are not sorted, only searched, strings are usable.
**Input: User inputs a value to be searched for.
**Output: Program implements the search function, a recursive function that
searches an array for a match to the user input variable. If the variable is found
it will print out it's location in the array. If it is not found, it prints out
that the variable is not in the array.
*********************************************************************************/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int ARRAY_SIZE = 10;

template<class T>
void search(const T a[ ], int first, int last, T key, bool& found, 
				int& location);
//Precondition: a[first] through a[last] are sorted in increasing
//order.
//Postcondition: if key is not one of the values a[first] through
//a[last], then found == false; otherwise, a[location] == key
//and found == true.

int main( )
{
	//Different arrays used for testing:
	//string a[3] = {"help", "menu", "set"};
	//char a[ARRAY_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	//double a[ARRAY_SIZE] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2};
	
	int a[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const int finalIndex = ARRAY_SIZE - 1;
	int key; //needs to change type to match array type
	int location;
	bool found;
	
	cout << "Enter variable to be located: ";
	cin >> key;
	search(a, 0, finalIndex, key, found, location);
	if (found)
	{	
		cout << key << " is in index location " << location << endl;
	}
	else {
		cout << key << " is not in the array." << endl;
	}

	return 0;
}

template<class T>
void search(const T a[ ], int first, int last, T key, bool& found, 
				int& location)
{
	int mid;
	if (first > last)
	{
		found = false ;
	}
	else
	{
		mid = (first + last)/2;
		if (key == a[mid])
		{
			found = true ;
			location = mid;
		}
		else if (key < a[mid])
		{
			search(a, first, mid - 1, key, found, location);
		}
		else if (key > a[mid])
		{
			search(a, mid + 1, last, key, found, location);
		}
	}
}