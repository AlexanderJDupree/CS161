/*********************************************************************
* File: wk3_pairProgram.cpp                                          *
* Description: Tells user what grade they're in college              *
* Author: Alexander DuPree, Lawrence Scroggs                         *
* Date: 1/23/2018                                                    *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>

using namespace std;

void intro()
{
    cout << "\t\tYEAR IN COLLEGE" << endl;
}

void getInput(int &collegeYear)
{
    cout << "\nWhat is your year in college?  ";
    cin >> collegeYear;
}

int main()
{
    int collegeYear;

    intro();
    getInput(collegeYear);
    cout << collegeYear << endl;
    return 0;
}

