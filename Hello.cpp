#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string fileName;
    fileName = "Input.txt";
    cout << "Enter file name with extension (.txt): ";
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
    string LastLine;
    while (getline(inFile, line))
    {

        cout << line << endl;
        LastLine = line;
    }
    cout << LastLine;
    inFile.close();
    return 0;
}
