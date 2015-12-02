/*********************************************************************************
**Program: project5.cpp
**Author: Holly Harmon
**Description: The Game of Life!!! This program consists of a 22 by 80 two dimensional
array where each element is a cell that is either alive (indicated with *) or dead 
(empty). The cells change with each generation following rules according to the
number of neighbors (alive cells surrounding the cell) they have. If a living cell
has 0, 1, or more than 3 living neighbors that cell dies. If a dead (empty) cell has
exactly 3 living neighbors that cell is born and turns into a live cell.
**Input: User gets to choose from a menu of three options. 1) They can enter an
integer of how many random living cells they would like to start with and the
number of generations. 2-3) User chooses the number of generations.
**Output: Program displays the "world" array with it's original placement of cells
and the subsequent generations up to the number of gens chosen by the user. Will
also alert the user to input errors (user can only input integers).
*********************************************************************************/
#include <iostream>
#include <cstdlib> //rand function
#include <limits> //"Press ENTER" code

using namespace std;

void empty_array(char world[][80]);
//Initializes the world array with blank ' ' spaces (all dead cells)
void generation(char world[][80]);
//Takes in the original iteration of world with the random user cell placement
//or prewritten patterns chosen from the menu. Initializes a temporary array
//with the same living cells to be changed by the if statements according to the
//rules of the game, counting neighbors with int n. Runs through every cell in 
//the array assigning them to dead or alive, then copies the changed/temp array 
//back to the original world array, printing it to the user at the same time.
void user_array(int, char world[][80]);
//Accepts a user int that is the number of live cells they would like to start with.
//Uses the rand function to assign x and y as coordinates of the array to be living
//cells. User input must be at least 1 and less than 1760 (max size of the array).
void toad_array(char world[][80]);
//Accepts the empty world array and assigns living cells in a "toad" pattern.
//A simple oscillating pattern with 2 phases.
void glider_array(char world[][80]);
//Accepts the empty world array and assigns living cells in a pattern called
//the "Gosper's Glider Gun."

int main ( )
{
	char world[22][80];
	int gens; //number of generations
	int menu; //menu number choice
	int userStars; //number of living cells input by user

	empty_array(world); //initializing empty array

	cout << "Welcome to the Game of Life!\n";
	cout << "You may either choose the number of random starting points or some"
		<< " preprogrammed designs. Please select a number from the menu below.\n";
	cout << endl;
	cout << "(1) Enter my own number\n";
	cout << "(2) Design: Toad\n";
	cout << "(3) Design: Gosper's Glider Gun\n";
	cout << "Enter a number: ";
	cin >> menu;

	//User input error check. Only integers 1, 2, and 3 may be entered
	while((menu > 3) || (menu < 1) || (cin.fail()))
	{
		cout << "There is no option with that number, choose again: ";
		cin.clear();
		cin.ignore(255, '\n');
		cin >> menu;
	}

	switch (menu)
	{
		/**Case 1 lets the user create their own random array of live cells **/
		case 1:

			cout << "How many random markers would you like to start with? ";
			cin >> userStars;

			//error check. User input must be int and cannot fall outside the array
			while((userStars > 1760) || (userStars < 1) || (cin.fail()))
			{
				cout << "Must be an integer between 1 and 1760: ";
				cin.clear();
				cin.ignore(255, '\n');
				cin >> userStars;
			}
			
			cout << "How many generations would you like to run? ";
			cin >> gens;
			
			//User must enter an int of at least 1 (otherwise what's the point??)
			while((gens < 1) || (cin.fail()))
			{
				cout << "Please choose an integer greater than 0: ";
				cin.clear();
				cin.ignore(255, '\n');
				cin >> gens;
			}
			user_array(userStars, world);
			break;
		/**Case 2 creates an array with the "toad" pattern**/	
		case 2:
			cout << "How many generations of Toad would you like to run? ";
			cin >> gens;
			
			while((gens < 1) || (cin.fail()))
			{
				cout << "Please choose an integer greater than 0: ";
				cin.clear();
				cin.ignore(255, '\n');
				cin >> gens;
			}
			toad_array(world);
			break;
		/**Case 3 creates an array with the Glider Gun (Pew pew!)**/	
		case 3:
			cout << "How many generations of the Glider Gun would you like to run?\n";
			cout << "(Recommend 30 or higher): "; //does not start "shooting" gliders till then
			cin >> gens;
			
			while((gens < 1) || (cin.fail()))
			{
				cout << "Please choose an integer greater than 0: ";
				cin.clear();
				cin.ignore(255, '\n');
				cin >> gens;
			}
			glider_array(world);
			break;
			//no default because the error check after user menu input should
			//catch exceptions
	}

	//Prints the original generation
	cout << "+++ Generation 0 +++" << endl;
	for(int i = 0; i < 22; i++) {
		for(int k = 0; k < 80; k++) {
			cout << world[i][k];
		}
		cout << endl;
	}

  	cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //For "ENTER" input
	//Calls generation function the number of times input by the user
	for(int a = 0; a < gens; a++) {
		//For "ENTER" input (allows time between generations)
		cout << "Press ENTER for next generation...";
	  	cin.ignore(numeric_limits<streamsize>::max(), '\n' );

		cout << "+++ Generation " << a+1 << " +++" << endl;
		generation(world);
	}

	return 0;
}

void generation(char world[][80])
{	
	char worldTemp[22][80];
	for(int i = 0; i < 22; i++) {
		for(int k = 0; k < 80; k++) {
			worldTemp[i][k] = ' ';
		}
	}

	for(int i = 0; i < 22; i++) {
		for(int k = 0; k < 80; k++) {
			int n = 0; //number of neighbors for that cell
			//For live cells:
			if(world[i][k] == '*') {
				if(world[(i+22-1) % 22][(k+80-1) % 80] == '*') {
					n++;
				}
				if(world[(i+22-1) % 22][k] == '*') {
					n++;
				}
				if(world[(i+22-1) % 22][(k+1) % 80] == '*') {
					n++;
				}
				if(world[i][(k+80-1) % 80] == '*') {
					n++;
				}
				if(world[i][(k+1) % 80] == '*') {
					n++;
				}
				if(world[(i+1) % 22][(k+80-1) % 80] == '*') {
					n++;
				}
				if(world[(i+1) % 22][k] == '*') {
					n++;
				}
				if(world[(i+1) % 22][(k+1) % 80] == '*') {
					n++;
				}
				if(n <= 1) {
					worldTemp[i][k] = ' '; //cell dies of loneliness :(
				}
				if(n > 3) {
					worldTemp[i][k] = ' '; //cell dies of overcrowding
				}
				if((n == 2) || (n == 3)) {
					worldTemp[i][k] = '*';
				}
			}
			//For dead cells
			if(world[i][k] == ' ') {
				if(world[(i+22-1) % 22][(k+80-1) % 80] == '*') {
					n++;
				}
				if(world[(i+22-1) % 22][k] == '*') {
					n++;
				}
				if(world[(i+22-1) % 22][(k+1) % 80] == '*') {
					n++;
				}
				if(world[i][(k+80-1) % 80] == '*') {
					n++;
				}
				if(world[i][(k+1) % 80] == '*') {
					n++;
				}
				if(world[(i+1) % 22][(k+80-1) % 80] == '*') {
					n++;
				}
				if(world[(i+1) % 22][k] == '*') {
					n++;
				}
				if(world[(i+1) % 22][(k+1) % 80] == '*') {
					n++;
				}
				if(n == 3) {
					worldTemp[i][k] = '*'; //birth of new cell
				}
			}
		}
	}

	for(int i = 0; i < 22; i++) {
		for(int k = 0; k < 80; k++) {
			world[i][k] = worldTemp[i][k];
			cout << world[i][k];
		}
		cout << endl;
	}
}

void empty_array(char world[][80])
{
	for(int i = 0; i < 22; i++) {
		for(int k = 0; k < 80; k++) {
			world[i][k] = ' ';
		}
	}
}

void user_array(int stars, char world[][80])
{
	srand(stars);
	for(int k = 0; k < stars; k++) {
		int x = (rand() % 22);
		int y = (rand() % 80);
		world[x][y] = '*';
	}

}

void toad_array(char world[][80])
{
	world[8][13] = '*';
	world[8][14] = '*';
	world[8][15] = '*';
	world[9][12] = '*';
	world[9][13] = '*';
	world[9][14] = '*';
}

void glider_array(char world[][80])
{
	world[7][0] = '*';
	world[7][1] = '*';
	world[8][0] = '*';
	world[8][1] = '*';
	world[7][10] = '*';
	world[8][10] = '*';
	world[9][10] = '*';
	world[6][11] = '*';
	world[10][11] = '*';
	world[5][12] = '*';
	world[11][12] = '*';
	world[5][13] = '*';
	world[11][13] = '*';
	world[8][14] = '*';
	world[6][15] = '*';
	world[10][15] = '*';
	world[7][16] = '*';
	world[8][16] = '*';
	world[9][16] = '*';
	world[8][17] = '*';
	world[5][20] = '*';
	world[6][20] = '*';
	world[7][20] = '*';
	world[5][21] = '*';
	world[6][21] = '*';
	world[7][21] = '*';
	world[4][22] = '*';
	world[8][22] = '*';
	world[3][24] = '*';
	world[4][24] = '*';
	world[8][24] = '*';
	world[9][24] = '*';
	world[6][34] = '*';
	world[5][34] = '*';
	world[6][35] = '*';
	world[5][35] = '*';
}