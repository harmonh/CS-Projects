/*********************************************************************************
**Program: random_number.cpp
**Author: Holly Harmon
**Description: For excercise set 3, question 4. This program prints 10 random numbers
**Input: none
**Output: Ten random numbers
*********************************************************************************/ 

#include <iostream>
#include <cstdlib>
using namespace std;

int main ( )
{
	int i;
	
	for (i = 0; i < 10; i++)
	{
		cout << rand( ) << endl;
	}
	
	return 0;
}

int card[52];    // array of cards;
    int n;           // number of cards to deal
    srand(time(0));  // initialize seed "randomly"
     
    for (int i=0; i<52; i++) {
        card[i] = i;  // fill the array in order
    }
    
    while (cin >> n) {    
        //--- Shuffle elements by randomly exchanging each with one other.
        for (int i=0; i<52; i++) {
            int r = rand() % 52;  // generate a random position
            int temp = card[i]; card[i] = card[r]; card[r] = temp;
        }
        
        //--- Print first n cards as ints.
        for (int c=0; c<n; c++) {
            cout << card[c] << " ";  // Just print number
        }
        cout << endl;
    }
   
   return 0;
}