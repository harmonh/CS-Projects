/*********************************************************************************
**Program: pp3_5.cpp
**Author: Holly Harmon
**Description: For Programming Projects 3.5 This program gets the height, weight and
age of the user then uses three functions to tell them their hat size, jacket size, 
and waist measurement.
**Input: User inputs their height in inches, their weight in pounds, and their age.
**Output: The program outputs the users hat size, jacket size, and waist measurement.
The numbers being output have been truncated to two decimal points to make the numbers
a little cleaner looking. If I went back to improve the program I would probably have 
it round the results to even inches or integers, but that was not specified in the 
problem instructions, so I went with this solution.
*********************************************************************************/

#include <iostream>
using namespace std;
	
double hatSize (double weight, double height);
double jacketSize (double weight, double height, int age);
double waistInInches (double weight, int age);

int main ( )
{
	char repeat;
	
	do
	{
		double height, weight;
		double hat_Size, jacket_Size, waist_Size;
		int age;
		
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
	
		cout << "Enter your height in inches: ";
		cin >> height;
		cout << "Enter your weight in pounds: ";
		cin >> weight;
		cout << "Enter your age in years: ";
		cin >> age;
	
		hat_Size = hatSize(weight, height);
		jacket_Size = jacketSize(weight, height, age);
		waist_Size = waistInInches(weight, age);
	
		cout << "Your hat size is " << hat_Size << ".\n";
		cout << "Your jacket size is " << jacket_Size << " inches.\n";
		cout << "Your waist size is " << waist_Size << " inches.\n";
		
		cout << "Would you like to calculate your sizes again? (y/n): ";
		cin >> repeat;
		cout << endl;
		
	} while ((repeat == 'y') || (repeat == 'Y'));
	
	return 0;
	
}

double hatSize (double weight, double height)
{
	return ((weight / height) * 2.9);
}

double jacketSize (double weight, double height, int age)
{
	double addedInch;
	addedInch = (((age - 30) / 10) * 0.125);
	if (addedInch > 0)
	{
		return (((height * weight) / 288) + addedInch);
	}
	else
	{
		return ((height * weight) / 288);
	}
}

double waistInInches (double weight, int age)
{
	double addedInch;
	addedInch = (((age - 28) / 2) * 0.1);
	if (addedInch > 0)
	{
		return ((weight / 5.7) + addedInch);
	}
	else {
		return (weight / 5.7);
	}
}
