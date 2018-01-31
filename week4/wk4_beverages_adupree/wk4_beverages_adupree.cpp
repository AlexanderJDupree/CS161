/******************************************************************************
* File: wk4_beverages_adupree.cpp
* Description: performs a survey tally on beverages, displays tally at the end.
* Author: Alexander DuPree
* Date: 1/30/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void intro();
void setSurveyChoices(vector<pair<string, int>> &surveyChoices);
// Appends correct key value pairs to the surveyChoices vector.

void displaySurveyChoices(vector<pair<string, int>> &surveyChoices);
void updateSurvey(vector<pair<string, int>> &surveyChoices, int choice);
//increments a key's value based on what the user voted for in the survey.

void displaySurveyResults(vector<pair<string, int>> &surveyChoices);

int getInput(string prompt, string errorMessage, int _max, int _min);
// Prints prompt to user, grabs input from user, attempts to return integer
// after checking the input was within the  min/max range.

bool isValidNum(string errorMessage, int userInput, int _max, int _min);
// returns true if user input is within  min/max range. Otherwise,
// prints an error message, flushes input stream and returns false.

string createPrompt(int personCounter);
// creates string to prompt user with the correct value of the person surveyed.

int main()
{
    int choice; // sentinel for do-while loop to hold user input.
    int personCounter = 1;

    // creates vector of pairs to hold survey choices
    vector<pair<string, int>> surveyChoices;

    intro();
    setSurveyChoices(surveyChoices); // assigns vector correct key value pairs
    displaySurveyChoices(surveyChoices);

    do {
        string errorMessage = "Please choose the number of the corresponding beverage.";
        choice = getInput(createPrompt(personCounter), errorMessage,
                                       surveyChoices.size(), -1);
        updateSurvey(surveyChoices, choice);
        personCounter++;
    }while(choice != 0); // sentinel controlled loop.

    displaySurveyResults(surveyChoices);

    return 0;
}

void intro()
{
    cout << "\t\tBEVERAGE SURVEY" << endl;
}

void setSurveyChoices(vector<pair<string, int>> &surveyChoices)
{
    surveyChoices.push_back(pair<string, int>("Coffee", 0));
    surveyChoices.push_back(pair<string, int>("Tea", 0));
    surveyChoices.push_back(pair<string, int>("Cola", 0));
    surveyChoices.push_back(pair<string, int>("Orange Juice", 0));
}

void displaySurveyChoices(vector<pair<string, int>> &surveyChoices)
{
    for (int i=0; i < surveyChoices.size(); i++)
    {
        cout << i + 1 << ". " << surveyChoices[i].first << endl;
    }
    cout << "Enter 0 to quit" << endl;
    return;
}

void updateSurvey(vector<pair<string, int>> &surveyChoices, int choice)
{
    switch(choice)
    {
        case 1 : surveyChoices[0].second += 1; break;
        case 2 : surveyChoices[1].second += 1; break;
        case 3 : surveyChoices[2].second += 1; break;
        case 4 : surveyChoices[3].second += 1; break;
        default : return;
    }
}

void displaySurveyResults(vector<pair<string, int>> &surveyChoices)
{
    cout << "\n\tSURVEY RESULTS" << endl;
    cout << "\nBeverage    Number of Votes" << endl;
    cout << "******************************" << endl;
    // loop through surveyChoices vector and prints the key and its value.
    for (auto& choice : surveyChoices)
    {
        cout << setw(16) << left <<choice.first;
        cout << choice.second << endl;
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


string createPrompt(int personCounter)
{
    ostringstream prompt;
    prompt << "\nEnter the favorite beverage of person #"
           << personCounter <<":  ";
    return prompt.str();
}
