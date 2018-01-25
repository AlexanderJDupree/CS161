/*********************************************************************
* File: wk3_pairProgram.cpp                                          *
* Description: Tells user what grade they're in college              *
* Author: Alexander DuPree, Lawrence Scroggs                         *
* Date: 1/23/2018                                                    *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void intro()
{
    cout << "This program will tell you how you are doing with your "
         << "water usage" << endl;
}

void getInput(float &quarter, char number)
{
    cout << "\nPlease input your water bill for quarter " << number << ":  ";
    cin >> quarter;
    return;
}

void displayBill(float averageBill, string message)
{
    cout << "You're average monthly bil is " << averageBill << endl;
}

float calculateAverage(float q1, float q2, float q3, float q4)
{
    return (q1 + q2 + q3 + q4) / 4;
}

int main()
{
    float quarter1, // declare variables to store water usage for each
          quarter2, // quarter
          quarter3,
          quarter4,
          averageBill; // Holds the calculated average monthly bill

    intro();

    getInput(quarter1, '1');
    getInput(quarter2, '2');
    getInput(quarter3, '3');
    getInput(quarter4, '4');

    if (quarter1 < 0 || quarter2 < 0 || quarter3 < 0 || quarter4 < 0)
    {
        cout << "\nThere was at least one invalid number" << endl;
    }
    else
    {
        averageBill = calculateAverage(quarter1, quarter2, quarter3, quarter4);

        if (averageBill > 75)
        {
            displayBill(averageBill, "You're using too much water")
        }
        else if (averageBill > 25 and  averageBill <= 75)
        {
            displayBill(averageBill, "You're doing good")
        }
        else
        {
            displayBill(averageBill, "Good job conserving water!")
        }
    }


    return 0;
}

