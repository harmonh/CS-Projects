/*********************************************************************************
**Program: pp5_9_oned.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Projects 5.9 (one-dimensional array 
version). A program that runs a two player tic-tac-toe board using an array from 
1 to 9 set up as a 3x3 board. Player 1 marks their place with an X and player 2 
marks there place with an O.
**Input: Each player is asked in turn to mark a location on the board. To choose 
a location, they enter the integer corresponding to the place on the "board" 
they would like to play. They input choices until every space on the board has 
either an X or O. If a player inputs a number that is not an integer, a number 
off the board, or the number of a location that already has an X or O the 
program will return an error message and they must input something different.
**Output: The program displays the tic tac toe board as a 3x3 grid of the 
numbers 1 through 9. When a player takes a turn, the location they choose 
changes from a number to their player indicator (X or O) and the updated board 
is printed. The game starts with the X player and cycles back and forth between 
X and O until the board is filled (9 times).
*********************************************************************************/

#include <iostream>
using namespace std;

//Prints out tic tac toe board
void ttt_board(char ttt_array[]);
//Runs Player X turn
void player_x_turn(char ttt_array[]);
//Runs playerO turn
void player_o_turn(char ttt_array[]);

int main()
{
	char tic_tac_toe[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int turn = 0;
	
	cout << "Greetings players! So far your tic-tac-toe board looks like this:\n";
	
	for(int i = 0; i < 9; i++)
	{
		ttt_board(tic_tac_toe);
		
		if(turn == 0)
		{
			player_x_turn(tic_tac_toe);
			turn++;
		}
		else
		{
			player_o_turn(tic_tac_toe);
			turn--;
		}	
	}
	
	ttt_board(tic_tac_toe);
	cout << "Spaces have all been filled.\n";
	
	return 0;
}

void ttt_board(char ttt_array[])
{
	for(int i = 0; i < 9; i++)
	{
		cout << ttt_array[i] << " ";
		if((i == 2) || (i == 5))
		{
			cout << endl;
		}
	}
	cout << endl;
}

void player_x_turn(char ttt_array[])
{
	int playerX;
	cout << "Player X, which location number do you wish to mark?\n";
	cin >> playerX;
		
	while(((playerX < 1) || (playerX > 9)) || cin.fail())
	{
		cout << "That is not a location on the board, choose again.\n";
		cin.clear();
		cin.ignore(255, '\n');
		cin >> playerX;
	}
			
	while((ttt_array[playerX - 1] == 'O') || (ttt_array[playerX - 1] == 'X'))
	{
		cout << "That location has already been played on, choose again.\n";
		cin >> playerX;
	}
			
	cout << endl;
	ttt_array[playerX - 1] = 'X';
}

void player_o_turn(char ttt_array[])
{
	int playerO;
	cout << "Player O, which location number do you wish to mark?\n";
	cin >> playerO;
		
	while(((playerO < 1) || (playerO > 9)) || cin.fail())
	{
		cout << "That is not a location on the board, choose again.\n";
		cin.clear();
		cin.ignore(255, '\n');
		cin >> playerO;
	}
	
	while((ttt_array[playerO - 1] == 'O') || (ttt_array[playerO - 1] == 'X'))
	{
		cout << "That location has already been played on, choose again.\n";
		cin >> playerO;
	}
	
	cout << endl;
	ttt_array[playerO - 1] = 'O';
}