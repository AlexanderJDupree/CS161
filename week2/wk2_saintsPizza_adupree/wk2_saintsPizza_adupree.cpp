/*********************************************************************
* File: wk2_saintsPizza_adupree.cpp                                  *
* Description: Displays pizza sales info for saints pizza            *
* Author: Alexander DuPree                                           *
* Date: 1/16/2018                                                    *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>
#include <map>
using namespace std;

void getInput(const char[4][7]);
void displayOutput();
void intro();

void intro()
{
    cout << "\t\tSAINTS PIZZA SALES" << endl << endl;
}

void getPizzaSoldBySize(const char[4][7] PIZZA_SIZES)
{
    return;
}

int main()
{
    // creates list of pizza sizes for use in input map
    const char PIZZA_SIZES[4][7] = {"Small", "Medium", "Large", "Family"};

    intro();
    getPizzaSoldBySize(PIZZA_SIZES);

    return 0;
}

