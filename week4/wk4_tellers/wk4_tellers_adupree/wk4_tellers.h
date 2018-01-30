/******************************************************************************
Teller class creates an object that will hold the number of sick days missed
per year for the last 3 years.

When the teller object is instantiated it must be supplied with 3 integer
arguments that correspond to the number of sick days missed for each year.

Upon construction of the teller object, the integer arguments will be stored in
the correct member variables.
******************************************************************************/

#ifndef TELLER_H
#define TELLER_H

class Teller
{
public:

    Teller(int year1, int year2, int year3);
    // Constructor assigns integer arguments to corresponding member variable

    int getTotalDaysMissed();

private:

    //These member variables hold the number of sick days used each year
    int m_year1,
        m_year2,
        m_year3;

};

#endif // teller_h
