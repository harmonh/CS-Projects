/*********************************************************************************
**Program: pp3_1.cpp
**Author: Holly Harmon
**Description: Tells the user how many miles per gallon their vehicle gets.
**Input: User inputs the number of liters they have used and the number of miles 
they have driven.
**Output: The program plugs the user input into a function designed to give the 
miles per gallon. The function converts the liters input by the user to gallons,
then divides the number of miles by the number of gallons. The function returns 
the miles per gallon value to the program and it prints out the MPG to the user. 
*********************************************************************************/ 

#include <iostream>
using namespace std;
	
const double LITERS_GALLON = 0.264179;
	
double milesPerGallon(int miles, double liters);

int main ( )
{
	char repeat;
	
	do
	{
		double liters, perGallon;
		int milesDriven;
	
		cout << "Enter the number of liters used: ";
		cin >> liters;
		cout << "Enter the number of miles driven: ";
		cin >> milesDriven;
	
		perGallon = milesPerGallon(milesDriven, liters);
	
		cout << "Your vehicle gave you " << perGallon << " miles per gallon.\n";
		
		cout << "Would you like to do another calculation? (y/n): ";
		cin >> repeat;
		cout << endl;
		
	} while ((repeat == 'y') || (repeat == 'Y'));
	
	return 0;
	
}

double milesPerGallon (int miles, double liters)
{
	return (miles / (liters * LITERS_GALLON));
}