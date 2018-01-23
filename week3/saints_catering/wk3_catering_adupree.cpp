/*********************************************************************
* File: wk3_catering_adupree.cpp                                     *
* Description: Provides billing statement for catering services      *
* Author: Alexander DuPree                                           *
* Date: 1/23/2018                                                    *
* Compiler: Code::Blocks17.12                                        *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/* contains two arrays, one array for items, and another that
reflects the price of that item */
struct Menu
{
    string item[4] = {"Hot Dogs", "Hamburgers", "Grilled Cheese",
                      "BBQ Ribs"};
    float price[4] = {1.25, 2.50, 1.99, 3.99};
};


void intro();
void displayMenu(const Menu, const int);
void displayBill(const Menu, const int, const int, const float);
int getValidInput(string);
float calculateTotalCost(const Menu, const int, const int);
bool isValidNum(const string);

void intro()
{
    cout << "\t\tWelcome to Saints Catering!" << endl;
    cout << "\nYou need to let us know how many people will be "
         << "attending the event." << endl;
}

void displayMenu(Menu menu, int menuSize)
{
    cout << "\n Now, you need to let us know what you want to eat.";
    cout << endl;

    for (int i; i < menuSize; i++)
    {
        cout << '\t' << i + 1 << ". " << menu.item[i] << endl;
    }
}

void displayBill(Menu menu, int numOfGuests, int menuChoice, float totalCost)
{
    cout << "\n\n\t\tSaints Catering\n\t\tGresham, OR" << endl;
    cout << "\nMenu Selection\t\tPrice Per Person\tServings\tTotal Cost";
    cout << "\n---------------------------------------------------------"
         << "-----------------" << endl;
    cout << menu.item[menuChoice - 1] << "\t\t    "
         << setprecision(2) << fixed
         << menu.price[menuChoice - 1] << "\t\t  "
         << numOfGuests << "\t\t  "
         << totalCost << endl;
    cout << "\nThank you for your business!\n" << endl;
}

int getValidInput(string prompt)
{
    string userInput;

    bool isInt = false;
    do {
        cout << prompt;
        getline(cin, userInput);
        isInt = isValidNum(userInput);
    }while (!isInt);

    return stoi(userInput);
}

float calculateTotalCost(Menu menu, int numOfGuests, int menuChoice)
{
    return menu.price[menuChoice - 1] * numOfGuests;
}

bool isValidNum(const string userInput)
{
    // Ranged based for loop to iterate through user input
    for (char c : userInput)
    {
        if (isalpha(c) || c == '.' || c == '-')
        {
            cout << userInput << " is invalid. Enter a positive whole number."
                 << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    Menu menu; // instantiates menu object

    // Calculates the size of the menu array
    int menuSize = (sizeof(menu.item)/sizeof(*menu.item));

    int numOfGuests = 0;
    int menuChoice = 0;

    float totalCost = 0;

    intro();
    numOfGuests = getValidInput("\nHow many people will be eating?  ");

    displayMenu(menu, menuSize);
    // continuous loop to ensure menu choice is a valid selection.
    do {
       menuChoice = getValidInput("\nEnter the number of your choice:  ");
    }while(menuChoice > menuSize || menuChoice <= 0);

    totalCost = calculateTotalCost(menu, numOfGuests, menuChoice);

    displayBill(menu, numOfGuests, menuChoice, totalCost);

    return 0;
}

