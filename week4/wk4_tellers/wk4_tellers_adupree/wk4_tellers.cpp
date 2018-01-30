/******************************************************************************

cpp file for wk4_tellers.h

******************************************************************************/


#include "wk4_tellers.h"


Teller::Teller(int year1, int year2, int year3)
    : m_year1(year1), m_year2(year2), m_year3(year3) {}

int Teller::getTotalDaysMissed()
{
    return m_year1 + m_year2 + m_year3;
}

