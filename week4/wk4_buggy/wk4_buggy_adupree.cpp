/******************************************************************************
* File:         wk4_buggy_adupree.cpp
* Description: Displays the number of positive integers
*              and the number of negative integers entered by the user
*
*author: Alexander DuPree
*date: 1/30/2018
*compiler: GNU GCC 5.4.0
*modifications: line 21 added using namespace std;
                line 31 changed Number to number
                line 33 changed not to != operator
                line 36 & 38 changed =+ to ++
                line 40 changed quotes from single to double quotes
                line 43 added missing curly brace
                line 470 & 48 changed variables in both cout statements
                line 51 // added return 0; statement
******************************************************************************/

#include <iostream>

using namespace std; // Missing std:: on all cout and endl functions, added
                    // using namespace std;

int main()
{
	int number;
	int positive = 0;
	int negative = 0;

	cout << "Enter a positive or negative integer (enter 0 to end): ";
	cin >> number; // changed Number to number.

	while (number != 0) // changed not to != operator
	{
		if (number > 0)
			positive++; // changed =+ to ++
		else
			negative++; // changed =+ to ++

        // changed quotes from single to double quotes.
		cout << "Enter another positive or negative integer (enter 0 to end): ";
		cin >> number;
	} // added missing curly brace

	cout << endl;
	// switched variables in both cout statements to reflect correct variables
	cout << "Total positive integers: " << positive << endl;
	cout << "Total negative integers: " << negative << endl;
	cout << endl;

	return 0; // added return 0;
}
