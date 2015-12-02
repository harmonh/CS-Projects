/*********************************************************************************
**Program: videogame_a.cpp
**Author: Holly Harmon
**Description: Program for Absolute C++ Programming Projects 1.9(a). Asks the user 
how many coupons they've won playing video games and tells them first how many candy 
bars they can get and then how many gumballs they can get.
**Input: The user inputs an integer value that is the number of coupons they've won.
**Output: The number of coupons input by the user is divided by 10 to determine how 
many candy bars they can get. Then the remainder of the coupons after it's divided 
by 10 is divided by 3 to determine how many gumballs they can get. Both results are
printed out to the user.
*********************************************************************************/

#include <iostream>
using namespace std;

int main ( )
{
	int coupons; //Number of coupons input by the user
	
	cout << "How many coupons did you win? ";
	cin >> coupons;
	
	cout << "Great job!\n";
	//determines number of candy bars through division
	cout << "You can get " << coupons / 10 << " candy bar(s)" 
		//determines number of gumballs through remainders and division
		" and " << (coupons % 10) / 3 << " gumball(s).\n";
		
	return 0;
}
