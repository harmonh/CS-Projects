/********************************************************************************
**Program: ex10_4.cpp
**Author: Holly Harmon
**Description: For exercise 10 question 4. This program finds the sum of all
the multiples of 3 or 5 below 1000 and prints it to the user. I find you could
interpret this as a) either the sum of the multiples of 3 OR the sum of the 
multiples of 5 or as b) the sum of the multiples of 3 and the multiples of 5.
For my program I chose interpretation b.
**Input: none
**Output: Prints the sum  of all the multiples of 3 or 5 under 1000.
********************************************************************************/

#include <iostream>
using std::cout;
using std::endl;

int sum_multiples( );
//Uses a for loop going from ints 1 to 999 and % to find multiples of 3 or 5
//adding the multiples to int k as the loop progresses. 

int main ( )
{
	cout << "The sum of all of the multiples of 3 or 5 under 1000 is: " 
		<< sum_multiples() << endl;

	return 0;
}

int sum_multiples( )
{
	int k = 0;

	for(int i = 1; i < 1000; i++)
	{
		if(i % 3 == 0 || i % 5 == 0) //if % == 0, then it is a multiple
		{
			k += i;
		}
	}
	return k;
}