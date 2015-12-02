/*********************************************************************************
**Program: cerealbox.cpp
**Author: Holly Harmon
**Description: Program for Absolute C++ Programming Projects 1.1. Converts the weight 
of a box of cereal from ounces to metric tons and tells the user how many boxes it 
would take to make one metric ton of cereal.
**Input: The user inputs the number of ounces a box of cereal weighs. Can be an 
integer or floating point number and no need to write "ounces."
**Output: The input weight of the box of cereal in metric tons in output to the 
user. The number of cereal boxes in one metric ton is calculated and output to the user.
*********************************************************************************/

#include <iostream>
using namespace std;

int main ( ) 
{
	double packageCerealOunces; //Weight of the cereal in ounces
	const float ONE_TON = 35273.92;  //Number of ounces in a ton as constant
	
	//Asks the user to input cereal weight in ounces
	cout << "How many ounces does a package of breakfast cereal weigh?\n";
	cin >> packageCerealOunces;
	
	//Converts cereal weight from ounces to metric tons 
	cout << "One package of breakfast cereal weighs " 
		<< packageCerealOunces / ONE_TON << " tons.\n";
	
	//Number of boxes to make a metric ton 
	cout << "You need " << 35273.92 / packageCerealOunces
		<< " boxes to yield one metric ton of cereal." << endl;
	
	return 0;
}
