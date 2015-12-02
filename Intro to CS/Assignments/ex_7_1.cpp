/*********************************************************************************
**Program: ex_7_1.cpp
**Author: Holly Harmon
**Description: For exercise set 7 question 1. A program that calls a function 
that asks the user to input a value (integer) to be assigned to a variable by 
way of a pointer.
**Input: User inputs an integer value.
**Output: The program assigns the input value to a pointer pointing to an 
integer variable. The program then prints the value of the int variable, the 
dereferenced pointer value, and the value (address) of the pointer itself to the 
user.
*********************************************************************************/

#include <iostream>
using namespace std;

void ptr_function();

int main ()
{
	ptr_function();
	
	return 0;
}

void ptr_function()
{
	int var1;
	int *var1_ptr; //pointer
	var1_ptr = &var1;
	
	cout << "Enter an integer to be assigned to 'var1': ";
	cin >> *var1_ptr;
	cout << "'var1' = " << var1 << endl;
	cout << "'*var1_ptr' = " << *var1_ptr << endl;
	cout << "The address of 'var1' and value of 'var1_ptr' = " << var1_ptr << endl;
}