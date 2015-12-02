/*********************************************************************************
**Program: pp12_3a.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Projects 12.3(a). This program creates
a data file with numbers and then computes the median.
**Input: 
**Output: The program creates a .txt file with the indicated numbers in it
starting at 0. Then the number of values in the file are counted and the median
is calculated depending on whether there are an odd or even number of values. Odd
finds the middle number, even finds the average of the two middle values. Prints
the median value to the screen.
*********************************************************************************/
#include <fstream> //for file in-out
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
void find_median(int);
//Takes in int n and fills a vector with the values from the file. Uses n to
//find the median (middle value from the vector if n is odd, the average of the
//two middle values if n is even).

int main( )
{
	int n = 0;

	make_out_file(10); //here you can set the number of values in the file
	read_in_file(n);
	cout << "In a file containing the numbers: \n";
	find_median(n);

	return 0;

}

void make_out_file(int k) 
{
	ofstream outFile;

	outFile.open("outMedian.txt");
	if (outFile.fail( )) {
		cout << "Output file opening failed.\n";
		exit(1);
	} //error handling

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
	} //error handling

	double next;
	while(inFile >> next) {
		n++;
	}
}

void find_median(int n)
{
	ifstream inFile ("outMedian.txt");
	vector<double> v;
	double median;
	int medianPlace; //place of median in the vector

	double next;
	
	while(inFile >> next) {
		v.push_back(next);
		cout << next << " ";
	} //error handling
	cout << endl;
	
	if(n % 2 == 0) {
		cout << "The number of elements in the file is even.\n";
		medianPlace = ((n/2));
		median = (v[medianPlace] + (v[medianPlace - 1]))/2;
		cout << "The Median Element is: " << median << endl;
	}
	else {
		cout << "The number of elements is odd.\n";
		medianPlace = ((n/2));
		cout << "The Median Element is: " << v[medianPlace] << endl;
	}
}