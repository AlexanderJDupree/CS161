/******************************************************************************

******************************************************************************/

#ifndef TRIP_H
#define TRIP_H

struct Adventures
{
    char adventure[];
    int cost;
};


class Trip
{
public:

    Trip();
//
//    Adventures* getAdventures();


private:

    Adventures m_adventures[3];

    char m_name[];
    char m_number[];

    int m_people;


};

#endif // TRIP_H
