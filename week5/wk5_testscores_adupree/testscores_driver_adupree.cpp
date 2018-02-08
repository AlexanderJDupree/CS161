/******************************************************************************
* File: testscores_driver_adupree.cpp
* Description: Calculates and outputs the average test score for each student
               user enters.
* Author: Alexander DuPree
* Date: 2/07/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "testscores_adupree.h"

using namespace std;

void intro();
void displayAverageScore(int studentIndex, float averageScore);
void resetInputStream();
//resets failure state and discards bad characters on any input that failed.

float getInput(string prompt, string errorMessage, int _max, int _min);
// prints prompt, records user input, passes the min/max range and user input
// into isValidInput. Continues to loop until isValidInput returns true.

bool isValidInput(string errorMessage, float userInput, int _max, int _min);
// checks it userInput is out of range bounds, if so it will clear failed stream
// state, discard bad characters and return false. otherwise, return true.

string createPrompt(int scoreIndex, int studentIndex);
// creates a string to prompt user with correct values for score and student

int main()
{
    int numOfStudents;
    int numOfTests;

    intro();

    numOfStudents = getInput("\nfor how many students do you have scores? ",
                             "There needs to be at least one student.",
                             10000, // arbitrary large number for max students
                             0);
    numOfTests = getInput("How many test scores does each student have? ",
                          "There must be at least one test.\n",
                             10000, // arbitrary large number for max tests
                             0);

    for (int i = 1; i <= numOfStudents; i++)
    {
        cout << endl;
        // Create Student object, discarded and recreated after each iteration.
        Student student (numOfTests);
        for (int n = 1; n <= numOfTests; n++)
        {
            int testScore = getInput(createPrompt(n, i),
                                     "Invalid score. Enter a value from 0 to 100\n",
                                     100, -1);
            student.addTestScore(testScore);
        }
        displayAverageScore(i, student.calculateAverage());
    }
    return 0;
}

void intro()
{
    cout << "This program averages test scores." << endl;
    return;
}

void displayAverageScore(int studentIndex, float averageScore)
{
    cout << "\nThe average score for student " << studentIndex << " is "
         << fixed << setprecision(1) << averageScore << endl;
}

void resetInputStream()
{
    // get rid of failure state
    cin.clear();

    // discard 'bad' characters
    cin.ignore(100, '\n');
    return;
}

float getInput(string prompt, string errorMessage, int _max, int _min)
{
    float userInput;

    do {
        cout << prompt;
        cin >> userInput;
    } while (!isValidInput(errorMessage, userInput, _max, _min));

    return userInput;
}

bool isValidInput(string errorMessage, float userInput, int _max, int _min)
{
    if (userInput > _max || userInput <= _min)
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

string createPrompt(int scoreIndex, int studentIndex)
{
    ostringstream prompt;
    prompt << "Enter score " << scoreIndex << " for student " << studentIndex
           << ":  ";
    return prompt.str();
}
