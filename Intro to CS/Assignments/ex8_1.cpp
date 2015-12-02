/*********************************************************************************
**Program: ex8_1.cpp
**Author: Holly Harmon
**Description: Creation of a struct named PersonInfo with member variables 'name'
and 'age'. Program takes user input and creates an instance of the struct, which
represents an individual.
**Input: The name and age of a person.
**Output: Program will assign the member variables to the user input and repeat
them back to the user.
*********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct PersonInfo
{
	char name[10];
	int age;
};

void personData(PersonInfo& myPerson);

int main()
{
	PersonInfo my_person;
	personData(my_person);
}

void personData(PersonInfo& myPerson)
{
	cout << "What is the person's name?\n";
	cin >> myPerson.name;
	cout << "What is the age of the person?\n";
	cin >> myPerson.age;
	cout << "The person's name is " << myPerson.name << ".\n";
	cout << "The person is " << myPerson.age << " years old.\n";
}