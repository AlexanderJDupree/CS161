/******************************************************************************
* File: labPractice_adupree.cpp
* Description: Pass by Reference lab and debugging practice
* Author: Alexander DuPree
* Date: 2/20/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/
// labPractice.cpp

#include <iostream>
using namespace std;

void intro();
void getValues(int& value1, int& value2);
// gets values for length and width, stores them into referenced variables.
void displayValues(int& lotLength, int& lotWidth, int& structLength, int& structWidth, int& yardArea);
// displays all values in structured format.
int computeArea(int& lotLength, int& lotWidth, int& structLength, int& structWidth);
// computes area of lot, then area of structure. returns the (area of lot - area of structure).
// Lot area must be larger than the structure area otherwise computeArea will return a negative value.

int main()
{
	int lot_length, lot_width,
		structure_length, structure_width,
		yard_area;

	intro();

	cout << "Enter the length and width of the lot.";
	getValues(lot_length, lot_width);
	cout << "Enter the length and width of the structure.";
	getValues(structure_length, structure_width);

	yard_area = computeArea(lot_length, lot_width, structure_length, structure_width);
	displayValues(lot_length, lot_width, structure_length, structure_width, yard_area);

	return 0;
}

void intro()
{
	cout << "\t\tYARD SPACE\n\n";
	cout << "This program will compute the square footage\n"
	 	 << "of the yard space for a property.\n\n";
	cout << "You will be asked to enter the dimensions of the lot\n"
		 << "and the dimensions of the structure (house or other\n"
		 << "building).\n\n";
	cout << "The program will output how many square feet of the\n"
		 <<	"lot is available for gardening or for a lawn.\n\n";
}

void getValues(int& value1, int& value2)
{
    cout << "\nLength:  ";
    cin >> value1;
    cout << "\nWidth:  ";
    cin >> value2;
    return;
}

int computeArea(int& lotLength, int& lotWidth, int& structLength, int& structWidth)
{
    int lotArea = lotLength * lotWidth;
    int structArea = structLength * structWidth;
    int yardArea = lotArea - structArea;
    return yardArea;
}

void displayValues(int& lotLength, int& lotWidth, int& structLength, int& structWidth, int& yardArea)
{
    cout << "\nLot:\t\t" << lotLength << "    " << lotWidth << "    (measured in feet)" << endl;
    cout << "structure:\t" << structLength << "    " << structWidth << "    (measured in feet)" << endl;
    cout << "yard should end up being " << yardArea << " square feet." << endl;
    return;

}
