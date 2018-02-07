/*********************************************************************
* File: wk3_tuition_adupree.cpp                                      *
* Description: Tells user how tuition costs                          *
* Author: Alexander DuPree                                           *
* Date: 1/25/2018                                                    *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/* I haven't been separating my classes into their own header and .cpp
files because at the beginning of the term we were instructed to only
turn in one .cpp file per assignment. If you'd like me to separate my
files when I turn them in I definitely can. Otherwise, I can just
separate them through comment slashes. */


/* StudentTuition class holds the cost for tuition and housing as well
as the setter methods to change these variables based on user input. */
class StudentTuition
{
public:

    int tuition;
    int housing;
    int total;

    StudentTuition(); //constructor

    void setTuition(bool status);
    void setHousing(bool status);
    void setTotal();

};

//////////////////////////////////////////////////////////////////////

// Default student is a non-resident that requires housing.
StudentTuition::StudentTuition()
{
    tuition = 4500;
    housing = 3500;
}

void StudentTuition::setTuition(bool status)
{
    // If status is true, the tuition is set to in-state prices
    if (status)
    {
        tuition = 3000;
    }
    return;

}

void StudentTuition::setHousing(bool status)
{
    if (status) // if student is state resident, tuition = 3000
    {
        if (tuition == 3000)
        {
            housing = 2500;
        }
        else // else for non-resident students
        {
            return;
        }
    }
    else
    {
        housing = 0;
    }

}

void StudentTuition::setTotal()
{
    total = tuition + housing;
    return;
}

//////////////////////////////////////////////////////////////////////

void intro()
{
    cout << "\t\tUNIVERSITY OF TROUTDALE" << endl;
    cout << "\t\tTotal Cost Calculator" << endl;
}

/* We use a dynamic getStatus function here to get the residency and
housing requirements of the student. This prevents having to write
two status seeking functions on a yes or no type question to user. */
bool getStatus(const string prompt)
{
    string input;
    cout << prompt << "  ";
    getline(cin, input);

    //Because there is only 2 questions being asked, we switch on the
    // first character of the prompt.
    switch(prompt[0])
    {
    case 'A':
        switch (tolower(input[0])) // convert character to lowercase
        {
            case 'i' : return true; break;
            case 'o' : return false; break;
            default :
                cout << "Error: invalid input, defaulting to out-of-state\n";
                return false;
        }; break;

    default :
        switch (tolower(input[0]))
        {
            case 'y' : return true; break;
            case 'n' : return false; break;
            default :
                cout << "Error: invalid input, defaulting to no housing\n";
                return false;
        }; break;
    }
}

void displayBill(StudentTuition student)
{
    cout << "\n\n\t\tUNIVERSITY OF TROUTDALE" << endl;
    cout << "\t    Billing Statement for Semester" << endl;
    cout << "\n         Tuition      Room & Board      Total";
    cout << "\n          " << student.tuition << "\t\t "
        << student.housing << "\t\t " << student.total;
    cout << endl;
}

int main()
{
    StudentTuition student;

    string residencyPrompt = "Are you an in-state(I) or out-of-state(O) student?";
    string housingPrompt = "Do you need room & board (Y or N)?";

    intro();
    student.setTuition(getStatus(residencyPrompt));
    student.setHousing(getStatus(housingPrompt));
    student.setTotal();
    displayBill(student);

    return 0;
}

