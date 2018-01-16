/*********************************************************************
* File: week2_columns.cpp                                            *
* Description: demonstration of using setw to set up columns         *
* Author: Alexander DuPree                                           *
* Date: 1/9/2018                                                     *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x = 15;
    int y = 7654;
    int z = 123;
    int q = 23456;

    cout <<"12345678901234567890" << endl;

    cout << setw(5) << setfill('^') << x << setw(6) << setfill('^') << y << endl;
    cout << setw(5) << left << z << setw(9) << q << endl;

    return 0;
}

