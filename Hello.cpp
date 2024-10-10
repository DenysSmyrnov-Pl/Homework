#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string fileName;
    cout << "File: ";
    getline(cin, fileName);

    if (fileName.empty())
    {
        cout << "No file name provided." << endl;
        return 1;
    }

    ifstream inFile(fileName);
    if (inFile.fail())
    {
        cout << "Error opening file: " << fileName << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;
    }

    inFile.close();
    return 0;
}
