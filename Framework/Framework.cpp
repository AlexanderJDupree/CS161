/*********************************************************************
* File: Framework.cpp                                                *
* Description: Prints "Hello World!" to the console                  *
* Author: Alexander DuPree                                           *
* Date: 1/9/2018                                                     *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

// Pre-processor directive
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string name;

    cout << "Hello World!\nWhat is your name?\n> ";
    getline(cin, name);
    cout << "Hello " << name << endl;
    return 0;
}

/*  Escape sequences
    \n newline
    \t tab
    \b backspace
    \r carriage return
    \a alarm
*/
