/*********************************************************************************
**Program: 7_1_command_line.cpp
**Author: Holly Harmon
**Description: For exercise set 7 question 5: a command line argument friendly 
version of set 7 question 1. A program that excepts a command line argument in the 
form of an integer value and then calls a function that assigns that value to a 
variable by way of a pointer.
**Input: User has no input. Input is entered in the command line.
**Output: The program converts the value of the argument entered in command line from a char to an int. The int value is then assigned to a pointer pointing to an integer variable. The program then prints the value of the int variable, the dereferenced pointer value, and the value (address) of the pointer itself to the user.
*********************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

void ptr_function(char *argv[]);

int main (int argc, char *argv[])
{
	ptr_function(argv);
	
	return 0;
}

void ptr_function(char *argv[])
{
	int var1;
	int *var1_ptr;
	var1_ptr = &var1;
	*var1_ptr = atoi(argv[1]);

	cout << "'var1' = " << var1 << endl;
	cout << "'*var1_ptr' = " << *var1_ptr << endl;
	cout << "The address of 'var1' and value of 'var1_ptr' = " << var1_ptr << endl;
}