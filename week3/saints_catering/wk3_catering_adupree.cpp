/******************************************************************************
* File: wk3_catering_adupree.cpp
* Description: Provides billing statement for catering services
* Author: Alexander DuPree
* Date: 1/23/2018
* Compiler: GNU GCC 5.4.0
* Modifications: Moved main() to top of file.

                 removed constructor side effect of the Menu struct class.
                 created setMenuItemsAndPrice() function to create the menu
                 for the Menu struct.

                 implemented talked about switch structure in the getItemAndPrice
                 function to get the menu item and price from the Menu struct.

                 Added different getInput() function and complementary
                 isValidNum() function for use in getInput.

*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/* contains two arrays, one array for items, and another that
reflects the price of that item */
struct Menu
{
    string item[4];
    float price[4];
};


void intro();
void setMenuItemsAndPrice(Menu& menu);
// Sets the menu and price arrays within our struct Menu class.
void getItemAndPrice(Menu menu, string &menuItem, float &menuPrice,
                     int menuChoice);
// Modifies the menuItem and menuPrice variables using a switch
// structure. These variables are passed by value into the
// final displayBill function.

void displayMenu(Menu menu, int menuSize);
// iterates through the menu array and prints it to the user.

void displayBill(string menuItem, int numOfGuests, int menuChoice,
                 float menuPrice, float totalCost);
float calculateTotalCost(float menuPrice, int numOfGuests);
int getInput(string prompt, string errorMessage, int _max, int _min);
// Prints prompt to user, grabs input from user, attempts to return integer
// after checking the input was within the  min/max range.

bool isValidNum(string errorMessage, int userInput, int _max, int _min);
// returns true if user input is within  min/max range. Otherwise,
// prints an error message, flushes input stream and returns false.

int main()
{
    Menu menu; // instantiates menu object

    // Calculates the size of the menu array
    int menuSize;
    int numOfGuests = 0;
    int menuChoice = 0;

    float totalCost = 0;
    float menuPrice = 0; // price of menu item.

    string menuItem;

    // create items and prices for menu.
    setMenuItemsAndPrice(menu);
    // Calculates the size of the menu array
    menuSize = (sizeof(menu.item)/sizeof(*menu.item));

    intro();
    numOfGuests = getInput("\nHow many people will be eating?  ",
                           "Error: positive integers between 1 - 10000 only.",
                           10000, 0);

    displayMenu(menu, menuSize);

    menuChoice = getInput("\nEnter the number of your choice:  ",
                          "Please enter a number matches with the menu.",
                          menuSize, 0);

    // menuItem and menuPrice are passed by reference.
    getItemAndPrice(menu, menuItem, menuPrice, menuChoice);
    totalCost = calculateTotalCost(menuPrice, numOfGuests);

    displayBill(menuItem, numOfGuests, menuChoice, menuPrice, totalCost);

    return 0;
}


void intro()
{
    cout << "\t\tWelcome to Saints Catering!" << endl;
    cout << "\nYou need to let us know how many people will be "
         << "attending the event." << endl;
}

void setMenuItemsAndPrice(Menu& menu)
{
    menu.item[0] = "Hot Dogs";
    menu.item[1] = "Hamburgers";
    menu.item[2] = "Grilled Cheese";
    menu.item[3] = "BBQ Ribs";

    menu.price[0] = 1.25;
    menu.price[1] = 2.50;
    menu.price[2] = 1.99;
    menu.price[3] = 3.99;
    return;
}

void getItemAndPrice(Menu menu, string &menuItem, float &menuPrice,
                     int menuChoice)
{
    switch (menuChoice)
    {
        case 1 : menuItem = menu.item[0]; menuPrice = menu.price[0]; break;
        case 2 : menuItem = menu.item[1]; menuPrice = menu.price[1]; break;
        case 3 : menuItem = menu.item[2]; menuPrice = menu.price[2]; break;
        case 4 : menuItem = menu.item[3]; menuPrice = menu.price[3]; break;
        default : menuItem = " "; menuPrice = 0.0;
    }
    return;
}

void displayMenu(Menu menu, int menuSize)
{
    cout << "\nNow, you need to let us know what you want to eat.";
    cout << endl;

    for (int i; i < menuSize; i++)
    {
        cout << '\t' << i + 1 << ". " << menu.item[i] << endl;
    }
}

void displayBill(string menuItem, int numOfGuests, int menuChoice,
                 float menuPrice, float totalCost)
{
    cout << "\n\n\t\tSaints Catering\n\t\tGresham, OR" << endl;
    cout << "\nMenu Selection\t\tPrice Per Person\tServings\tTotal Cost";
    cout << "\n---------------------------------------------------------"
         << "-----------------" << endl;
    cout << menuItem << "\t\t    "
         << setprecision(2) << fixed
         << menuPrice << "\t\t  "
         << numOfGuests << "\t\t  "
         << totalCost << endl;
    cout << "\nThank you for your business!\n" << endl;
}

int getInput(string prompt, string errorMessage, int _max, int _min);

float calculateTotalCost(float menuPrice, int numOfGuests)
{
    return menuPrice * numOfGuests;
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

