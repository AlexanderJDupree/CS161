/*********************************************************************
* File: wk2_cin.cpp                                                  *
* Description: input demo                                            *
* Author: Alexander DuPree                                           *
* Date: 1/9/2018                                                     *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream> //cout, endl, cin
#include <string>
using namespace std;

int main()
{
    float num;
    char symbol;
    string name;

    cout << "Enter a number:  ";
    cin >> num;
    cin.sync();
    cout << "You entered " << num << endl;
    cout << "Enter a character:  ";
    cin.get(symbol); // gets only one character
    cin.sync(); // enter stays in input buffer
    cout << "You entered " << symbol << endl;
    cout << "what is your name?  ";
    getline(cin, name);
    cout << "Hello, " << name << endl;

    return 0;
}

