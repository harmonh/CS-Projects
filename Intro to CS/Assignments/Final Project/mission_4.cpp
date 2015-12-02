#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "harmonh.h"

using namespace Harmonh;
using std::cout;
using std::endl;
using std::cout;
using std::string;
using std::cin;

int main()
{
	srand(time(0));

	Human *cap;
	cap = new Human(35, 20);

	Alien *al;
	al = new Alien(20, 30);

	cout << "Oh no! An intruder has somehow beamed aboard your ship!\n";
	cout << "I wonder how they made it past the shields...\n";
	cout << "Quick, you need to attack." << endl << endl;

	while((cap->getLife() > 0) && (al->getLife() > 0)) {
		cout << "Press ENTER to attack.";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
		cout << endl;

		al->setLife(al->getLife() - cap->getDamage());
		if(al->getLife() < 0) {
			al->setLife(0);
		}
		else {
			cout << "The alien's life is now " << al->getLife() << " points." << endl << endl;
			cap->setLife(cap->getLife() - al->getDamage());
			if(cap->getLife() < 0) {
				cap->setLife(0);
			}
			cout << "Your life is now " << cap->getLife() << " points." << endl;
		}
	}

	if(al->getLife() == 0) {
		cout << "You've killed the intruder! I guess we'll never know what it\n";
		cout << "was really here for...\n";
		cout << "You are now ready to move on to a different sector.\n";
	}
	else {
		cout << "You have been gravely wounded by the alien's razor sharp claws.\n";
		cout << "Your crew managed to save you at the last minute, but you must\n";
		cout << "return to Earth for medical attention and recuperation.\n";
	}

	return 0;
}