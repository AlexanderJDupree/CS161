/******************************************************************************
* File: wk8_largestRandom_aduree.cpp
* Description: Fills an array with random integers from 0 - 1000, then displays
               the array as well as the largest integer.
* Author: Alexander DuPree
* Date: 2/27/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillRandArray(int randArray[], const int SIZE);
// Uses rand() % 1000 to fill the array with random integers from 0 - 1000
void printArray(const int randArray[], const int SIZE);
void printLargest(const int randArray[], int largestsIndex);
int findLargest(const int randArray[], const int SIZE);


int main()
{
    const int SIZE = 10;
    int randArray[SIZE] = {0};
    int largestsIndex = 0;

    fillRandArray(randArray, SIZE);
    largestsIndex = findLargest(randArray, SIZE);

    printArray(randArray, SIZE);
    printLargest(randArray, largestsIndex);

    return 0;
}

void fillRandArray(int randArray[], const int SIZE)
{
    srand(time(NULL));
    // Seed the random number generation

    for (int i = 0; i < SIZE; i++)
    {
        randArray[i] = rand() % 1000;
    }
    return;
}

void printArray(const int randArray[], const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << randArray[i] << "  ";
    }
    cout << endl;
    return;
}

void printLargest(const int randArray[], int largestsIndex)
{
    cout << "\nLargest value: " << randArray[largestsIndex]
         << ", found at index " << largestsIndex << endl;
    return;
}

int findLargest(const int randArray[], const int SIZE)
{
    int largest = randArray[0];
    int index = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (randArray[i] >= largest)
        {
            index = i;
            largest = randArray[i];
        }
    }
    return index;
}
