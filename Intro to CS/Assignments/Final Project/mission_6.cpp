#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <cstdio>
#include "harmonh.h"

using namespace Harmonh;
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
	char tradeAns;
	int spaceBucks = 500;
	string buyItem;
	vector<string> hold;
	vector<string> trade;

	open_items(hold, trade);

	cout << "You have come upon some traders.\n";
	cout << "Here is what you currently have in your hold:\n";
	for(int i = 0; i < hold.size(); i++) {
		cout << hold[i] << endl;
	}
	cout << "*************************************\n";
	cout << "Would you like to puchase some items?\n";
	cout << "(y/n):: ";
	cin >> tradeAns;

	trade_function(tradeAns, trade, hold, spaceBucks);	

	add_print_items(hold);

	cout << "You have finished trading and decide to move on to another sector.\n";

	return 0;
}