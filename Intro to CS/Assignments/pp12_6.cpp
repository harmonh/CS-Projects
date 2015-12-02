/*********************************************************************************
**Program: pp12_6.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Projects 12.6 Program outputs two text
files with integer values in them in sorted order. The two files are then copied to
a third file with the numbers still in sorted order.
**Input: Two files output by the program with int values.
**Output: Creates three files, two with integers in certain ranges in ascending
order and a third with all of the values from the first two files, also in
ascending order. Assigns the values from the first two files to a vector, sorts
the values in ascending order, and writes the numbers from that vector to a new
file.
*********************************************************************************/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm> //for sort
#include <string>

using std::cout;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::vector;
using std::string;

void make_input(int, int, string);
//Creates an output file filled with values in the range indicated by the two
//argument integers. The files created in this function will be the ones read
//and copied to the third, combined file.
void merge_files(ifstream&, ifstream&, ofstream&);
//Takes in two input file streams and an output file stream for the
//two input files filled with values and the output file those values are 
//going to be written to. Copies values from the input streams to a vector,
//sorts those values and then writes them to a new 

int main( )
{
	string inputFile1 = "input1.txt"; //file one
	string inputFile2 = "input2.txt"; //file two

	make_input(0, 15, inputFile1);
	//A file with numbers 0 to 14
	make_input(8, 20, inputFile2);
	//A file with numbers 8 to 19

	ifstream inOne (inputFile1);
	if (inOne.fail( )) {
		cout << "Input file opening failed.\n";
		exit(1);
	}
	ifstream inTwo (inputFile2);
	if (inTwo.fail( )) {
		cout << "Input file opening failed.\n";
		exit(1);
	}
	ofstream outThree ("output3.txt"); //file three
	if (outThree.fail( )) {
		cout << "Output file opening failed.\n";
		exit(1);
	}

	merge_files(inOne, inTwo, outThree);

	return 0;
}

void make_input(int i, int k, string fileName)
{
	ofstream outSt;
	outSt.open(fileName);
	if (outSt.fail( )) {
		cout << "Output file opening failed.\n";
		exit(1);
	}

	for(i ; i < k; i++) {
		outSt << i << endl;
	}
}

void merge_files(ifstream& ins1, ifstream& ins2, ofstream& outs3)
{
	vector<int> v;
	int next;
	while(ins1 >> next) {
		v.push_back(next);
	}
	while(ins2 >> next) {
		v.push_back(next);
	}

	//sorts the combined values
	std::sort (v.begin(), v.end());

	for(int i = 0; i < v.size(); i++) {
		outs3 << v[i] << endl;
	}
}