/******************************************************************************
* File: wk10_sortOperations_adupree.cpp
* Description: Performs three different types of array sorting, and displays
               number of operations conducted.
* Author: Alexander DuPree
* Date: 3/13/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include "RandArray.h"
#include "CustomSort.h"

void copyAra(const int permAra[], int ara[]);
void bubbleSort(int ara[], int n, int& counter);
// implemented recursively
void selectionSort(int ara[], int n, int& counter);
// implemented recursively
void insertionSort(int ara[], int n, int& counter);
// implemented recursively
void printArray(const int ara[], int counter, std::string araName);
void printResults(int counter, std::string sortMethod);

const int SIZE = 100;
const int VALUE_MAX = 200;

int main()
{
    int bubbleCounter = 0;
    int selectionCounter = 0;
    int insertionCounter = 0;
    int customSort = 0;

    int permAra[SIZE];
    int ara1[SIZE];
    int ara2[SIZE];
    int ara3[SIZE];
    int ara4[SIZE];

    Random::Randomize(permAra, VALUE_MAX, SIZE);

    copyAra(permAra, ara1);
    copyAra(permAra, ara2);
    copyAra(permAra, ara3);
    copyAra(permAra, ara4);

    bubbleSort(ara1, SIZE, bubbleCounter);
    selectionSort(ara2, SIZE, selectionCounter);
    insertionSort(ara3, 1, insertionCounter);
    Custom::sortArray(ara4, VALUE_MAX, SIZE, customSort);

    printResults(bubbleCounter, "Bubble Sort");
    printResults(selectionCounter, "Selection Sort");
    printResults(insertionCounter, "Insertion Sort");
    printResults(customSort, "Custom Sort");

    return 0;
}

void copyAra(const int permAra[], int ara[])
{
    for (int i = 0; i < SIZE; i++)
    {
        ara[i] = permAra[i];
    }
    return;
}


void bubbleSort(int ara[], int n, int& counter)
{
    bool isSwap = false;

    // Base case
    counter++;
    if (n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        counter++;
        if (ara[i] > ara[i+1])
        {
            std::swap(ara[i], ara[i+1]);
            isSwap = true;
            counter += 4;
        }
        counter += 2;
    }
    counter++;
    if (isSwap) { bubbleSort(ara, n - 1, counter); }
    else { return; }
}

void selectionSort(int ara[], int n, int& counter)
{
    // Base case
    counter++;
    if (n == 0)
    {
        return;
    }
    counter++;
    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        counter++;
        if (ara[i] > ara[largest])
        {
            counter++;
            largest = i;
        }
        counter += 2;
    }
    std::swap(ara[largest], ara[n-1]);
    counter += 3;
    selectionSort(ara, n - 1, counter);
}

void insertionSort(int ara[], int n, int& counter)
{
    // base case
    counter++;
    if (n >= SIZE ) { return; }

    counter++;
    int i = n;
    for(i; i > 0; i--)
    {
        counter++;
        if (ara[n] > ara[i-1]) { break; }
        counter += 2;
    }

    // Shift every element larger than ara[n] over one position.
    for (int j = n; j > i; j--)
    {
        counter += 3;
        std::swap(ara[j-1], ara[j]);
        counter += 2;
    }
    insertionSort(ara, n + 1, counter);
}

void printArray(const int ara[], int counter, std::string araName)
{
    std::cout << araName << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << ara[i] << " ";
    }
    std::cout << "\nOperations: " << counter << '\n' << std::endl;
    return;
}

void printResults(int counter, std::string sortMethod)
{
    std::cout << sortMethod  << " operations:  " << counter << std::endl;
    return;
}


