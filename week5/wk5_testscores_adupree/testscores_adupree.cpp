/******************************************************************************

cpp file for testscores.h Student class

******************************************************************************/

#include "testscores_adupree.h"

Student::Student(int numOfTests)
{
    m_numOfTests = numOfTests;
    m_sumOfTests = 0;
}

float Student::calculateAverage()
{
    return m_sumOfTests / m_numOfTests;
}

void Student::addTestScore(float testScore)
{
    m_sumOfTests += testScore;
    return;
}
