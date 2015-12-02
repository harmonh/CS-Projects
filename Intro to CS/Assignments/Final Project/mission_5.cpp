#include <iostream>
#include <string>
#include "namespace1.h"

using namespace Harmonh;
using std::cout;
using std::endl;
using std::cin;
using std::string;



int main()
{	
	int asts = 4;
	string* a;
	string ast_array[16] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", 
								"13", "14", "15", "16"};
	a = ast_array;

	cout << "You've jumped into the middle of an asteroid field!\n";
	cout << "One has made impact and your sensors are offline. You're shooting blind!!!\n";
	cout << "You need to destroy the asteroids before they get to you!\n";
	cout << "You have 8 shots before they reach the ship and it is too late." << endl << endl;

	cout << "Choose a numbered location to shoot at\n";

	print_array(a);
	cout << endl;
	
	
	asteroid_shoot(a, asts);

	if(asts == 0) {
		cout << "You did it! The ship makes it safely through the asteroid field\n";
		cout << "and you are free to move on to a different sector.\n";
	}
	else {
		cout << "You ran out of time and the ship was impacted by " << asts << " asteroids\n";
		cout << "It is too damaged to go on and you must return to Earth for repairs.\n";
	}

	return 0;
}

