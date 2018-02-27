/******************************************************************************
sandyRiver.cpp contains the implementation of the class methods prototyped in
the sandyRiver.h file.
******************************************************************************/
#include "wk7_sandyRiver.h"

Trip::Trip()
{
    m_adventures[0] = (Adventures){.adventure = "Shark Feeding in the Sandy River",
                                   .cost = 75};
    m_adventures[1] = (Adventures){.adventure = "Treasure Hunting in the Sandy River",
                                   .cost = 100};
    m_adventures[2] = (Adventures){.adventure = "Midnight Dive with the Salamanders",
                                   .cost = 150};
}

Adventures* Trip::getAdventures()
{
    return m_adventures;
}

std::string Trip::getAdventureName()
{
    return m_adventures[m_tripChoice].adventure;
}

std::string Trip::getName()
{
    return m_name;
}

std::string Trip::getNumber()
{
    return m_number;
}

int Trip::getAdventureCost()
{
    return m_adventures[m_tripChoice].cost;
}

int Trip::calculateCost()
{
    int cost;
    cost = m_adventures[m_tripChoice].cost * m_purchasers;
    return cost;
}

void Trip::setName(std::string name)
{
    m_name = name;
    return;
}

void Trip::setNumber(std::string number)
{
    m_number = number;
    return;
}

void Trip::setPurchasers(int purchasers)
{
    m_purchasers = purchasers;
    return;
}

void Trip::setTripChoice(int tripChoice)
{
    m_tripChoice = tripChoice - 1;
    return;
}


