/******************************************************************************
* File: wk8_gradesArray_adupree.cpp
* Description: Asks for and computes the average of 5 students grades
* Author: Alexander DuPree
* Date: 2/27/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

void intro();
void displayGrades(const float grades[], const int SIZE);
// Loops through grades array and prints elements
void displayAverageGrade(float average);
string createPrompt(int index);
// For use in getInput function. Creates the prompt with the correct student
// index as a string.
float calculateAverage(const float grades[], const int SIZE);
// Loops through each element in the grades array and adds accumulates the sum.
// returns the sum / size of the array.
float getInput(string prompt, string errorMessage, int _max, int _min);
bool isValidNum(string errorMessage, float userInput, int _max, int _min);


int main()
{
    const int SIZE = 5;
    float grades[SIZE] = {0};
    float average = 0;

    intro();

    for (int i = 0; i < SIZE; i++)
    {
        grades[i] = getInput(createPrompt(i + 1),
                             "Invalid number try again.",
                             100, 0);
    }
    average = calculateAverage(grades, SIZE);

    displayGrades(grades, SIZE);
    displayAverageGrade(average);

    return 0;
}

void intro()
{
    cout << "\t\tAVERAGE GRADE\n" << endl;
    cout << "Enter the grades of 5 students, each on a seperate line." << endl;
    cout << "The grades must be in the range of 0 - 100.\n" << endl;
    return;
}

void displayGrades(const float grades[], const int SIZE)
{
    cout << "\nThe grades entered were:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << grades[i] << "  ";
    }
    return;
}

void displayAverageGrade(float average)
{
    cout << "\n\nThe average of the grades is " << fixed << setprecision(1)
         << average << endl;
}

string createPrompt(int index)
{
    ostringstream prompt;
    prompt << "Student " << index << ":  ";
    return prompt.str();
}

float calculateAverage(const float grades[], const int SIZE)
{
    float sum = 0;
    float average = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += grades[i];
    }
    average = sum / SIZE;
    return average;
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
    if (userInput >= _min && userInput <= _max)
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

