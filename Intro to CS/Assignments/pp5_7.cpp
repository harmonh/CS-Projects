/*********************************************************************************
**Program: pp5_7.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Projects 5.7. Generates a text-based 
histogram for a quiz given to a class of students. Prints the number of students 
who scored a 0, 1, 2, 3, 4, or 5 on the quiz (graded on a scale from 0-5). Can 
handle any number of students input by the user.
**Input: User inputs the number of students whose grades they would like to 
enter, then enters the score for each student. If the user attempts to enter a 
non-integer or an integer outside of the grade scale an error message is returned.
**Output: The program asks the user for the grades from however many students 
they entered and tallies the scores using an array for the 6 different grade 
scores. Once all scores are entered the program prints the number of quizes that 
received the different scores from 0 to 5.
*********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	
	int grades[6] = {0, 0, 0, 0, 0, 0}; //array counts up quiz grades
	int numberOfStudents;
	int gradeValue;
	
	cout << "How many student grades would you like to enter?\n";
	cin >> numberOfStudents;
	while(cin.fail()) //checks for integer
		{
			cout << "Not an integer, try again.\n";
			cin.clear();
			cin.ignore(255, '\n');
			cin >> numberOfStudents;
		}
	cout << endl;
	
	cout << "Enter the grade, from 0 to 5, for each student: \n";
	for(int i = 0; i < numberOfStudents; i++)
	{
		cin >> gradeValue;
		
		while(cin.fail() || (gradeValue > 5)) //checks for integer
		{
			cout << "Not an integer between 0 and 5 inclusive, try again.\n";
			cin.clear();
			cin.ignore(255, '\n');
			cin >> gradeValue;
		}
		
		//increments the corresponding score value in the array by 1
		grades[gradeValue]++;
		
	}
	cout << endl;
	
	//prints out the histogram
	for(int i = 0; i < 6; i++)
	{
		cout << grades[i] << " grade(s) of " << i << endl;
	}

	return 0;
}