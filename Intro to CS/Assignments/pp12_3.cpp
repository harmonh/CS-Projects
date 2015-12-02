#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

//using namespace std;
using std::cout;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::vector;

void make_out_file(int);
void read_in_file(int&);
void find_median(int);

int main( )
{
	int n = 0;

	make_out_file(10);
	read_in_file(n);
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

void find_median(int n)
{
	ifstream inFile ("outMedian.txt");
	vector<double> v;
	double median;
	int medianPlace;

	double next;
	
	while(inFile >> next) {
		v.push_back(next);
	}
	
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