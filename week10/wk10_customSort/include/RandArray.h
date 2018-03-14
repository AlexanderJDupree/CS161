#ifndef RANDARRAY_H
#define RANDARRAY_H

namespace Random
{
    class RandArray
    {
    public:
        RandArray(const int SIZE);
        // Constructor sets m_size to equal parameter SIZE.

        void fillUnique(int ara[], int _max);
        // fills array with random unique integers from 0 - _max. Utilizes a
        // set to find unique integers then copies the sets values over to the
        // array. Assumes size of ara is the same size of m_size.

        void fillRandom(int ara[], int _max);
        // fills the dynamic array with random integers from 0 - _max.

        void shuffle(int ara[]);
        // shuffles a m_randAra to make it unsorted. Used in conjunction with
        // fillUnique. The nature of using a set to fill an array requires
        // that we shuffle it afterwards.

    private:
        unsigned int m_size;
    };

    void Randomize(int ara[], const int VALUE_MAX, const int SIZE);

}

#endif // RANDARRAY_H
