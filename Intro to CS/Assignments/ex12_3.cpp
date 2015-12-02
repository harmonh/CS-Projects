/******************************************************************************************************
**Program: ex12_3.cpp
**Author: Holly Harmon
**Description: **For program to compile, must use the -std=c++0x flag**
For exercise 12 question 3. This program forces a princess named Eve to randomly choose
a suitor from a list of any number in length by eliminating every third suitor. When she reaches the 
end of the line she continues back at the beginning without starting her counting over. The user enters
the number of suitors and the program will tell the user which place in line they should occupy in order
to be "chosen" by the princess.
**Input: User enters the integer number of suitors that will be lined up.
**Output: The user is asked how many suitors princess Eve will be choosing from and creates a vector
of that size (minus one) with each element assigned a number from 1 to n (n being the number of 
suitors). The program then erases every third suitor from the list and when it reaches the end of the
line, will begin erasing from the beginning of the now emptier vector, but will erase depending on how
many suitors we left at the end of the previous line. Finally, the program will let the user know 
where in line they should stand to not get eliminated.
******************************************************************************************************/

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main( )
{
	int n; //number of suitors
	vector<int> suitors; //vector to be filled with suitors

	cout << "How many suitors does princess Eve need to choose from?\n";
	cin >> n;

	//Filling the vector with suitors numbered 1 to n
	for(int i = 0; i < n; i++)
	{
		suitors.push_back(i + 1);
	}

	int j = suitors.size(); //used later for do-while loop if statements

	//When elimination starts, it starts at the beginning of the vector (suitors[0]) and erases
	//every third suitor. No need to take into account where Eve left off at the end of the line.
	for (auto i = suitors.begin(); i != suitors.end() /* not hoisted */; /* no increment */)
	{
    	if ((*i % 3 == 0)) {
        	i = suitors.erase(i);
    	}
   		 else {
    	    ++i;
    	}
	}
	
	do {
		if((j % 3) == 1) {
			//When the previous round of elimination ends with one suitor at the end
			//of the line, the second suitor in line will always be eliminated
			suitors.erase(suitors.begin() + 1);

			//accounts for suitor[1] having been eliminated and conts to count by 3s.
		    int m = 0; //m increments to erase every third suitor
			for (auto i = suitors.begin(); i != suitors.end() /* not hoisted */; m++)
			{
		   		if ((m != 0) && (m % 3 == 0)) {
       				i = suitors.erase(i);
   				}
    			else {
   				    ++i;
   				}
   				j = m; //lets the loop know how many suitors were left at the end
			}
		}

		if((j % 3) == 2) {
			//When the previous round of elimination ends with two suitors at the end
			//of the line, the first suitor in line will always be eliminated
			suitors.erase(suitors.begin());

			//accounts for suitor[0] having been eliminated and conts to count by 3s.
			int m = 1;
			for (auto i = suitors.begin(); i != suitors.end() /* not hoisted */; m++)
			{
                if ((m != 0) && (m % 3 == 0)) {
    		        i = suitors.erase(i);
        		}
       			else {
            		++i;
    		    }
    		    j = m;
		   	}
		}

		if((j % 3) == 0) 
		{
			//When the previous round of elimination ends with the last one in line
			//counting starts from the beginning.
			int m = 1;
			for (auto i = suitors.begin(); i != suitors.end() /* not hoisted */; m++)
    		{
           		if ((m != 0) && (m % 3 == 0)) {
        		    i = suitors.erase(i);
        		}
        		else {
            		++i;
        		}
        		j = m;
        	}
		}
		
	} while(suitors.size() > 1); 
	//Once the number of elements in the vector reaches 1, a suitor has been selected
	//and the loop ends.

	cout << "If there are " << n << " suitors, to be chosen by the princess\n";
	cout << "you should stand in position " << suitors[0] << endl;

	return 0;
}