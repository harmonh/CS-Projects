/*********************************************************************************
**Program: pp14_9.cpp
**Author: Holly Harmon
**Description: Defines creature classes for a fantasy role-playing game including
humans, elves, cyberdemons, and balrogs. Program has a base class Creatures with 
derived classes for Human, Elf, and Demon, and Demon has derived classes for 
Cyberdemon and Balrog. Each class creates objects with member variables for setting 
a creature's strength and hitpoints. They also each contain a function that calculates 
the damage each creature can do in an attack. Elves, Cyberdemons, and Balrogs have 
special attacks that are defined in their specified classes.
**Input: Chooses y or n to continue calculating creature attack damage.
**Output: Creates a creature from each class: Human and Cyberdemon are set to
defaults, and Elf and Balrog have set strengths and hitpoints. Prints out attack
damage until user chooses to exit.
*********************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Creature
{
	private:
		int strength; // How much damage we can inflict
		int hitpoints; // How much damage we can sustain
		string getSpecies(); // Returns type of species
	public:
		Creature( );
		// Initialize to 10 strength and 10 hit points
		Creature(int newStrength, int newHit);
		// Initialize creature to new type, strength, hit points

		int setStrength(int newStrength);
		int setHit(int newHit);
		int getStrength();
		int getHit();
		int getDamage();
		// Returns amount of damage this creature
		// inflicts in one round of combat
};

class Human : public Creature
{
public:
	Human();
	//Initializes to Creature() defaults
	Human(int newStrength, int newHit);
	int getDamage();

private:
	string getSpecies( );

};

class Elf : public Creature
{
public:
	Elf();
	//Initializes to Creature defaults
	Elf(int newStrength, int newHit);
	int getDamage();

private:
	string getSpecies( );

};

class Demon : public Creature
{
public:
	Demon();
	//Initializes to Creature defaults
	Demon(int newStrength, int newHit);
	int getDamage();
	int getStrength(); //Accesses strength from base class

private:
	//empty
};

class Cyberdemon : public Demon
{
public:
	Cyberdemon();
	//Initializes to Demon default then to Creature default
	Cyberdemon(int newStrength, int newHit);
	int getDamage();

private:
	string getSpecies( );
};

class Balrog : public Demon
{
public:
	Balrog();
	//Initializes to Demon default then to Creature default
	Balrog(int newStrength, int newHit);
	int getDamage();

private:
	string getSpecies( );
};

//*****************************//
int main ()
{
	srand(time(0)); //Seed for rand()
	char ans; //for attack loop

	class Human human1; //set default
	class Elf elf1(20, 40); //strength = 20, hitPoints = 40
	class Cyberdemon cyber1; //set default
	class Balrog balrog1(30, 45); //strength = 30, hitPoints = 45

	cout << "A human has been created and set to default strength of "
		<< human1.getStrength() << endl;
	cout << " and default hit points of " << human1.getHit() << ".\n";

	cout << "An elf has been created and set to a strength of "
		<< elf1.getStrength() << endl;
	cout << " and hit points of " << elf1.getHit() << ".\n";
	
	cout << "A cyberdemon has been created and set to default strength of "
		<< cyber1.getStrength() << endl;
	cout << " and default hit points of " << cyber1.getHit() << ".\n";

	cout << "A balrog has been created and set to a strength of "
		<< balrog1.getStrength() << endl; 
	cout << " and hit points of " << balrog1.getHit() << "." << endl << endl;
	
	//Gets attack damage while user chooses 'y'
	do
	{
		cout << "** ";
		human1.getDamage();
		cout << "** ";
		elf1.getDamage();
		cout << "** ";
		cyber1.getDamage();
		cout << "** ";
		balrog1.getDamage();
		cout << endl;
		cout << "Would you like to attack again? (y/n): ";
		cin >> ans;
		cout << endl;
	} while(ans == 'y' || ans == 'Y');

	return 0;
}

Creature::Creature( )
{
	strength = 10;
	hitpoints = 10;
}

Creature::Creature(int newStrength, int newHit)
{
	strength = newStrength;
	hitpoints = newHit;
}

int Creature::setStrength(int newStrength)
{
	strength = newStrength;
}

int Creature::setHit(int newHit)
{
	hitpoints = newHit;
}

int Creature::getStrength()
{
	return strength;
}

int Creature::getHit()
{
	return hitpoints;
}

int Creature::getDamage()
{
	int damage;
	// All creatures inflict damage, which is a
	// random number up to their strength

	damage = (rand( ) % strength) + 1;
	return damage;
}

Human::Human( ) : Creature( )
{
	//empty
}

Human::Human(int newStrength, int newHit) : Creature(newStrength, newHit)
{
	//empty
}

int Human::getDamage()
{
	int damage = Creature::getDamage();
	cout << getSpecies() << " attacks for " <<
		damage << " points!\n"; 
}

string Human::getSpecies()
{
	return "Human";
}

Elf::Elf() : Creature( )
{
	//empty
}

Elf::Elf(int newStrength, int newHit) : Creature(newStrength, newHit)
{
	//empty
}

string Elf::getSpecies()
{
	return "Elf";
}

int Elf::getDamage()
{
	int damage = Creature::getDamage();
	cout << getSpecies() << " attacks for " <<
		 damage << " points!" << endl;
	
	if ((rand( ) % 10) == 0)
		{
			cout << "Magical attack inflicts " << damage <<
					" additional damage points!" << endl;
			damage = damage * 2;
		}
	return damage;
}

Demon::Demon() : Creature( )
{
	//empty
}

Demon::Demon(int newStrength, int newHit) : Creature(newStrength, newHit)
{
	//empty
}

int Demon::getDamage()
{
	int damage = Creature::getDamage();
	cout << " attacks for " << damage << " points!" << endl;

	if ((rand( ) % 100) < 5)
		{
			damage = damage + 50;
			cout << "Demonic attack inflicts 50"
				<< " additional damage points!" << endl;
		}
	return damage;
}

int Demon::getStrength()
{
	Creature::getStrength();
}

Cyberdemon::Cyberdemon() : Demon()
{
	//empty
}

Cyberdemon::Cyberdemon(int newStrength, int newHit) : Demon(newStrength, newHit)
{
	//empty
}

string Cyberdemon::getSpecies()
{
	return "Cyberdemon";
}

int Cyberdemon::getDamage()
{
	cout << getSpecies();
	Demon::getDamage();
}

Balrog::Balrog() : Demon()
{
	//empty
}

Balrog::Balrog(int newStrength, int newHit) : Demon(newStrength, newHit)
{
	//empty
}

string Balrog::getSpecies()
{
	return "Balrog";
}

int Balrog::getDamage()
{
	cout << getSpecies();
	Demon::getDamage();
	int damage2 = (rand() % Demon::getStrength()) + 1;
	cout << "Balrog speed attack inflicts " << damage2 <<
			" additional damage points!" << endl;
}