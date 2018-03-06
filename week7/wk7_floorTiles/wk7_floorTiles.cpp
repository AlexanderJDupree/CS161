/******************************************************************************

cpp file for floorTiles.h Tiles class

******************************************************************************/

#include <cmath> // std::ceil()
#include "wk7_floorTiles.h"

Tiles::Tiles(float tileSize) : m_tileSize(tileSize), m_totalTiles(0),
                               m_totalBoxes(0) {}

int Tiles::numTilesNeeded(const Room& room)
{
    int numOfTiles = std::ceil(room.area / m_tileSize);
    m_totalTiles += numOfTiles;
    return numOfTiles;
}

int Tiles::calculateLeftover()
{
    int leftover = (m_totalBoxes * m_BOX) - m_totalTiles;
    return leftover;
}

int Tiles::getTotalTiles()
{
    return m_totalTiles;
}

int Tiles::getTotalBoxes()
{
    return m_totalBoxes;

}

void Tiles::setTotalBoxes()
{
    m_totalBoxes = std::ceil(m_totalTiles / static_cast<float>(m_BOX));
    return;
}
