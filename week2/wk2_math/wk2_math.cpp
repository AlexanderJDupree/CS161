/*********************************************************************
* File: wk2_math.cpp                                                 *
* Description: math.h demo                                           *
* Author: Alexander DuPree                                           *
* Date: 1/9/2018                                                     *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>     // cout, endl
#include <cmath>        // pow, sqrt, abs, fabs, ceil, floor
using namespace std;

int main()
{
    int base,
        power,
        negNumber;
    float squareRoot,
          ceilingNum;

    base = 2;
    power = 4;
    negNumber = -14;
    squareRoot = sqrt(123);
    ceilingNum = 2.3456;

    cout << base << " raised to the power of " << power << " is "
         << pow(base, power) << endl;

    cout << "The sqrt of " << 123 << " is " << squareRoot << endl;

    cout << "The absolute value of " << negNumber << " is "
         << abs(static_cast<float>(negNumber)) << endl;

    cout << "celing applied to " << ceilingNum << " is " << ceil(ceilingNum) << endl;
    cout << "floor applied to " << ceilingNum << " is " << floor(ceilingNum) << endl;

    cout << endl << endl;

    return 0;
}

