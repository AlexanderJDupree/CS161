/******************************************************************************
* File: wk6_grosspay_adupree.cpp
* Description: Calculates and displays the gross wages of the user.
* Author: Alexander DuPree
* Date: 2/13/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

void welcome();
void displayPay(float grossPay);
void resetInputStream();
//resets failure state and discards bad characters on any input that failed.

float calculatePay(float hoursWorked, float rateOfPay);
float getInput(string prompt, string errorMessage, int _max, int _min);
bool isValidNum(string errorMessage, float userInput, int _max, int _min);

int main()
{
    float hoursWorked;
    float rateOfPay;

    welcome();

    hoursWorked = getInput("\nHow many hours were worked? (0-40)  ",
                           "You must enter a number between 0 to 40.",
                           40, 0);
    rateOfPay = getInput("\nWhat is your hourly rate of pay? (10-100)  ",
                         "Invalid rate of pay.",
                         100, 10);

    displayPay(calculatePay(hoursWorked, rateOfPay));

    return 0;
}

void welcome()
{
    cout << "\t\tGROSS PAY CALCULATOR" << endl;
    cout << "\nThis program will ask for a number of hours and a rate of pay."
         << "\nThen, you will see what your total pay would be." << endl;
    return;
}

void displayPay(float grosspay)
{
    cout << "\nGross pay = $" << fixed << setprecision(2) << grosspay << endl;
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

float calculatePay(float hoursWorked, float rateOfPay)
{
    return hoursWorked * rateOfPay;
}

float getInput(string prompt, string errorMessage, int _max, int _min)
{
    float userInput = 0;

    do {
    cout << prompt;
    cin >> userInput;
    } while(!isValidNum(errorMessage, userInput, _max, _min));

    return userInput;
}

bool isValidNum(string errorMessage, float userInput, int _max, int _min)
{
    if (userInput > _max || userInput < _min)
    {
        cout << errorMessage << endl;
        resetInputStream();
        return false;
    }
    else
    {
        return true;
    }
}
