#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <sstream>

using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;

int main()
{
	int price;
	vector<string> v;
	v.push_back("5");

	stringstream ss(v[0]);
	ss >> price;

	cout << "v[0] " << v[0] << endl;
	cout << "Price " << price << endl;

}