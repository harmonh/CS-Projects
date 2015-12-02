#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
// using std::cout;
// using std::cin;
// using std::endl;
// using std::vector;

int main( )
{
    int n;
    vector<int> suitors;

    cout << "How many suitors does princess Eve need to choose from?\n";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        suitors.push_back(i + 1);
        //cout << "Suitor at place " << i << " is " << suitors[i] << endl;
    }

    int j = suitors.size();

    for (auto i = suitors.begin(); i != suitors.end() /* not hoisted */; /* no increment */)
    {
        if ((*i % 3 == 0)) {
            i = suitors.erase(i);
        }
         else {
            ++i;
        }
    }

    for(unsigned int p = 0; p < suitors.size(); p++)
    cout << suitors[p] << endl;

    suitors.erase(suitors.begin() + 1);

    for(unsigned int p = 0; p < suitors.size(); p++)
    cout << suitors[p] << endl;
    
    int m = 0;
	for (auto i = suitors.begin(); i != suitors.end() /* not hoisted */; m++)
	{
   		
   		if ((m != 0) && (m % 3 == 0)) {
       		i = suitors.erase(i);
   		}
    	else {
   		    ++i;
   		    
   		}
	}

    for(unsigned int p = 0; p < suitors.size(); p++)
    cout << suitors[p] << endl;

    // suitors.erase(suitors.begin());


    
    // m = 1;
    // for (auto i = suitors.begin(); i != suitors.end() /* not hoisted */; m++)
    // {
        
    //     if ((m != 0) && (m % 3 == 0)) {
    //         i = suitors.erase(i);
    //     }
    //     else {
    //         ++i;
            
    //     }
    // }
    // for(unsigned int p = 0; p < suitors.size(); p++)
    // cout << suitors[p] << endl;
    
    m = 1;
    for (auto i = suitors.begin(); i != suitors.end() /* not hoisted */; m++)
    {
        
        if ((m != 0) && (m % 3 == 0)) {
            i = suitors.erase(i);
        }
        else {
            ++i;
            
        }
    }
    for(unsigned int p = 0; p < suitors.size(); p++)
    cout << suitors[p] << endl;

    return 0;
}