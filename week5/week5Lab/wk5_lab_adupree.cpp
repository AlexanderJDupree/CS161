/******************************************************************************
* File: wk5_lab_adupree.cpp
* Description: functions examples for while loop, do-while loop, and for loop.
* Author: Alexander DuPree
* Date: 2/06/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int getInput(string prompt, string errorMessage, int _max, int _min);
bool isValidNum(string errorMessage, int userInput, int _max, int _min);

void whileLoopExample();
void doWhileExample();
void forLoopExample();

int main()
{
    whileLoopExample();

    doWhileExample();

    forLoopExample();

    return 0;
}

void whileLoopExample()
{
    int numOfLoops;
    int counter = 0;

    numOfLoops = getInput("Enter number of times to loop:  ",
                       "Positive integers only.",
                       1000, 0);
    while (counter < numOfLoops)
    {
        cout << "Go Saints!" << endl;
        counter++;
    }
    return;
}

void doWhileExample()
{
    char ch;
    do {
        cout << "\nEnter any character (Enter '$' to stop):  ";
        cin.ignore(100, '\n'); // clear previous \n character in stream
        cin.get(ch);
        cout << "\nAscii code for character '" << ch << "' is: "
             << static_cast<int>(ch) << endl;
    } while (ch != '$');
    return;
}

void forLoopExample()
{
    char symbol;
    int numOfSymbols;

    cout << "\nEnter the symbol to print:  ";
    cin.ignore(100, '\n');
    cin.get(symbol);
    numOfSymbols = getInput("Enter the number of times to show symbol:  ",
                            "Positive integers only.",
                            1000, 0);

    for (int i = 0; i < numOfSymbols; i++)
    {
        cout << symbol;
    }
    cout << endl;
    return;
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

