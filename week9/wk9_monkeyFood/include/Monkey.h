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
        // when the first food data value comes in we can check if the value is
        // -1, if it is then we set the lowest day to the incoming food data.

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
        // the food data into it.
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
