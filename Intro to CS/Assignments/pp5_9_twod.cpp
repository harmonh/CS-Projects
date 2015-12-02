/*********************************************************************************
**Program: pp5_9_twod.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Projects 5.9 (two-dimensional array 
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

void ttt_board(char ttt[][3], int firstDimension);
void player_x_choice(char ttt[][3]);
void player_o_choice(char ttt[][3]);

int main()
{
	char tic_tac_toe[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
	int turn = 0;
	
	cout << "Greetings players! So far your tic-tac-toe board looks like this:\n";
	
	
	
	for(int i = 0; i < 9; i++)
	{	
		ttt_board(tic_tac_toe, 3);
		cout << endl;
		
		if(turn == 0)
		{
			player_x_choice(tic_tac_toe);
			
			cout << endl;
			turn++;
		}
		else
		{
			player_o_choice(tic_tac_toe);
			
			cout << endl;
			turn--;
		}	
	}
	
	ttt_board(tic_tac_toe, 3);	
	cout << endl;
	cout << "Spaces have all been filled.\n";
	
	return 0;
}

void ttt_board(char ttt[][3], int firstDimension)
{
	for(int n = 0; n < firstDimension; n++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << ttt[n][j] << " ";
		}
		cout << endl;
	}
}

void player_x_choice(char ttt[][3])
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
	
	while(((ttt[0][playerX - 1] == 'O') || (ttt[0][playerX - 1] == 'X')) || ((ttt[1][playerX - 4] == 'O') || (ttt[1][playerX - 4] == 'X')) || ((ttt[2][playerX - 7] == 'O') || (ttt[2][playerX - 7] == 'X')))
	{
		cout << "That location has already been played on, choose again.\n";
		cin >> playerX;
	}
			
	if((playerX > 0) && (playerX < 4))
	{
		ttt[0][playerX - 1] = 'X';
	}
			
	else if((playerX > 3) && (playerX < 7))
	{
		ttt[1][playerX - 4] = 'X';
	}
	else
	{
		ttt[2][playerX - 7] = 'X';
	}
}

void player_o_choice(char ttt[][3])
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
	
	while(((ttt[0][playerO - 1] == 'O') || (ttt[0][playerO - 1] == 'X')) || ((ttt[1][playerO - 4] == 'O') || (ttt[1][playerO - 4] == 'X')) || ((ttt[2][playerO - 7] == 'O') || (ttt[2][playerO - 7] == 'X')))
	{
		cout << "That location has already been played on, choose again.\n";
		cin >> playerO;
	}		
	
	if((playerO > 0) && (playerO < 4))
	{
		ttt[0][playerO - 1] = 'O';
	}
	
	else if((playerO > 3) && (playerO < 7))
	{
		ttt[1][playerO - 4] = 'O';
	}
			
	else
	{
		ttt[2][playerO - 7] = 'O';
	}
}