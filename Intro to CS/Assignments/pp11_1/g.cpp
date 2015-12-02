#include <iostream>
#include "g.h"
using std::cout;
using std::endl;

namespace A
{
	void g( )
	{
		cout << "Function 'g' called." << endl;
		int x = 7;
		int y = 10;
		cout << "x = " << x << " and y = " << y << endl;
		int temp = x;
		x = y;
		y = temp;
		cout << "Now x = " << x << " and y = " << y << endl;
	}
}