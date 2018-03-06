/******************************************************************************
* File: wk7_floorTiles_driver.cpp
* Description: Calculates and displays the number of boxes needed to tile a job.
* Author: Alexander DuPree
* Date: 2/20/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include "wk7_floorTiles.h"

using namespace std;

void intro();
void setRoomDimension(Room& room, int index);
// Uses getInput() to set the length and width of room object

void displayTilesNeeded(int tilesNeeded, int index);
// Uses tiles object to display the tiles needed for the room.

void displaySummary(Tiles& tiles, int numOfRooms);
// Uses getters from Tiles class to display the job summary.

void resetInputStream();
//resets failure state and discards bad characters on any input that failed.

float getInput(string prompt, string errorMessage, int _max, int _min);
// prints prompt, records user input, passes the min/max range and user input
// into isValidInput. Continues to loop until isValidInput returns true.

bool isValidInput(string errorMessage, float userInput, int _max, int _min);
// checks if userInput is out of range bounds, if so calls resetInputStream()
// otherwise, return true.

int main()
{
    float tileSize;
    int numOfRooms;

    intro();
    tileSize = getInput("\nEnter the size of the tile in square inches:  ",
                        "Error: Positive numbers only.", 10000, 0);
    numOfRooms = getInput("\nEnter the number of rooms to be tiled:  ",
                          "Error: Positive numbers only.", 10000, 0);

    Tiles tiles(tileSize); // Instantiate Tile object

    for (int i = 0; i < numOfRooms; i++)
    {
        Room room;
        // Instantiate room object

        setRoomDimension(room, i);
        // room is passed by reference

        int tilesNeeded = tiles.numTilesNeeded(room);
        // room is passed by reference

        displayTilesNeeded(tilesNeeded, i);
        // room and tiles are passed by reference
    }
    tiles.setTotalBoxes();

    displaySummary(tiles, numOfRooms);
    // tiles is passed by reference

    return 0;
}

void intro()
{
    cout << "\t\tTILE CALCULATOR\n\n";
    cout << "This program will estimate the number of boxes of tile needed for"
         << "\na job. You will need to input the size of the tile, the number "
         << "of \nrooms to be tiled and the dimensions of each room." << endl;
    return;
}

void setRoomDimension(Room& room, int index)
{
    cout << "\nEnter dimensions for room " << index + 1 << ':' << endl;
    room.length = getInput("\tLength:  ",
                           "Error: Positive numbers only.", 10000, 0);
    room.width = getInput("\tWidth:  ",
                          "Error: Positive numbers only.", 10000, 0);
    room.area = room.length * room.width;
    return;
}

void displayTilesNeeded(int tilesNeeded, int index)
{
    cout << "Room " << index + 1 << " requires " << tilesNeeded << " tiles.";
    cout << endl;
    return;
}

void displaySummary(Tiles& tiles, int numOfRooms)
{
    cout << "\n\t\tJOB SUMMARY\n" << endl;
    cout << "ROOMS\tTOTAL TILES\tTOTAL BOXES\tLEFTOVER" << endl;
    cout << setw(4) << right << numOfRooms << setw(11) << right
         << tiles.getTotalTiles() << setw(15) << right << tiles.getTotalBoxes()
         << setw(14) << right << tiles.calculateLeftover() << endl;
    return;
}

void resetInputStream()
{
    // get rid of failure state
    cin.clear();

    // discard 'bad' characters
    cin.ignore(100, '\n');
    return;
}

float getInput(string prompt, string errorMessage, int _max, int _min)
{
    float userInput;

    do {
        cout << prompt;
        cin >> userInput;
    } while (!isValidInput(errorMessage, userInput, _max, _min));

    return userInput;
}

bool isValidInput(string errorMessage, float userInput, int _max, int _min)
{
    if (userInput > _max || userInput <= _min)
    {
        cout << errorMessage << endl;
        resetInputStream();
        return false;
    }
    else
    {
        return true;
    }
}

