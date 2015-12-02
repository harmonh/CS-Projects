/*********************************************************************************
**Program: pp13_8.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Project 13.8. This program excepts an 
initial deposit amount, an interest rate per year, and the number of years the money 
will accrue compound interest from the user. The program then lets the user know how 
much money will be in their account after the number of years they input.
**Input: User inputs their initial deposit amount (as int or double) into a savings 
account, the yearly interest rate as a decimal (double), and the number of years 
their money will be in the account.
**Output: Using a recursive function, the program takes the user input and calculates 
the amount of money that will be in the savings account after the number of years 
input by the user. That amount is then returned and output to the user.
*********************************************************************************/

#include <iostream>
using namespace std;

double savings_account(double amount, double rate, int years);

int main()
{
	double depositAmount;
	int years;
	double interestRate;
	
	cout << "How much is you initial deposit? ";
	cin >> depositAmount;
	cout << "How many years will this account be accruing interest? ";
	cin >> years;
	cout << "What is the interest rate per year in decimal? ";
	cin >> interestRate;
	cout << "Your total after " << years << " years will be: "
		<< savings_account(depositAmount, interestRate, years) << endl;
	
	return 0;
}

double savings_account(double amount, double rate, int years)
{
	if(years > 0)
	{
		amount = amount * (rate + 1);
		savings_account(amount, rate, (years - 1));
	}
}