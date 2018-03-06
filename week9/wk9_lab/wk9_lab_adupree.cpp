/******************************************************************************
* File: wk9_lab_adupree.cpp
* Description: Fills 2 arrays with random integers from 0 - 9, fills a third
               array with the products of the first two then displays results.
* Author: Alexander DuPree
* Date: 3/6/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

void fillRandArray(int index, int randArray[], const int SIZE);
// Uses rand() % 10 to fill the array with random integers from 0 - 1000
void genProduct(int products[], const int ara1[], const int ara2[], const int SIZE);
void printArray(const int ara[], const int SIZE, string header);

int main()
{
    srand(time(NULL));
    const int SIZE = 10;
    int randArray1[SIZE] = {0};
    int randArray2[SIZE] = {0};
    int productArray[SIZE] = {0};

    fillRandArray(1, randArray1, SIZE);
    fillRandArray(2, randArray2, SIZE);

    genProduct(productArray, randArray1, randArray2, SIZE);

    printArray(randArray1, SIZE, "\nara1:");
    printArray(randArray2, SIZE, "\nara2:");
    printArray(productArray, SIZE, "\nproducts:");

    return 0;
}

void fillRandArray(int index, int randArray[], const int SIZE)
{
    // Seed the random number generation
    cout << "Filling ara" << index << ". . ." << endl;
    for (int i = 0; i < SIZE; i++)
    {
        randArray[i] = rand() % 10;
    }
    return;
}

void genProduct(int products[], const int ara1[], const int ara2[], const int SIZE)
{
    cout << "Computing the products. . . " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        products[i] = ara1[i] * ara2[i];
    }
    return;
}

void printArray(const int ara[], const int SIZE, string header)
{
    cout << header << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << ara[i] << '\t';
    }
    return;
}
