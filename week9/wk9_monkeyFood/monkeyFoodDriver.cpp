#include <iostream>
#include <iomanip>
#include "Monkey.h"

using namespace std;

void intro();
void getNames(Monkey monkeys[], const int SIZE);
void getFoodData(Monkey monkeys[], const int SIZE);
void displayData(Monkey monkeys[], const int SIZE);
void displayExtrema(Monkey monkeys[], int least, int most);
string createPrompt(int index);
// For use in getInput(), creates the prompt with the correct day of the week.6
int findLeast(Monkey monkeys[], const int SIZE);
// Finds the index for the monkey who ate the least, returns index.
int findMost(Monkey monkeys[], const int SIZE);
// Finds the index for the monkey who ate the most, returns index.

void getInput(string &name);
int getInput(string prompt, string errorMessage, int _min);

bool isValidNum(string errorMessage, int userInput, int _min);

int main()
{
    const int SIZE = 3;
    int least;
    int most;

    intro();

    Monkey monkeys[SIZE];
    // I know the assignment specifically asks for use of a 3 x 7 2d array,
    // but each object contains a int[7] array so in essence this monkeys
    // class array is a 2d array. However, because they are class objects I can
    // implement great functionality like being able to keep track of the total
    // food ate and the low/high days.

    getNames(monkeys, SIZE);
    // Since I had the monkeys as class objects, I thought why not name the
    // monkeys for extra challenge.
    getFoodData(monkeys, SIZE);

    least = findLeast(monkeys, SIZE);
    most = findMost(monkeys, SIZE);

    displayData(monkeys, SIZE);
    displayExtrema(monkeys, least, most);

    return 0;
}

void intro()
{
    cout << "\t\tCORBETT ZOO\n\t\tMONKEY FOOD\n" << endl;
    cout << "You will need to enter three sets of 7 integers, one set for each"
         << " monkey.";
    return;
}

void getNames(Monkey monkeys[], const int SIZE)
{   string name;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nEnter the name for monkey #" << i + 1 << ":  " << endl;
        getInput(name);
        // name is passed by reference

        monkeys[i].setName(name);
    }
    return;
}

void getFoodData(Monkey monkeys[], const int SIZE)
{
    int food;

    for(int i = 0; i < SIZE; i++)
    {
        cout << "\nEnter data for " << monkeys[i].getName() << endl;
        for (int j = 0; j < DAYS; j++)
        {
            food = getInput(createPrompt(j), "Positive numbers only.", 0);
            monkeys[i].updateFoodAte(food, j);
        }
    }
    return;
}

void displayData(Monkey monkeys[], const int SIZE)
{
    int foodPerDay[DAYS] = {0};
    // Declare int array to keep track of food eaten per day by all monkeys.
    int total = 0;

    cout << "\n\t\tM\tT\tW\tTr\tF\tS\tSu\tTOTAL" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(16) << left << monkeys[i].getName();
        for (int j = 0; j < DAYS; j++)
        {
            int food = monkeys[i].getFoodAte(j);
            cout << setw(8) << left << food;
            foodPerDay[j] += food;
            total += food;
        }
        cout << setw(8) << left << monkeys[i].getTotal() << endl;
    }
    cout << setw(16) << left << "TOTALS";
    for (int i = 0; i < DAYS; i++)
    {
        cout << setw(8) << left << foodPerDay[i];
    }
    cout << setw(8) << left << total;
    return;
}

void displayExtrema(Monkey monkeys[], int least, int most)
{
    std::pair<int, int> lowestDay = monkeys[least].getLowest();
    std::pair<int, int> highestDay = monkeys[most].getHighest();

    cout << "\n\nLeast eaten. . ." << endl;
    cout << monkeys[least].getName() << " on day " << lowestDay.first << " ate "
         << lowestDay.second << endl;
    cout << "\nMost eaten. . . " << endl;
    cout << monkeys[most].getName() << " on day " << highestDay.first << " ate "
         << highestDay.second << endl;
    return;
}

string createPrompt(int index)
{
    char day = index + 49;
    // index + 48 calculates the ASCII value where '1' begins.
    string prompt = "Day " + string(1, day) + ":  ";
    return prompt;
}

int findLeast(Monkey monkeys[], const int SIZE)
{
    int least = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (monkeys[i].getLowest().second <= monkeys[least].getLowest().second)
        {
            least = i;
        }
    }
    return least;
}

int findMost(Monkey monkeys[], const int SIZE)
{
    int most = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (monkeys[i].getHighest().second >= monkeys[most].getHighest().second)
        {
            most = i;
        }
    }
    return most;
}

void getInput(string &name)
{
    cin >> name;
    return;
}

int getInput(string prompt, string errorMessage, int _min)
{
    int userInput = -1;
    // initialized to -1 because any number less than 0 is an invalid input.

    do {
        cout << prompt;
        cin >> userInput;
    } while (!isValidNum(errorMessage, userInput, _min));
    return userInput;
}

bool isValidNum(string errorMessage, int userInput, int _min)
{
    if (userInput >= _min && cin)
    {
        return true;
    }
    else
    {
        cout << errorMessage << endl;

        // get rid of failure state
        cin.clear();

        // discard 'bad' characters
        cin.ignore(100, '\n');

        return false;
    }
}
