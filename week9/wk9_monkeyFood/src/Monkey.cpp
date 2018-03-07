#include "Monkey.h"

Monkey::Monkey() : m_total(0)
{
    m_lowestDay = std::make_pair(0, -1);
    m_highestDay = std::make_pair(0, 0);
}

int Monkey::getTotal()
{
    return m_total;
}

int Monkey::getFoodAte(int day)
{
    return m_foodAte[day];
}

std::pair<int, int> Monkey::getLowest()
{
    return m_lowestDay;
}

std::pair<int, int> Monkey::getHighest()
{
    return m_highestDay;
}

std::string Monkey::getName()
{
    return m_name;
}

void Monkey::updateFoodAte(int food, int day)
{
    m_foodAte[day] = food;
    m_total += food;
    if (food <= m_lowestDay.second || m_lowestDay.second == -1)
    {
        m_lowestDay.first = day + 1;
        m_lowestDay.second = food;
    }
    else if (food >= m_highestDay.second)
    {
        m_highestDay.first = day + 1;
        m_highestDay.second = food;
    }
    return;
}

void Monkey::setName(std::string name)
{
    m_name = name;
    return;
}
