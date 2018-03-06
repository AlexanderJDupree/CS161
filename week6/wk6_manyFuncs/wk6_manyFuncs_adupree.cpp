/******************************************************************************
* File: wk6_manyFuncs_adupree.cpp
* Description: performas multiple function demonstrations
* Author: Alexander DuPree
* Date: 2/13/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void instructions();
void displayPoweredInt(int PoweredInt, int base, int power);
void alphaStrings(string string1, string string2);
// receives the users strings and prints them out in alphabetical order
void repeatChar(char symbol, int base);
// uses a for loop to print a symbol 'base' times on the same line. Buffers
// output with a newline at the start and end of function.
void resetInputStream();
//resets failure state and discards bad characters on any input that failed.

int poweredInteger(int base, int power);
// returns calculated base to the nth power.

string getInput(string prompt);
// overloaded getInput function allows us to handle input for just strings
// with no data validation.`

template <class T> T getInput(string prompt, string errorMessage, int _min);
// Use of a template so the getInput function can return either a character or
//  an integer and perform data validation for each.
template <class T> bool isValidInput(string errorMessage, T userInput, int _min);
// isValidInput is called within the getInput function, if input stream is in a
// failed state or the input value was less than _min, function calls
// resetInputStream() and returns false. Otherwise, returns true.

int main()
{
    int base,
        power,
        poweredInt;
    char symbol;
    string string1,
           string2;

    instructions();
    base = getInput<int>(
                "\nEnter the basis of computing a power (positive integers only):  ",
                "Invalid basis, positive integers only.", 0);
    power = getInput<int>(
                "\nNow, enter the power to use:  ",
                "Invalid power, positive integers only.", 0);
    symbol = getInput<char>(
                "\nPlease enter a character to be repeated:  ",
                "Please enter any character.", 0);

    resetInputStream(); // gets stream ready for use of getline() to grab input.
    string1 = getInput("\nFinally, enter two strings, pressing ENTER after each:\n");
    string2 = getInput("");

    poweredInt = poweredInteger(base, power); // calculate poweredInt
    displayPoweredInt(poweredInt, base, power);
    repeatChar(symbol, base);
    alphaStrings(string1, string2);

    return 0;
}

void instructions()
{
    cout << "\t\tVARIOUS FUNCTIONS" << endl;
    cout << "\nThis program will demonstrate the use of functions that "
         << "\nreceive different data types and perform different actions on those."
         << endl;
    return ;
}

void displayPoweredInt(int poweredInt, int base, int power)
{
    cout << endl;
    cout << base << " to the power of " << power << " is " << poweredInt;
    cout << endl;
    return;
}

void alphaStrings(string string1, string string2)
{
    cout << "\nIn alphabetical order:" << endl;
    if (string1 <= string2)
    {
        cout << string1 << endl << string2 << endl;
    }
    else
    {
        cout << string2 << endl << string1 << endl;
    }
    return;
}

void repeatChar(char symbol, int base)
{
    cout << endl;
    for (int i=0; i < base; i++)
    {
        cout << symbol;
    }
    cout << endl;
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

int poweredInteger(int base, int power)
{
    return pow(base, power);
}

string getInput(string prompt)
{
    string userInput;

    cout << prompt;
    getline(cin, userInput);
    return userInput;
}

template <class T>
T getInput(string prompt, string errorMessage, int _min)
{
    T userInput;

    do {
        cout << prompt;
        cin >> userInput;
    } while (!isValidInput(errorMessage, userInput, _min));

    return userInput;
}

template <class T>
bool isValidInput(string errorMessage, T userInput, int _min)
{
    if (cin && userInput > _min)
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

