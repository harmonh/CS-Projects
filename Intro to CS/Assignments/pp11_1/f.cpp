/***************************************************************************************************
**Program: pp11_1.cpp
**Author: Holly Harmon
**Description: Fpr Absolute C++ Programming Projects 11.1.
**Input: 
**Output: 
****************************************************************************************************/

#include <iostream>
#include "f.h"
using std::cout;
using std::endl;

namespace A
{
	void f( )
	{
		cout << "Function 'f' called." << endl;
		int x = 3;
		int y = 5;
		cout << "x = " << x << " and y = " << y << endl;
		int temp = x;
		x = y;
		y = temp;
		cout << "Now x = " << x << " and y = " << y << endl;
	}
}