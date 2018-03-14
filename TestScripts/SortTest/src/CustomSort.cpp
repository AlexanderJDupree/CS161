#include "CustomSort.h"

Custom::Sort::Sort(const int VALUE_MAX, int& counter) : m_size(VALUE_MAX)
{
    counter++;

    m_initArray = new int[m_size];
    for (unsigned int i = 0; i < m_size; i++)
    {
        counter++;
        m_initArray[i] = -1;
        counter += 2;
    }
}

Custom::Sort::~Sort()
{
    delete [] m_initArray;
    m_initArray = 0;
}

void Custom::Sort::imprintValues(const int ara[], const int SIZE, int& counter)
{
    for (int i = 0; i < SIZE; i++)
    {
        counter++;
        m_initArray[ara[i]] = ara[i];
        counter += 2;
    }
    return;
}

void Custom::Sort::getSortedValues(int ara[], const int SIZE, int& counter)
{
    counter++;
    int i = 0;
    counter++;
    int index = 0;
    while (index < SIZE)
    {
        counter++;
        if (m_initArray[i] != -1)
        {
            counter++;
            ara[index] = m_initArray[i];
            counter++;
            index++;
        }
        counter++;
        i++;
        counter++;
    }
    return;
}

void Custom::sortArray(int ara[], const int VALUE_MAX, const int SIZE, int& counter)
{
    Custom::Sort customSort(VALUE_MAX, counter);
    customSort.imprintValues(ara, SIZE, counter);
    customSort.getSortedValues(ara, SIZE, counter);
    return;
}
