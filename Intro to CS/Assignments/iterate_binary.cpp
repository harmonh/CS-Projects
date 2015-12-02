/*********************************************************************************
**Program: iterate_binary.cpp
**Author: Holly Harmon
**Description: The book was a little confusing on which section of code to use
for 16.1 and 16.2. This program can be used for either Excersize Set 16 question 
1 or question 2. It uses a while loop instead of recursion to search through the
array.
Contains a template function for searching an array of variables. Can be used with
any types you can use in an array: int, double, char, and string. Since the values
are not sorted, only searched, strings are usable.
**Input: User inputs a value to be searched for.
**Output: Program implements the search function, a function that
searches an array for a match to the user input variable using a loop that exits
once the variable has been found or is found to not be in the array. If the variable
is found it will print out it's location in the array. If it is not found, it prints
out that the variable is not in the array.
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
//Uses a while loop instead of recursion.

int main()
{
	//Different arrays used for testing:
	//string a[3] = {"help", "menu", "set"};
	char a[ARRAY_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	//double a[ARRAY_SIZE] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2};

	//int a[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const int finalIndex = ARRAY_SIZE - 1;
	char key; //needs to change type to match array type
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
	int i = 0;
	while(i == 0) {
		if(first > last) { //A stopping case
			found = false;
			i = 1;
		}
		else
		{
			mid = (first + last)/2;
			if (key == a[mid]) //A stopping case
			{
				found = true;
				location = mid;
				i = 1;
			}
			else if (key < a[mid]) { //A case with recursion
				last = (mid - 1);
			}
			else if (key > a[mid]) {
				first = (mid + 1);
			} //A case with recursion
		}
	}
}