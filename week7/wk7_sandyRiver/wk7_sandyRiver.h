/******************************************************************************
Trip object holds the contact information for the user as well as the adventure
choices, costs and selection. Trip class contains setters for the name, number
purchasers and trip selection as well as getters for these private members.

The Adventures object allows us to package the data for the name of the
adventure with the cost of the adventure.
******************************************************************************/

#ifndef TRIP_H
#define TRIP_H

#include <string>

struct Adventures
{
    std::string adventure;
    int cost;
};


class Trip
{
public:

    Trip();
    // Constructor fills adventure array will correct adventure and costs.

    Adventures* getAdventures();
    // Returns adventures array
    std::string getAdventureName();
    // Returns the string of the chosen adventure.
    std::string getName();
    // Returns the string of the name of the purchaser
    std::string getNumber();
    // Returns the number of the name of the purchaser as a string.
    int getAdventureCost();
    // Returns the cost of the chosen adventure.

    int calculateCost();

    void setName(std::string name);
    void setNumber(std::string number);
    void setPurchasers(int purchasers);
    void setTripChoice(int tripChoice);


private:

    Adventures m_adventures[3];

    std::string m_name;
    std::string m_number;

    int m_purchasers;
    int m_tripChoice;
};

#endif // TRIP_H
