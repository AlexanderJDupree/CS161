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

        void imprintValues(const int ara[], const int SIZE);
        // Precondition: Assumes that the highest value of any element in ara
        // is less than VALUE_MAX (m_size).
        // Postcondition: Takes every value in ara and assigns it to the
        // corresponding index in m_initArray. I.E. if the value is 71 then
        // m_initArray[71] will equal 71.

        void getSortedValues(int ara[], const int SIZE);

    private:
        unsigned int m_size;
        int * m_initArray;
    };

    void sortArray(int ara[], const int VALUE_MAX, const int SIZE);


}

#endif // CUSTOMSORT_H
