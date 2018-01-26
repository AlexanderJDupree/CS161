/*********************************************************************
* File: wk3_tshirts_adupree.cpp                                      *
* Description: Tells user how many X shirts cost                     *
* Author: Alexander DuPree                                           *
* Date: 1/25/2018                                                    *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

void intro()
{
    cout << "\t\tWelcome to Saints T-shirts!!" << endl;
}

void getShirtsSold(int &shirtsSold)
{
    cout << "\nHow many t-shirts would you like to order?  ";
    cin >> shirtsSold;
    return;
}

void displayCost(float totalCost,int shirtsSold,int discountRate)
{
    cout << "The total cost of " << shirtsSold << " shirt(s) is $"
         << setprecision(2) << fixed << totalCost << '.';
    cout << "\nThis includes a " << discountRate << ".00% discount.";
    cout << "\nYou saved $" << (shirtsSold * 12) - totalCost << '.';
    cout << endl;
}

//This function has the side effect of setting the discount rate as well
// as calculating the total to avoid another if, else if tree.
float calculateTotal(int &discountRate, int shirtsSold)
{
    // shirts are sold at $12 before bulk discount
    if (shirtsSold > 30)
    {
        // 25% discount for 31 or more shirts
        discountRate = 25;
        return (shirtsSold * 12) * .75;
    }
    else if (shirtsSold <= 30 && shirtsSold > 20)
    {
        // 20% discount for 21 - 30  shirts
        discountRate = 20;
        return (shirtsSold * 12) * .80;
    }
    else if (shirtsSold <= 20 && shirtsSold > 10)
    {
        // 15% discount for 11 - 20  shirts
        discountRate = 15;
        return (shirtsSold * 12) * .85;
    }
    else if (shirtsSold <= 10 && shirtsSold >= 5)
    {
        // 10% discount for 21 - 30  shirts
        discountRate = 10;
        return (shirtsSold * 12) * .90;
    }
    else
    {
        discountRate = 0;
        return shirtsSold * 12;
    }
}

int main()
{
    int shirtsSold;
    int discountRate;
    float totalCost;

    intro();
    getShirtsSold(shirtsSold);
    if (shirtsSold < 0)
    {
        cout << "Invalid number." << endl;
    }
    else
    {
        totalCost = calculateTotal(discountRate, shirtsSold);
        displayCost(totalCost, shirtsSold, discountRate);
    }
    return 0;
}

