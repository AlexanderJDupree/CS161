/******************************************************************************
* File: wk7_sandyRiver_driver.cpp
* Description: Asks user to provide info on contact information and desired
               trip package then displays to the user the total cost.
* Author: Alexander DuPree
* Date: 2/26/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include "wk7_sandyRiver.h"

using namespace std;

void intro();
void displayAdventures(Trip& trip);
void displayReceipt(Trip trip, int purchasers);
void resetInputStream();
//resets failure state and discards bad characters on any input that failed.

int getInput(string prompt);
void getInput(string prompt, string& outString);
bool isValidInput(string errorMessage, int userInput, int _max, int _min);
// checks if userInput is out of range bounds, if so calls resetInputStream()
// otherwise, return true.

int main()
{
    Trip trip; // instantiate trip object.
    string name;
    string number;
    int tripChoice;
    int purchasers;

    intro();
    getInput("First, please enter your name:  ", name);
    getInput("\nNow please enter a valid telephone number:  ", number);
    displayAdventures(trip);
    // trip is passed by reference
    do {
        tripChoice = getInput("\nPlease enter the number of desired trip:  ");
    } while (!isValidInput("Invalid selection. Try again.", tripChoice, 3, 0));
    do {
        purchasers = getInput("\nHow many TOTAL people will be purchasing a trip?  ");
    } while (!isValidInput("Please enter a positive number.", purchasers,10000, 0));

    trip.setName(name);
    trip.setNumber(number);
    trip.setTripChoice(tripChoice);
    trip.setPurchasers(purchasers);

    displayReceipt(trip, purchasers);

    return 0;
}

void intro()
{
    cout << "\t\tSANDY RIVER SCUBA ADVENTURES" << endl;
    cout << "******************************************************************\n";
    cout << "\nThis program will help you book the perfect Sandy River adventure!";
    cout << "\nYou will be prompted for your name, number, trip choice as well as";
    cout << "\nthe number of people who will be purchasing a trip.\n" << endl;
    cout << "******************************************************************\n";
    return;
}

void displayAdventures(Trip& trip)
{
    Adventures* adventures;
    // Set up pointer
    adventures = trip.getAdventures();
    // get the address of the adventures array object from the trip class.
    for (int i = 0; i < 3; i++)
    {
        cout << endl;
        cout << '\t' << i + 1 << '.' << " ";
        cout << adventures->adventure << "\t$" << adventures->cost << endl;
        adventures += 1;
        // Increment the pointer to the next address in the array
    }
    return;
}

void displayReceipt(Trip trip, int purchasers)
{
    cout << "\n\n\n\t\tSandy River Scuba Adventures Invoice" << endl;
    cout << "\tInvoice for: " << trip.getName() << "\tNumber: "
         << trip.getNumber() << endl;
    cout << "\nADVENTURE: " << trip.getAdventureName() << endl;
    cout << "\nCOST PER PERSON: $" << trip.getAdventureCost() << endl;
    cout << "\nNUMBER OF PERSONS: " << purchasers << endl;
    cout << "\nTOTAL COST: $" << trip.calculateCost() << endl;

}

void resetInputStream()
{
    // get rid of failure state
    cin.clear();

    // discard 'bad' characters
    cin.ignore(100, '\n');
    return;
}

int getInput(string prompt)
{
    int userInput = 0;
    cout << prompt;
    cin >> userInput;
    return userInput;
}

void getInput(string prompt, string& outString)
{
    cout << prompt;
    getline(cin, outString);
    return;
}

bool isValidInput(string errorMessage, int userInput, int _max, int _min)
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


