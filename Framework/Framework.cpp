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

void whileLoopExample();

int main()
{
    whileLoopExample();

    // do -while sentinal example

    // for loop example

    return 0;
}

void whileLoopExample()
{
    int numOfLoops;
    int counter = 0;

    numOfLoops = getInput("Enter number of times to loop:  ",
                       "Positive integers only.",
                       1000, 0)
    while (counter < numOfLoops)
    {
        cout << "Go Saints!" << endl;
        counter++;
    }
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

