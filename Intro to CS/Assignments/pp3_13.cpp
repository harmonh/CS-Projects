/*********************************************************************************
**Program: pp3_13.cpp
**Author: Holly Harmon
**Description: For Programming Project 3.13. Chooses 4 random winners from a pool of 25.
**Input: none
**Output: 4 random number **Did not get a chance to fix the multiples of the same number
getting chosen. The numbers are random each time, but within the 4 numbers there are 
still repeats :(**
*********************************************************************************/ 

#include <iostream>
#include <cstdlib> //needed for rand function
//#include <ctime> //needed for the srand-time function
using namespace std;

int main ( )
{	
	int i;
	
	cout << "Your four finalists are: \n";
	
	srand(time(0));	
	for (i = 0; i < 4; i++)
	{
		int randWinner;
		//srand(time(0));
		randWinner = rand() % ((26) - 1) + 1;
		cout << randWinner << endl;
	}
}
