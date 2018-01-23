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
    if (collegeYear >= 4)
    {
        cout << "You should be finishing up soon!";
    }
    else if (collegeYear > 0 )
    {
        switch(collegeYear)
        {
            case 1: cout << "You're a freshman" << endl; break;
            case 2: cout << "You're a sophomore" << endl;break;
            case 3: cout << "You're a junior" << endl; break;
        }

    }
    else
    {
        cout << "This is an invalid number. You are not ready for college";
        cout << endl;
    }

    cout << endl;
    return 0;
}

