#include <fstream>
#include <iostream>
#include <sstream>
#include <vector> // I chose vector instead of list due to its flexibility and if we can't predict the amount of Pearson in Input file

using namespace std;

class Person // Сlass that include FirstName, SecondName, Score
{
public:
    string FirstName;
    string SecondName;
    int Score;

    // Сlass properties
    Person(const string P_FirstName, const string P_SecondName, int P_score)
        : FirstName(P_FirstName), SecondName(P_SecondName), Score(P_score) {}
};

// Function for changing the object
void changePerson(vector<Person> persons)
{

    cout << "Enter the index of the person you want to change: ";
    size_t i; // size_t instead of Ind, becouse if we compare int to vector size it give us a warning
    cin >> i;

    if (i < 1 || i > persons.size()) // check if User wrote correct index line
    {
        cout << "Wrong person number!" << endl;
    }

    i--; // Decrease by 1, the user enters from 1, but indexing starts from 0

    cout << "Enter new First Name: ";
    cin >> persons[i].FirstName;

    cout << "Enter new Second Name: ";
    cin >> persons[i].SecondName;

    cout << "Enter new Score: ";
    cin >> persons[i].Score;
}

// Function to output all objects
void CoutAllPersons(vector<Person> persons)
{
    cout << "List of people:" << endl;
    for (size_t i = 0; i < persons.size(); i++)
    {
        cout << i + 1 << ") ";
        cout << persons[i].FirstName << " ";
        cout << persons[i].SecondName << " ";
        cout << persons[i].Score << endl;
    }
}

// Function to add a new object
void addPerson(vector<Person> persons)
{
    string FirstName;
    string SecondName;
    int Score;

    cout << "Enter First Name: ";
    cin >> FirstName;

    cout << "Enter Second Name: ";
    cin >> SecondName;

    cout << "Enter Score: ";
    cin >> Score;

    persons.emplace_back(FirstName, SecondName, Score);
}

// Function to delete an object
void removePerson(vector<Person> persons)
{
    size_t i;
    cout << "Enter the number of the person you want to delete: ";
    cin >> i;

    if (i < 1 || i > persons.size()) // check if User wrote correct index line
    {
        cout << "Invalid person number!" << endl;
    }

    i--; // Decrease by 1, the user enters from 1, but indexing starts from 0

    persons.erase(persons.begin() + i);
}

int main()
{
    vector<Person> persons;
    string filename;

    try // trying to read file
    {
        cout << "Enter the file name: ";
        cin >> filename;

        ifstream file(filename);

        if (!file.is_open()) // Checking if the fileName is Empty
        {
            cout << "Error opening file!" << endl;
            return 1;
        }

        string line;
        int lineIndex = 0;

        while (getline(file, line))
        {
            lineIndex++;
            istringstream iss(line);
            string firstName;
            string secondName;
            int score;

            if (!(iss >> firstName >> secondName >> score))
            {

                if (line == "")
                {
                    cout << "Empty line! => " << lineIndex << endl;
                }

                cout << "Error: Incorrect data! => " << lineIndex << endl;
                continue;
            }
            persons.emplace_back(firstName, secondName, score);
        }
        file.close();
    }
    catch (exception error)
    {
        cout << "Error: " << error.what() << endl;
    }

    CoutAllPersons(persons); // Output of all created objects

    try // Changing, adding, deleting objects at the user request
    {
        char choice;
        cout << "Do you want to change (c), add (a) or remove (r) a person? (Enter (n) if no): ";
        cin >> choice;

        if (choice == 'c')
        {
            changePerson(persons);
        }
        else if (choice == 'a')
        {
            addPerson(persons);
        }
        else if (choice == 'r')
        {
            removePerson(persons);
        }
        else if (choice == 'n')
        {
        }
        else
        {
            cout << "No command found!" << endl;
        }
        CoutAllPersons(persons); // Output the new list
    }
    catch (exception error)
    {
        cout << "Error: " << error.what() << endl;
    }
    // Write to output file
    try
    {
        cout << "Enter the output file name: ";
        cin >> filename;

        ofstream outputFile(filename);
        if (!outputFile.is_open())
        {
            cout << "Error opening output file!" << endl;
        }

        for (auto person : persons)
        {
            outputFile << person.FirstName << " " << person.SecondName << " " << person.Score << endl;
        }

        outputFile.close();
    }
    catch (exception error)
    {
        cout << "Error: " << error.what() << endl;
    }
}
