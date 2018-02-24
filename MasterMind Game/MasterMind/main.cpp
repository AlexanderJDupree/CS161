#include <iostream>
#include "MasterMind.h"

using namespace std;

void intro(); // jake
void displayResults(); // jake
void gameSummary(); // jake
string getInput();
bool isValidInput(string input);

pair<int, int> guessStatus(string guess);


int main()
{
    string userInput = "rgbg";
    Game game;
    HitSummary TEMP;

    TEMP = game.guessStatus(userInput);

    cout << TEMP.hits << endl;
    cout << TEMP.nearHits << endl;

    return 0;
}
