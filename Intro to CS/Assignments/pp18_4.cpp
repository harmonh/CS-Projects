/********************************************************************************
**Program: pp18_4.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Project 18.4. This program uses two
arrays, one to hold product IDs (as ints) and one to store product names (as
strings). The function getProductID is called and returns the ID of whichever
product has been input. If the product is not in the list, the user is told
it is not on the product list.
**Input: none
**Output: When the function is called it prints out the ID number of the product
being requested. If the product does not exist an exception is thrown and the 
user is told the product is not on the list.
********************************************************************************/

#include <iostream>
#include <cctype>

using std::string;
using std::cout;
using std::endl;

void getProductID( int ids[], string names[], int numProducts, string target);

int main() // Sample code to test the getProductID function
{
	int productIds[] = {4, 5, 8, 10, 13};
	string products[] = {"computer", "flash drive", "mouse", "printer", "camera"};

	getProductID(productIds, products, 5, "Mouse");
	getProductID(productIds, products, 5, "camera");
	getProductID(productIds, products, 5, "laptop");

	return 0;
}

void getProductID( int ids[], string names[], int numProducts, string target)
{
	for (string::size_type i = 0; i < target.length(); i++)
	{
		target[i] = tolower (target[i]);
	}	
	try
	{
		for ( int i = 0; i < numProducts; i++)
		{
			if (names[i] == target)
			{	cout << ids[i] << endl;
				return;
			}
		}
		throw target;
		//return -1; // Not found
	}	
	catch(string target)
	{
		cout << "\'" << target << "\'" << " is not a product on the list.\n";
	}
}

