/*********************************************************************************
**Program: pp16_3.cpp
**Author: Holly Harmon
**Description: This program calls a template insertion sort function. Creates a 
vector and a variable s to insert and sort into that vector. Can be used with
any type that can be sorted (< and > oper.), so not of type string.
**Input:
**Output: Prints the original vector values then interts variable s and resorts
the vector to be printed again with the added value.
*********************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

template<class T>
void InsertionSort(vector<T> &v, T s, T key);

int main()
{
    //s, key, and vector v all need to be of the same type.
    int s = 3;
    int key;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);

    //Test code for type char:
    // char s = 'c';
    // char key;
    // vector<char> v;
    // v.push_back('a');
    // v.push_back('b');
    // v.push_back('d');
    // v.push_back('e');

    //Test code for type double:
    // double s = 3.2;
    // double key;
    // vector<double> v;
    // v.push_back(1.1);
    // v.push_back(2.5);
    // v.push_back(4.2);
    // v.push_back(5.3);

    //prints original vector sans s
    for(int n = 0; n < v.size(); n++) {
        cout << v[n] << " ";
    }
    cout << endl;

    InsertionSort(v, s, key);

    //prints vector with s added and sorted
    for(int n = 0; n < v.size(); n++) {
        cout << v[n] << " ";
    }
    cout << endl;

    return 0;
}

template<class T>
void InsertionSort(vector<T> &v, T s, T key)
{
    v.push_back(s);
    int size = v.size();
    int i, j;
    for(j = 1; j < size; j++)    // Start with 1 (not 0)
    {
        key = v[j];
        //moves smaller values to the front
        for(i = j - 1; (i >= 0) && (v[i] > key); i--)
        {
            v[i+1] = v[i];
        }
        v[i+1] = key;    //Put key into its proper location
    }
    
    return;
}