#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>


using std::cout;
using std::endl;
using std::cin;

typedef char* mapArrayPtr;

int main()
{
	mapArrayPtr *main = new mapArrayPtr[10];
	
	for(int i = 0; i < 10; i++) {
		main[i] = new char[40];
	}
	fill_map_array(main);

	map_menu(main);

	return 0;
}
