/*********************************************************************************
**Program: maxoccupancy.cpp
**Author: Holly Harmon
**Description: Program for Absolute C++ Programming Projects 1.5. This program 
determines whether a meeting room is in violation of fire law. The user inputs the 
maximum occupancy of the room and the number of people planning to attend. The 
program will output if the meeting can legally be held and how many people need to 
be excluded or how many more people can attend.
**Input: The user inputs the maximum occupancy of a meeting room according to fire 
regulations. The user then inputs the number of people planning to attend the meeting.
**Output: If the meeting attendance the user input is less than or equal to the 
max occupancy the program will output that the meeting is legal and let the user 
know how many more people may attend. If the attendance is greater than the max 
occupancy the program will output that the meeting it not legal and let the user know 
how many people must be excluded.
*********************************************************************************/

#include <iostream>
using namespace std;

int main() 
{
	int maxOccupancy; //Maximum occupancy according to fire regulation
	int attendance; //Number of people attending
	
	cout << "According to fire regulations\n"
		<< "what is the maximum capacity of your meeting room? ";
	cin >> maxOccupancy;
		
	cout << "How many people are planning to attend your meeting? ";
	cin >> attendance;
	cout << endl;
	
	//if else to determine legality of meeting occupancy
	if (attendance <= maxOccupancy) 
	{	//Prints if meeting is legal
		cout << "It is legal to hold your meeting!\n"
			//figures out how many more can attend
			<< "You may allow " << maxOccupancy - attendance <<
			" more people to attend your meeting.\n";
	}
	else //will print if attendance exceeds max occupancy
	{
		cout << "According to fire regulations you have too many people\n"
			<< "attending your meeting and it cannot be held as planned.\n"
			//figures out how many need to be excluded
			<< "In order to legally hold your meeting "
			<< attendance - maxOccupancy << " people must be excluded.\n";
	}
	
	return 0;
}