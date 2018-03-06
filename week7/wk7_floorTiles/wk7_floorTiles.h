/******************************************************************************
Tiles class stores the values for the total number of tiles required to tile a
job as well as the number of boxes needed. Tiles can also calculate the tiles
needed per room when given a Room object.

Room is a public structure class that holds the dimensions and area of any
rectangular shaped room.
******************************************************************************/

#ifndef TILES_H
#define TILES_H

struct Room
{
    float length;
    float width;
    float area;
};

class Tiles
{
public:

    Tiles(float tileSize);
    // Precondition: tileSize is greater than 0
    // Postcondition: Constructor sets m_tileSize to value of tileSize.
    // initializes m_totalTiles and m_totalBoxes to 0.

    int numTilesNeeded(const Room& room);
    // Precondition: Room object with positive values for length and width
    // Postcondition: returns the number of tiles needed to tile the room
    // rounded up to the nearest integer as well as update the m_totalTiles
    // variable with the calculated value.

    int calculateLeftover();
    // Precondition: totalTiles and totalBoxes have been assigned values.
    // Postcondition: returns the number of leftover tiles.

    int getTotalTiles();
    // Returns m_totalTiles

    int getTotalBoxes();
    // Returns m_totalBoxes

    void setTotalBoxes();
    // Precondition: constant m_BOX cannot be 0.
    // Postcondition: Sets the m_totalBoxes value to total tiles needed
    // divided by number tiles in a box rounded up.

private:

    static const int m_BOX = 20;
    // There are 20 tiles per box.

    float m_tileSize;
    // The size of each tile in square inches.

    int m_totalTiles;
    // The total number of tiles needed for the job.

    int m_totalBoxes;
    // The total number of boxes needed for the job.

};

#endif // tiles_h
