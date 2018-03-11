/******************************************************************************
Monkey class main purpose is to store the data for the food eaten for each day
of the week. This data is stored in the int m_foodAte array. Monkey class also
has the additional functionality of keeping track of the total amount eaten in
a week as well as providing the lowest and highest days. Each Monkey object
contains a name variable that can be set by the user.
******************************************************************************/


#ifndef MONKEY_H
#define MONKEY_H

#include <string>

const int DAYS = 7;
// Size is declared globally to represent the days of the week.

class Monkey
{
    public:
        Monkey();
        // Constructor initializes total counter to 0 as well as sets the
        // highest day to 0. We set the lowest day to -1 as a default value so
        // when the first food data value comes in we can check if the default
        // value is still there. If it is, set the incoming food data as the
        // lowest day.

        int getTotal();
        // Returns the running total of food ate
        int getFoodAte(int day);
        // Returns the amount of food ate on a certain day of the week.
        std::pair<int, int> getLowest();
        // Returns the lowest day pair
        std::pair<int, int> getHighest();
        // Returns the highest day pair
        std::string getName();
        // Returns the name of the monkey
        void updateFoodAte(int food, int day);
        // uses the day parameter as the index for the foodAte array and stores
        // the food data into it. Also adds the food ate to the total as well as
        // checks if the food ate is higher or lower than the previous extrema.
        void setName(std::string name);


    protected:

    private:

        int m_foodAte[DAYS];
        int m_total;
        std::pair<int, int> m_lowestDay;
        std::pair<int, int> m_highestDay;
        // Lowest and highest day holds the day for the extrema first, and the
        // value second.

        std::string m_name;

};

#endif // MONKEY_H
