/******************************************************************************
* File: wk9_greshamPolka_adupree.cpp
* Description: Displays dues amount based on user selection.
* Author: Alexander DuPree
* Date: 3/6/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void displayOptions(const string level[],const string description[], const int SIZE);
void displayDues(const string level[], const string description[], const int dues[], int index);
void getInput(string &choice, string prompt);
int findIndex(const string &choice, const string ara[], const int SIZE);
bool isValidNum(const string &choice, string errorMessage, int _max, int _min);


int main()
{
    const int SIZE = 5;
    int index;
    string choice;
    // Choice is reused for each input.

    // Set up parallel arrays
    int dues[SIZE] = {30, 50, 75, 100, 200};
    string level[SIZE] = {"A", "B", "C", "D", "E"};
    string description[SIZE] = {"Student Member",
                                "Individual Member",
                                "Performing Member",
                                "Touring Member",
                                "Lifetime Member"};

    do {
        displayOptions(level, description, SIZE);

        do {
            getInput(choice,
             "To enter a character, type 1; to enter a description, type 2.\n");
        } while (!isValidNum(choice, "Invalid input", 50, 48));
        // 49 - 50 are the ASCII values for 1 and 2
        if (choice[0] == '1')
        {
            do {
                getInput(choice, "Enter the level:  ");
                choice = toupper(choice[0]);
            } while (!isValidNum(choice, "Invalid input", 69, 64));
            // 65 - 69 are the ASCII values for A - E
            index = findIndex(choice, level, SIZE);
        }
        else
        {
            getInput(choice,
                 "Enter the description, exactly as it is in the menu above:  " );
            index = findIndex(choice, description, SIZE);
        }

        displayDues(level, description, dues, index);

        getInput(choice, "\nDo you want to see another dues amount?  (y or n)  ");
        } while (choice == "Y" || choice == "y");

    return 0;
}

void displayOptions(const string level[], const string description[], const int SIZE)
{
    cout << "\nLEVEL\tDESCFRIPTION" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << level[i] << '\t' << description[i] << endl;
    }
    return;
}

void displayDues(const string level[], const string description[], const int dues[], int index)
{
    if (index < 0)
    {
        cout << "I'm sorry, your selection was not found." << endl;
    }
    else
    {
        cout << level[index] << '\t' << description[index] << '\t' << dues[index];
    }
    return;
}



void getInput(string &choice, string prompt)
{
    cout << prompt;
    getline(cin, choice);
    return;
}

int findIndex(const string& choice,const string ara[], const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (choice == ara[i])
        {
            return i;
        }
    }
    return -1; // -1 is returned if element is not found.

}

bool isValidNum(const string &choice, string errorMessage, int _max, int _min)
{
    if (choice[0] > _min && choice[0] <= _max)
    {
        return true;
    }
    else
    {
        cout << errorMessage << endl;
        return false;
    }
}

