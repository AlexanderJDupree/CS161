/*********************************************************************
* File: wk2_dataType_var.cpp                                         *
* Description: demonstration of data types                           *
* Author: Alexander DuPree                                           *
* Date: 1/16/2018                                                    *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>
#include <iomanip> // setprecision, fixed, showpoint, setw
using namespace std;

int main()
{
    // variable declarations
    short myShort;
    unsigned short myUnsignedShort;
    int myInt;
    long long myLong; // code::blocks compiler treats longs and ints as the same
    float myFloat;
    double myDouble;

    const float PI = 3.14159;

    bool myBool = true;
    cout << "myBool:  " << myBool << endl;
    cout << boolalpha << myBool << endl; // outputs true or false not 0/1

    int intA{5},
        intB{7};
    int intC = 10; // either or but stick to one type of assignment = or {}

    float answer;
    answer = intA / static_cast<float>(intB); // type-cast to conduct float division
    cout << showpoint << setprecision(3);
    cout << "answer:  " << answer << endl;

/*
    // assignments
    myShort = 32766;
    myUnsignedShort = 65535;
    myInt = 22345678987;
    myLong = 22345678987;
    myFloat = 12.124516757;

    cout << "my short:  " << myShort << endl;
    cout << "my Unsignedshort:  " << myUnsignedShort << endl;
    cout << "my int:  " << myInt << endl;
    cout << "my long:  " << myLong << endl;
    cout << "my float:  " << myFloat << endl;
    cout << showpoint << fixed;
    cout << "my float rounded:  " << setprecision(2) << myFloat <<endl;
    cout << endl<< endl;
*/

    return 0;
}

