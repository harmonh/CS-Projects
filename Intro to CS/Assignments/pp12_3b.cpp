/*********************************************************************************
**Program: pp12_3b.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Projects 12.3(b). This program creates
a data file with numbers and then computes the three quartiles.
**Input: 
**Output: The program creates a .txt file with the indicated numbers in it
starting at 0. Then the number of values in the file are counted and the quartiles
are calculated depending on whether there are an odd or even number of values. Then
the three values are printed to the screen.
*********************************************************************************/
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using std::cout;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::vector;

void make_out_file(int);
//Accepts an integer to indecate the number of values to be written to the 
//output file "outMedian.txt." Then the numbers 0 to the int are written to a file.
void read_in_file(int&);
//Inputs the "outMedian.txt" file in order to count the number of values and
//assigns that value to n.
void find_quartile(int);
//Takes in int n and fills a vector with the values from the file. Uses n to
//find the median (middle value from the vector if n is odd, the average of the
//two middle values if n is even) which is the 2nd quartile. Then finds the
//middle value of the first half and the middle value of the second half to
//assign the 1st and 3rd quartile.

int main( )
{
	int n = 0;

	make_out_file(9);
	read_in_file(n);

	cout << "In a file containing the numbers: \n";
	find_quartile(n);

	return 0;

}

void make_out_file(int k) 
{
	ofstream outFile;

	outFile.open("outMedian.txt");
	if (outFile.fail( )) {
		cout << "Output file opening failed.\n";
		exit(1);
	}

	for(double i = 0; i < k; i++) {
		outFile << i << endl;
	}
}

void read_in_file(int &n)
{
	ifstream inFile;
	inFile.open("outMedian.txt");
	if (inFile.fail( )) {
		cout << "Input file opening failed.\n";
		exit(1);
	}

	double next;
	while(inFile >> next) {
		n++;
	}
}

void find_quartile(int n)
{
	ifstream inFile ("outMedian.txt");
	vector<double> v;
	double median;
	double quar1;
	double quar3;
	int medianPlace;

	double next;
	
	while(inFile >> next) {
		v.push_back(next);
		cout << next << " ";
	}
	cout << endl;
	
	//If there are an even number of values in the file
	if(n % 2 == 0) {
		medianPlace = ((n/2));
		median = (v[medianPlace] + (v[medianPlace - 1]))/2;
		quar1 = v[n * .25];
		quar3 = v[n * .75];

		cout << "The first Quartile is: " << quar1 << endl;
		cout << "The Second Quartile is: " << median << endl;
		cout << "The Third Quartile is: " << quar3 << endl;

	}
	//If there are an odd number of values in the file.
	else {
		medianPlace = ((n/2));
		quar1 = ((v[n*.25] + v[(n*.25)-1])/2);
		quar3 = ((v[n*.75] + v[(n*.75)+1])/2);

		cout << "The First Quartile is: " << quar1 << endl;
		cout << "The Second Quartile is: " << v[medianPlace] << endl;
		cout << "The Third Quartile is: " << quar3 << endl;
	}
}