/*********************************************************************
* File: wk2_saintsPizza_adupree.cpp                                  *
* Description: Displays pizza sales info for saints pizza            *
* Author: Alexander DuPree                                           *
* Date: 1/16/2018                                                    *
* Compiler: Code::Blocks 16.01                                       *
* Modifications: Moved main to top of program. simplified the        *
*                getPizzasSoldBySize function to not accomodate error*
*                checking because I could not find a way to convert  *
*                a string to an int without using stoi(). If user    *
*                decides to enter a non-numeric character the program*
*                will now just quit.                                 *
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void intro();
void displayResults(const int, const vector<pair<string, int> >);
int getPizzaSoldBySize(const string);
bool isValidNum(const string);

int main()
{
    int totalSold;

    //Vector of pairs to be used as an out parameter for grabbing input
    vector<pair<string, int> > pizzasSoldBySize({{"Small", 0}, {"Medium", 0}, {"Large", 0},
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

void intro()
{
    cout << "\t\tSAINTS PIZZA SALES" << endl << endl;
    cout << "Enter the number of each type of pizza sold this month.";
    cout << endl;
}

int getPizzaSoldBySize(const string pizzaSize)
{
    /* Changed pizzasSold from string to int, I won't be conducting error
    checking because I could not figure out a solid work around for converting
    a string to an int without using stoi() */
    int pizzasSold;

    cout << pizzaSize << ":  ";
    cin >> pizzasSold;

    return pizzasSold;
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

