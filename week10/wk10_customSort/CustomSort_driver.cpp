/******************************************************************************
* File: wk10_sortOperations_adupree.cpp
* Description: Generates an array of positive unique random integers and then
               Uses a newly developed "Custom" sort algorithm to sort it.
* Author: Alexander DuPree
* Date: 3/14/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include "RandArray.h"
#include "CustomSort.h"

void printArray(const int ara[], const int SIZE, std::string araName);

int main()
{
    const int SIZE = 50;
    const int VALUE_MAX = 500;

    int ara[SIZE];

    Random::randomize(ara, VALUE_MAX, SIZE);
    printArray(ara, SIZE, "Unsorted Array");

    Custom::sortArray(ara, VALUE_MAX, SIZE);
    printArray(ara, SIZE, "Sorted Array");
    return 0;
}

void printArray(const int ara[], const int SIZE, std::string araName)
{
    std::cout << araName << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << ara[i] << " ";
    }
    std::cout << std::endl;
    return;
}
