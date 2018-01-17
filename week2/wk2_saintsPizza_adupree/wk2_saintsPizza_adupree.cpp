/*********************************************************************
* File: wk2_saintsPizza_adupree.cpp                                  *
* Description: Displays pizza sales info for saints pizza            *
* Author: Alexander DuPree                                           *
* Date: 1/16/2018                                                    *
* Compiler: Code::Blocks 17.12                                       *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void intro();
void displayResults(const int, const vector<pair<string, int>>);
int getPizzaSoldBySize(const string);
bool isValidNum(const string);

void intro()
{
    cout << "\t\tSAINTS PIZZA SALES" << endl << endl;
    cout << "Enter the number of each type of pizza sold this month.";
    cout << endl;
}

int getPizzaSoldBySize(const string pizzaSize)
{
    /* A string is used here to store user input because we need to
    iterate through each character of the input to ensure the input
    is a valid number */
    string pizzasSold;

    bool isInt = false;
    do {
        cout << pizzaSize << ":  ";
        getline(cin, pizzasSold);
        isInt = isValidNum(pizzasSold);
    }while (!isInt);

    // converts string to int
    return stoi(pizzasSold);
}

bool isValidNum(const string userInput)
{
    for (char c : userInput)
    {
        if (isalpha(c) || c == '.')
        {
            cout << userInput << " is invalid. Enter a whole number."
                 << endl;
            return false;
        }
    }
    return true;
}

void displayResults(const int totalSold,
                    const vector<pair<string, int>> pizzasSoldBySize)
{
    cout << "\n\nTotal number of pizzas sold:  " << totalSold << endl;
    cout << "\nPercentage of total for each size:" << endl;

    for (auto pizzaSize : pizzasSoldBySize)
    {
        float percentOfTotal = (pizzaSize.second /
                                static_cast<float>(totalSold)) * 100;

        cout << setw(6) << left << pizzaSize.first << '\t'
             << setw(6) << right << setprecision(1)
             << fixed << percentOfTotal  << endl;
    }
}

int main()
{
    int totalSold;

    //Vector of pairs to be used as an out parameter for grabbing input
    vector<pair<string, int>> pizzasSoldBySize({{"Small", 0}, {"Medium", 0}, {"Large", 0},
                                        {"Family", 0}});

    intro();
    for (auto& pizzaSize : pizzasSoldBySize)
    {
        pizzaSize.second = getPizzaSoldBySize(pizzaSize.first);
        totalSold += pizzaSize.second;
    }
    displayResults(totalSold, pizzasSoldBySize);

    return 0;
}

