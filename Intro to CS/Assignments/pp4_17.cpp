/*********************************************************************************
**Program: pp4_17.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Projects 4.17. The program calls a 
function that takes three integer parameters (a, b, c) by reference and rearranges
them so that the first parameter is set to the smallest value, the second to the
second smallest value, and the third parameter to the largest value. Then prints out
the new values for a, b, c. AUTHORS NOTE: I don't know if my function was the most
efficient or prettiest way to rearrange all of the values from least to greatest, but
it's how I managed it.
**Input: None
**Output: The "sort()" function takes three arguments (a, b, and c) and assigns the
lowest value to int1, the second lowest value to int2, and the largest value to int3.
Since the function contains call-by-reference parameters, than a, b, and c get
reassigned accordingly. The program prints a, b, and c with their new values (lowest
to highest)
*********************************************************************************/

#include <iostream>
using namespace std;

//declaration of function to sort 3 integers
int sort(int& int1, int& int2, int& int3);

int main()
{
	int a, b, c;
	a = 30;
	b = 10;
	c = 20;
	sort(a, b, c);
	//prints a, b, and c from least to greatest value
	cout << "a = " << a << " b = " << b << " c = " << c << endl;
	
	return 0;
}

//Function uses if-else to determine largest, second largest, and lowest integer
//Probably could have been done in fewer steps/less complicated??
int sort(int& int1, int& int2, int& int3)
{
	int temp1, temp2, temp3;
	if(int1 > int2)
	{
		if(int1 > int3)
		{
			temp3 = int3;
			int3 = int1;
			if(int2 > temp3)
			{
				int1 = temp3;
				return int1, int2, int3; //done a > b > c
			}
			else
			{
				int1 = int2;
				int2 = temp3;
				return int1, int2, int3; //done a > c > b
			}
		}
		else
		{
			temp2 = int2;
			int2 = int1;
			int1 = temp2;
			return int1, int2, int3; //done c > a > b
		}
	}
	else
	{
		if(int1 > int3)
		{
			temp1 = int1;
			temp2 = int2;
			int1 = int3;
			int2 = temp1;
			int3 = temp2;
			return int1, int2, int3; //done b > a > c
		}
		else
		{
			if(int2 > int3)
			{
				temp3 = int3;
				int3 = int2;
				int2 = temp3;
				return int1, int2, int3; //done b > c > a
			}
			else
			{
				return int1, int2, int3; //done c > b > a
			}
		}
	}
}