/******************************************************************************
* File: wk7_quickShop_adupree.cpp
* Description: Calculates and outputs the retail price of an item based on
               turnover time.
* Author: Alexander DuPree
* Date: 2/20/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void instructions();
void giveOutput(double cost, double retailPrice, int turnover);
double price(double cost, int turnover);
// Calculates the retail price of an item based on turnover time.
// assumes the cost and turnover are positive values.
template <class T>
void getInput(string prompt, string errorMessage, T& value, int _min);
// getInput will set the value of the referenced variable when it is within the
// min/max range.
bool isValidNum(string errorMessage, int userInput, int _min);


int main()
{
    double cost,
           retailPrice;
    int turnover;

    instructions();
    getInput("\nEnter the wholesale price of the item:  ",
             "ERROR: Positive values only.",
             cost, 0);
    // cost is passed by reference

    getInput("\nEnter the number of days the item is to be on the shelf:  ",
             "Error: Positive values only.",
             turnover, 0);
    // turnover is passed by reference

    retailPrice = price(cost, turnover);

    giveOutput(cost, retailPrice, turnover);

    return 0;
}

void instructions()
{
    cout << "\t\tRETAIL PRICE CALCULATOR\n" << endl;
    cout << "This program will determine the retail price of an item based on ";
    cout << "\nthe turnover time." << endl;
    return;
}

void giveOutput(double cost, double retailPrice, int turnover)
{
    cout << "\nWholesale: $" << fixed << setprecision(2) << cost << endl;
    cout << "Turnover time:  " << turnover << " days" << endl;
    cout << "Suggested retail price:  $" << fixed << setprecision(2) << retailPrice;
    cout << endl;
    return;
}

double price(double cost, int turnover)
{
    double price;
    if (turnover <= 7)
    {
        price = cost * 1.05;
    }
    else
    {
        price = cost * 1.10;
    }
    return price;
}

template <class T>
void getInput(string prompt, string errorMessage, T& value, int _min)
{
    double userInput = 0.0;

    do {
    cout << prompt;
    cin >> userInput;
    } while(!isValidNum(errorMessage, userInput, _min));

    value = userInput;
    return;
}

bool isValidNum(string errorMessage, int userInput, int _min)
{
    if (userInput > _min)
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

