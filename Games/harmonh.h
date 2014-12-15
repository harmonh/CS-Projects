#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Harmonh
{	
	//mission 2
	struct starship
	{
		int crew;
		string type;
		int shields;
		string weapon;
	};
	
	//mission 1
	void user_name(int argc, char *argv[], string& name);
	//Finds if user has input anything to the command line and
	//sets it as the user name. If nothing has been entered they
	//may choose to input their name.
	void answer_check(int&, int);
	//Checks if the two ints are equal
	void answer_check(string&, string);
	//checks if the two strings are equal
	void check_int(int&);
	//Checks if input is an integer
	
	//mission 2
	void ship_menu(int&);
	//Prints out the ship menu and uses a switch to let the user
	//select a ship from the menu. Also allows user to input the
	//ships name and assigns it a random number
	void setStarship(starship& star, int, string, int, string);
	//Sets the member variables of a Starship from the Starship struct
	void printStarship(starship);
	//Prints member variables of Starships
	
	//mission 3
	void fill_map_array(char **main);
	//Fills the two-dimensional, dynamically declared array 'main'
	//Sets the points to select later from the user menu
	void print_map(char **main);
	//Prints the main array to the screen
	char map_menu(char **main, char& visit);
	//Allows the user to select a sector to visit from the map.
	//User must imput e, a, i, or t.
	void trading_post(int&);
	//Is called when the user inputs 't' at the map_menu. Allows the 
	//user to see what is in their hold (a txt file), what they can buy
	//(also a txt file) and tells them what is in their hold once they
	//have finished trading. Passes the int spaceBucks by reference, so
	//if they visit the trading post again, their balance is saved.
	int asteroid_assault( );
	//Main part of the asteroid shooting game. Calls the functions
	//to print the ast array and "shoot" at the array.
	int alien_attack( );
	//Main part of the alien intrider game. Creates a human and alien objects
	//and calls functions for getting damage and adjusting life points.
	//Winner is random, but favors the human.

	//mission 4
	class Creature
	{
	public:
		Creature();
		Creature(int newLife, int newStrength);
		int getLife();
		int getStrength();
		int setLife(int newLife);
		int setStrength(int newStrength);
		int getDamage();

	private:
		int lifePoints;
		int strength;
	};

	class Human : public Creature
	{
	public:
		Human();
		Human(int newLife, int newStrength);
		~Human();
		int getDamage();

	private:
		//empty
	};

	class Alien : public Creature
	{
	public:
		Alien();
		Alien(int newLife, int newStrength);
		~Alien();
		int getDamage();

	private:
		//empty
	};

	//mission 5
	void print_array(string a[]);
	void asteroid_shoot(string a[], int& asts);
	//user inputs numbers corresponding to points on the displayed array.
	//If the user hits an asteroid the point will become *, if they miss
	//it will become X. 
	
	//mission 6
	void open_items(vector<string>&, vector<string>&);
	void trade_function(char, vector<string>&, vector<string>&, int&);
	void add_print_items(vector<string>&);
	//Outputs the updated list of items a user has to a txt file. This
	//file can be opened later if the user chooses to return to the
	//trading post during the same game. After quitting the game the
	//file is deleted from the main function.
}