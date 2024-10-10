#include <fstream>
#include <iostream>
using namespace std;

int main()
{
 cout << "What did you eat?: "; 
 string food;
 cin >> food;
 ofstream file("foods.txt");
 file<< food;
    return 0;
}