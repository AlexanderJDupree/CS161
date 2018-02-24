#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "MasterMind.h"

using namespace std;

struct SolutionKey
{
    unsigned int index;
    unsigned int occurences;
};

void intro(); // jake
void displayResults(); // jake
void gameSummary(); // jake
string getInput();
bool isValidInput(string input);

pair<int, int> guessStatus(string guess);


int main()
{
    string userInput = "ygrb";

    guessStatus(userInput);


    return 0;
}


pair<int, int> guessStatus(string guess)
{
    string solution = "rggy";
    pair<int, int> hits;

    map<char, SolutionKey> solutionTable;
    for (unsigned int i = 0; i < sizeof(solution)-1; i++)
    {
        if (solutionTable['r'])
        {
            solutionTable[solution[i]].occurences += 1;
        }
        else
        {
            solutionTable[solution[i]] = SolutionKey(1, 1);
//            solutionTable[solution[i]].index.push_back(i);
//            solutionTable[solution[i]].occurences = 1;
        }
    };


    return hits;

}
