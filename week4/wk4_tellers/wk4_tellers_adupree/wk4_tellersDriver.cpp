/******************************************************************************
* File: wk3_tellersDriver_adupree.cpp
* Description: Outputs the total number of sick days missed by tellers in the
               last 3 years at saints bank.
* Author: Alexander DuPree
* Date: 1/30/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "wk4_tellers.h"

using namespace std;

void intro();
void displayDaysMissed(int numOfTellers, int totalMissedDays);
void getDaysMissedPerYear(int &year1, int &year2, int &year3, int tellerNumber);
// modifies value of days of missed work for years 1 - 3.

int getInput(string prompt, string errorMessage, int _max, int _min);
// returns integer within exclusive range of min & max. Continues to
// ask for valid input.

int calculateTotalSickDays(vector<Teller> tellers);
// returns total number of sick days used from all tellers in the Teller vector.

bool isValidNum(string errorMessage, int userInput, int _max, int _min);
// returns true if user input within the range of min & max. Otherwise, prints
// an error message, flushes input stream and returns false.

string createPrompt(int tellerNumber, int year);
// creates a string to prompt user with correct values for teller and year.

int main()
{
    int numOfTellers, // number of tellers employed at saints bank
        totalMissedDays; // total number of missed days across all tellers

    vector<Teller> tellers; // Initialize empty vector to hold all Teller objects.

    intro();

    numOfTellers = getInput(
                   "\nHow many tellers were employed for the last three years?  ",
                    "Invalid input, positive integers only",
                    1000, // arbitrary large int for max value.
                    0 );

    for(int i = 0; i < numOfTellers; i++)
    {
        int year1, year2, year3;

        cout << endl;

        getDaysMissedPerYear(year1, year2, year3, i+1);
        Teller teller(year1, year2, year3);
        tellers.push_back(teller);
    }

    totalMissedDays = calculateTotalSickDays(tellers);

    displayDaysMissed(numOfTellers, totalMissedDays);

    return 0;
}

void intro()
{
    cout << "\t\tSAINTS BANK OF GRESHAM" << endl;
    cout << "\t\t - Sick Days Report - " << endl;
    return;
}

void displayDaysMissed(int numOfTellers, int totalMissedDays)
{
    cout << "\nThe " << numOfTellers << " tellers missed work for sickness "
         << totalMissedDays << " days in the last 3 years." << endl;
    return;
}

void getDaysMissedPerYear(int &year1, int &year2, int &year3, int tellerNumber)
{
    string errorMessage = "Invalid number of sick days.";
    year1 = getInput(createPrompt(tellerNumber, 1), errorMessage, 366, -1);
    year2 = getInput(createPrompt(tellerNumber, 2), errorMessage, 366, -1);
    year3 = getInput(createPrompt(tellerNumber, 3), errorMessage, 366, -1);
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

int calculateTotalSickDays(vector<Teller> tellers)
{
    int totalSickDays = 0;

    for (Teller& teller : tellers)
    {
        totalSickDays += teller.getTotalDaysMissed();
    }
    return totalSickDays;
}

bool isValidNum(string errorMessage, int userInput, int _max, int _min)
{
    if (userInput > _min && userInput < _max)
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

string createPrompt(int tellerNumber, int year)
{
    ostringstream prompt;
    prompt << "How many days was teller " << tellerNumber << " sick in year "
           << year << "?  ";
    return prompt.str();
}
