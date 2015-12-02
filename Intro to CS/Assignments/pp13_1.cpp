/*********************************************************************************
**Program: pp13_1.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Project 13.1. Prints out the Fibonacci
number at the nth place.
**Input: none
**Output: Uses a recursive function to go through the sequence of numbers and return
the value at position n. Prints result to the user.
*********************************************************************************/

/*Write a recursive function definition for a function that has one parameter n of
type int and that returns the n th Fibonacci number. The Fibonacci numbers are
F0 is 1, F1 is 1, F2 is 2, F3 is 3, F4 is 5, and in general
Fi+2 = Fi + Fi+1 for i = 0, 1, 2, ...*/

#include <iostream>
using namespace std;

int fibonacci(int n);

int main()
{
	int n = 5; //at the nth position in the sequence
	cout << "The Fibonacci number at place '" << n << "' is " << fibonacci(n) << endl;
	
	return 0;
}

//function for the nth Fibonacci number
int fibonacci(int n)
{
	if((n == 1) || (n == 0)) //both return 1
	{
		return 1;
	}
	else
	{
		//using f(n) = f(n-1) + f(n-2)
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}