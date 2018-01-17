/*********************************************************************
* File: wk2_numberFuncs_adupree.cpp                                  *
* Description: Demos math functions in C++.                          *
* Author: Alexander DuPree                                           *
* Date: 1/16/2018                                                    *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class MathFunctions
{
    float num1,
          num2;
public:
    // default constructor sets member variables to 0
    MathFunctions() {num1 = 0; num2 = 0;};

    void setValues(string, int);
    void displayPOW();
    void displaySQRT();
    void displaySIN();
    void displayABS();
    void displayFABS();
    void displayFLOOR();
    void displayCEIL();
    void displayHYPOT();
};

void MathFunctions::setValues(string prompt, int inputNum)
{
    cout << endl << prompt << endl << ">  ";
    if (inputNum > 1)
    {
        cin >> num1 >> num2;
    }
    else
    {
        cin >> num1;
    }
}

void MathFunctions::displayPOW()
{
    cout << "\nPOW" << endl;
    cout << num1 << " raised to the power of " << num2
         << " = " << pow(num1, num2) << endl;
}

void MathFunctions::displayHYPOT()
{
    cout << "\nHYPOT" << endl;
    cout << "A triangle with sides " << num1 << " and " << num2
          << " has a hypotenuse of " << hypot(num1, num2) << endl;
}

void MathFunctions::displaySQRT()
{
    cout << "\nSQRT" << endl;
    cout << "The square root of " << num1
          << " = " << sqrt(num1) << endl;
}

void MathFunctions::displaySIN()
{
    cout << "\nSIN" << endl;
    cout << "The sine of " << num1 << " radians"
          << " = " << sin(num1) << endl;
}

void MathFunctions::displayABS()
{
    cout << "\nABS" << endl;
    cout << "The absolute value of " << num1
          << " = " << abs(num1) << endl;
}

void MathFunctions::displayFABS()
{
    cout << "\nFABS" << endl;
    cout << "The absolute value of " << num1
          << " = " << fabs(num1) << endl;
}

void MathFunctions::displayFLOOR()
{
    cout << "\nFLOOR" << endl;
    cout << "The floor of " << num1
         << " = " << floor(num1) << endl;

}

void MathFunctions::displayCEIL()
{
    cout << "\nCeiling" << endl;
    cout << "The ceiling of " << num1
         << " = " << ceil(num1) << endl;
}
int main()
{
    MathFunctions mathFunction[7];

    vector<pair<string, int>>
    userPrompt({{"Enter two integers, one for the base and one for the power:",  2},
                {"Enter the lengths of 2 sides of a triangle, as whole numbers:",2},
                {"Enter an integer to find the square root of:", 1},
                {"Enter a negative integer:", 1},
                {"Enter a negative floating point number:", 1},
                {"Enter an integer to find the sine of:", 1},
                {"Enter a floating point number, positive or negative:", 1}});

    // loop through userPrompt list and set values for each MathFunctions object
    for (int i=0; i < userPrompt.size(); i++)
    {
        mathFunction[i].setValues(userPrompt[i].first, userPrompt[i].second);
    }
    mathFunction[0].displayPOW();
    mathFunction[1].displayHYPOT();
    mathFunction[2].displaySQRT();
    mathFunction[3].displayABS();
    mathFunction[4].displayFABS();
    mathFunction[5].displaySIN();
    mathFunction[6].displayFLOOR();
    mathFunction[6].displayCEIL();

    return 0;
}

