/*********************************************************************************
**Program: videogame_b.cpp
**Author: Holly Harmon
**Description: Program for Absolute C++ Programming Projects 1.9(b). Asks the user 
how many coupons they've won playing video games and tells them first how many candy
bars they can get and then how many gumballs they can get with the remaining coupons.
Finally lets them know how many coupons are left over.
**Input: The user inputs an integer value that is the number of coupons they've won.
**Output: The number of coupons input by the user is run through two while loops. 
First loop decreases the number of coupons by 10 and increases the number of candy 
bars by one, to let the user know how many candy bars they may get. The second loop 
decreases the remaining coupons by 3 and the number of gumballs by one, to let the 
user know how many gumballs they may get. Finally the program outputs the number of 
tickets remaining after both loops have run.
*********************************************************************************/

#include <iostream>
using namespace std;

int main ( )
{
	int coupons; //User input number of coupons
	int candyBar;
	int gumBall;
	candyBar = 0;
	gumBall = 0;
	
	cout << "How many coupons did you win? ";
	cin >> coupons;
	
	//While loop runs while the number of coupons 
	//is greater than or equal to 10
	while (coupons >= 10)
	{
		coupons = coupons - 10; //decreases coupons by 10
		candyBar++; //increases candy bars by 1
	}
	
	//Tells the user how many candy bars they can get
	cout << "Congratulations! You can get " << candyBar 
		<< " candy bar(s) ";
	
	//While loop run while the number of coupons
	//is greater than or equal to 3
	while (coupons >= 3)
	{
		coupons = coupons - 3; //decreases coupons by 3
		gumBall++; //increases gumballs by 1
	}
	
	//Tells the user how many gumballs they can get
	cout << "and " << gumBall << " gumball(s).\n";
	//Prints out the remaining coupons
	cout << "You have " << coupons << " coupons left.\n";
	
	return 0;
}
