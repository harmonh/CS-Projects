/********************************************************************************
**Program: ex10_3.cpp
**Author: Holly Harmon
**Description: For exercise 10 question 3. This program fills two 10 by 10
integer arrays with the integers from 1 to 100. Then calls a function with the
two filled arrays and a third empty array as arguments. The function multiplies
array1 and array2 and stores the product from the two arrays in the third array
named product_array.
**Input: 
**Output: Prints out the product of the two arrays (product_array).
********************************************************************************/

#include <iostream>
using std::cout;
using std::endl;

void fill_array(int array[][10]); //fills an array with ints 1 to 100
void print_array(long int array[][10]); //prints the array
void matrix_product(int array1[][10], int array2[][10], long int array3[][10]);
//Precondition: accepts three arrays, array1: 1 to 100, array2: 1 to 100,
//array3: an empty array.
//Postcondition: multiplies array1 by array2 as 10 by 10 matrices and stores the
//product in array3.

int main( )
{
	int array1[10][10], array2[10][10];
	long int product_array[10][10] = {{}};

	fill_array(array1);
	fill_array(array2);

	matrix_product(array1, array2, product_array);
	print_array(product_array);

	return 0;
}

void fill_array(int array[][10])
{
	int k = 1;
	for(int i = 0; i < 10; i++)
	{
		for(int n = 0; n < 10; n++) {
			array[i][n] = k++;
		}
	}
}

void print_array(long int array[][10])
{
	for(int i = 0; i < 10; i++)
	{
		for(int n = 0; n < 10; n++) {
			if(array[i][n] < 10000) {
				cout << array[i][n] << "  ";
			}
			else {
				cout << array[i][n] << " ";
			}
		}
		cout << endl;
	}	
}

void matrix_product(int array1[][10], int array2[][10], long int array3[][10])
{
  int i, n, k;
  for (i = 0; i<10; i++)
  {
    for (n = 0; n<10; n++)
    {
      for (k = 0; k<10; k++)
      {
        array3[i][n] += array1[i][k]*array2[k][n];
      }
    }
  }
}
