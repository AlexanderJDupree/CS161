/******************************************************************************
* File: wk8_wordsArray_adupree.cpp
* Description: Asks the user for 8 strings and displays them
* Author: Alexander DuPree
* Date: 2/27/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void intro();
void fillArray(string words[], const int SIZE);
void showArray(string words[], const int SIZE);
void showWord(string words[], int ordinal);
int userRequest();
bool isValidNum(string errorMessasge, int input, int _max, int _min);

int main()
{

    const int SIZE = 8;         // size of the array
    string words[8] = {""};     // initialize array of strings will NULL strings
    int ordinal;                // for user input of which word to show



    intro();

    fillArray(words, SIZE);

    ordinal = userRequest();



    system("CLS");                             // clear the output screen



    showArray(words, SIZE);

    showWord(words, ordinal);



    return 0;

}

void intro()
{
    cout << "\t\tWORDS ARRAY\n" << endl;
    cout << "You will be asked to enter 8 words, then to request to view one of those words.";
    cout << endl;
    return;
}

void fillArray(string words[], const int SIZE)
{
    cout << "Enter 8 words, one per line. . . " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> words[i];
    }
    return;
}

void showArray(string words[], const int SIZE)
{
    cout << "The words in the array are:  " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << words[i] << endl;
    }
    return;
}

void showWord(string words[], int ordinal)
{
    cout << "\nThe word you requested was:  " << words[ordinal] << endl;
    return;
}

int userRequest()
{
    int input = 0;
    do {
        cout << "\nWhich word would you like to see?  " << endl;
        cout << "Enter 1 for first word, 2 for the second, etc.:  " << endl;
        cin >> input;
    } while (!isValidNum("Please enter a valid number.", input, 8, 0));
    return input - 1; // returns the index value the array will need
}

bool isValidNum(string errorMessage, int input, int _max, int _min)
{
    if (input > _max || input <= _min)
    {
        cout << errorMessage << endl;

        // get rid of failure state
        cin.clear();

        // discard 'bad' characters
        cin.ignore(100, '\n');

        return false;
    }
    else
    {
        return true;
    }
}
