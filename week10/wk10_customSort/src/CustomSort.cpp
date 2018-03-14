#include "CustomSort.h"

Custom::Sort::Sort(const int VALUE_MAX) : m_size(VALUE_MAX)
{
    m_initArray = new int[m_size];
    for (unsigned int i = 0; i < m_size; i++)
    {
        m_initArray[i] = -1;
    }
}

Custom::Sort::~Sort()
{
    delete [] m_initArray;
    m_initArray = 0;
}

void Custom::Sort::imprintValues(const int ara[], const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        m_initArray[ara[i]] = ara[i];
    }
    return;
}

void Custom::Sort::getSortedValues(int ara[], const int SIZE)
{
    int i = 0;
    int index = 0;
    while (index < SIZE)
    {
        if (m_initArray[i] != -1)
        {
            ara[index] = m_initArray[i];
            index++;
        }
        i++;
    }
    return;
}

void Custom::sortArray(int ara[], const int VALUE_MAX, const int SIZE)
{
    Custom::Sort customSort(VALUE_MAX);
    customSort.imprintValues(ara, SIZE);
    customSort.getSortedValues(ara, SIZE);
    return;
}
