/******************************************************************************
* File: .cpp
* Description:
* Author: Alexander DuPree
* Date: 1/30/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>

using namespace std;

int getInput(string prompt, string errorMessage, int _max, int _min);
bool isValidNum(string errorMessage, int userInput, int _max, int _min);


int main()
{

    return 0;
}

int getInput(string prompt, string errorMessage, int _max, int _min)
{
    int userInput = 0;

    do {
    cout << prompt;
    cin >> userInput;
    } while(!isValidNum(errorMessage, userInput, _max, _min));

    return userInput;
}

bool isValidNum(string errorMessage, int userInput, int _max, int _min)
{
    if (userInput > _min && userInput <= _max)
    {
        return true;
    }
    else
    {
        cout << errorMessage << endl;

        // get rid of failure state
        cin.clear();

        // discard 'bad' characters
        cin.ignore(100, '\n');

        return false;
    }
}

