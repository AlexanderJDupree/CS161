/******************************************************************************
* Sort class sorts a random unique positive integer array into ascending order.
* It accomplishes this by initializing an array of size VALUE_MAX to -1. Where
* VALUE_MAX is the highest value of the array to be sorted. It then imprints
* each element of the unsorted array onto the newly initialized array into the
* index that corresponds with its value. I.E. If the unsorted array contains
* an element of value 23, then the larger array's 23rd element will equal 23.
* After each element is imprinted then the sorted array will return the values
* are greater than -1 onto the original array.
*
* Sort class utilizes the custom name space to abstract its functions from the
* User. User only has to call Custom::sortArray() and provide the required
* parameters to have an array sorted.
******************************************************************************/

#ifndef CUSTOMSORT_H
#define CUSTOMSORT_H

namespace Custom
{
    class Sort
    {
    public:
        Sort(const int VALUE_MAX);
        // Constructor allocates memory for an int array of size VALUE_MAX and
        // initializes each element to -1.
        ~Sort();
        // Destructor deletes the dynamic array and points it to 0.

        void imprintValues(const int ara[], const int SIZE);
        // Precondition: Assumes that the highest value of any element in ara
        // is less than VALUE_MAX (m_size).
        // Postcondition: Takes every value in ara and assigns it to the
        // corresponding index in m_initArray. I.E. if the value is 71 then
        // m_initArray[71] will equal 71.

        void getSortedValues(int ara[], const int SIZE);
        // Iterates through m_initArray copies over any value greater than -1
        // to the given array.

    private:
        unsigned int m_size;
        int * m_initArray;
    };

    void sortArray(int ara[], const int VALUE_MAX, const int SIZE);
    // Function to be called by the user in main. Requires an array of unique
    // integers, the size of the array, and the highest value in the array.
    // SortArray will then sort the array using the sort methods in the sort
    // class.


}

#endif // CUSTOMSORT_H
