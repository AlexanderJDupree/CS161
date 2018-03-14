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

void copyAra(const int permAra[], int ara[]);
void bubbleSort(int ara[], int n, int& counter);
// implemented recursively
void selectionSort(int ara[], int n, int& counter);
// implemented recursively
void insertionSort(int ara[], int n, int& counter);
// implemented recursively
void printArray(const int ara[], int counter, std::string araName);

const int SIZE = 100;

int main()
{
    int bubbleCounter = 0;
    int selectionCounter = 0;
    int insertionCounter = 0;

    int permAra[SIZE] = {42, 4, 16, 13, 25, 8, 28, 31, 30, 35, 48, 27, 20, 20,
                         36, 36, 4, 21, 30, 50, 27, 20, 42, 8, 25, 29, 15, 30,
                         49, 18, 15, 14, 13, 15, 37, 26, 45, 44, 10, 43, 31,
                         42, 18, 50, 48, 47, 11, 5, 16, 6, 2, 31, 24, 31, 41,
                         22, 18, 4, 13, 28, 25, 23, 19, 29, 15, 19, 21, 23, 24,
                         41, 5, 16, 44, 46, 19, 39, 38, 10, 47, 28, 15, 12, 35,
                         45, 48, 18, 14, 35, 18, 8, 14, 29, 2, 31, 16, 25, 4,
                         49, 45, 15};
    int ara1[SIZE];
    int ara2[SIZE];
    int ara3[SIZE];

    copyAra(permAra, ara1);
    copyAra(permAra, ara2);
    copyAra(permAra, ara3);

    bubbleSort(ara1, SIZE, bubbleCounter);
    selectionSort(ara2, SIZE, selectionCounter);
    insertionSort(ara3, 1, insertionCounter);

    printArray(permAra, 0, "Original Array");
    printArray(ara1, bubbleCounter, "Bubble Sort");
    printArray(ara2, selectionCounter, "Selection Sort");
    printArray(ara3, insertionCounter, "Insertion Sort");

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


