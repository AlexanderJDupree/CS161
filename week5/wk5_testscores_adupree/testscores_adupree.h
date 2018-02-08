/******************************************************************************
Student object holds the number of tests the student was required to take and a
running total of test scores. The public methods allow the user to add a test
score to the running total as  well as calculate and return the average test
score for the student.
******************************************************************************/

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:

    Student(int numOfTests); // constructor

    float calculateAverage();
    // Calculates and returns the average test score

    void addTestScore(float testScore);
    // adds testScore to the running total in m_sumOfTests;

private:

    int m_numOfTests;
    float m_sumOfTests;

};

#endif // student_h
