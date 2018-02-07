/******************************************************************************
* File: wk5_powerLoop_adupree.cpp
* Description: Shows the powers of 0 - 10 of a number entered by user.
* Author: Alexander DuPree
* Date: 1/30/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>

using namespace std;

void intro(float baseNumber);
void displayResult(float baseNumber, float powerNumber, int index);
void resetInputStream();
//resets failure state and discards bad characters on any input that failed.

float calculatePower(float baseNumber, int index);

template <class T> T getInput(string prompt, string errorMessage);
// Use of a template class here so the getInput function can return either a
// character or an integer.

bool isValidInput(string errorMessage);
// function checks if input stream is in failed state, if so it will clear
// the failed state, discard bad characters and return false. otherwise,
// return true.

int main()
{
    // using a float here so user to get the powers of any real number.
    float baseNumber;
    float powerNumber;
    char continueLoop;
    int index = 0;

    baseNumber = getInput<float>("Enter a number: ",
                                 "Please enter any real number.");
    intro(baseNumber);

    do {
        powerNumber = calculatePower(baseNumber, index);
        displayResult(baseNumber, powerNumber, index);
        continueLoop = getInput<char>(
                            "Enter 'Q' to quit or any other key to continue. ",
                            "Please press any key, then press enter.");
        index++;
    } while (tolower(continueLoop) != 'q' && index != 11);

    return 0;
}

void intro(float baseNumber)
{
    cout << "This program will raise " << baseNumber << " to the powers of 0 "
         << "through 10." << endl;
    return;
}

void displayResult(float baseNumber, float powerNumber, int index)
{
    cout << '\n' << baseNumber << " to the power of " << index << " is: "
         << powerNumber << endl;
    return;
}

void resetInputStream()
{
    // get rid of failure state
    cin.clear();

    // discard 'bad' characters
    cin.ignore(100, '\n');
    return;
}

float calculatePower(float baseNumber, int index)
{
    float power = 1.0;

    for (int i = 1; i <= index; i++)
    {
        power = power * baseNumber;
    }
    return power;
}

template <class T>
T getInput(string prompt, string errorMessage)
{
    T userInput;

    do {
        cout << prompt;
        cin >> userInput;
    } while (!isValidInput(errorMessage));

    return userInput;
}

bool isValidInput(string errorMessage)
{
    if (cin)
    {
        return true;
    }
    else
    {
        cout << errorMessage << endl;
        resetInputStream();
        return false;
    }
}
