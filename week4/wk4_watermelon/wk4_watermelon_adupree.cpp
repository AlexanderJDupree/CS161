/******************************************************************************
* File: wk4_beverages_adupree.cpp
* Description: Calculate and display the distance fallen per second of a
               watermelon dropped off a bridge.
* Author: Alexander DuPree
* Date: 1/30/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications: This program will look slightly different than the flowchart
                 I submitted. This is because the program description only
                 mentioned to calculate the distance fallen. It did not
                 explicitly say to display the distance fallen each second,
                 therefore I omitted it from my flowchart. After seeing the
                 sample runs it was made clear that displaying the distance
                 fallen was implied and should have been included in the
                 flowchart.

                 The formula "distance = 0.5 * gravity * time" was not giving
                 values that match the sample runs in the description. I
                 modified the formula to match the sample run values by
                 changing it to "distance = 0.5 * gravity * (time * time)".
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void intro();
void displayResults(vector<float> distanceFellPerSecond,
                    float timeFallen);
void calculateDistanceFell(vector<float> &distanceFellPerSecond,
                        const float GRAVITY, float bridgeHeight, float timeFallen);
// continues to create a pair of float values and appends them to
// distanceFellPerSecond vector until we have data for each second fell.

float getInput(string prompt, string errorMessage, int _min);
// Prints prompt to user, grabs input from user, attempts to return integer
// after checking the input was above minimum integer

bool isValidNum(string errorMessage, int userInput, int _min);
// returns true if user input is above minimum integer. Otherwise,
// prints an error message, flushes input stream and returns false.

int main()
{
    const float GRAVITY = 9.8;
    float bridgeHeight,
          timeFallen;

    // vector holds the distance fallen and the index will be used as the time
    // in seconds the watermelon has fallen.
    vector<float> distanceFellPerSecond;

    intro();

    bridgeHeight = getInput("What is the height of the bridge, in meters?  ",
                            "Invalid height, Must be greater than 0.",
                            0);
    timeFallen = getInput("How long did the watermelon drop, in seconds?  ",
                          "Invalid seconds, Must be greater than 0.",
                          0);

    calculateDistanceFell(distanceFellPerSecond, GRAVITY, bridgeHeight,
                          timeFallen);

    displayResults(distanceFellPerSecond, timeFallen);


    return 0;
}

void intro()
{
    cout << "\t\tWATERMLEON DROP\n" << endl;
}

void displayResults(vector<float> distanceFellPerSecond,
                    float timeFallen)
{
    cout << "\nTime Falling (seconds)  Distance Fallen (meters)" << endl;
    cout << "**********************  ************************" << endl;
    for(int i = 0; i < distanceFellPerSecond.size(); i++)
    {
        cout << setw(13) << right << i << setw(24) << right
             << fixed << setprecision(2) << distanceFellPerSecond[i] << endl;
    }
    // If there is missing data for each second than we assume the bridge was
    // not high enough to support values for each second of the drop.
    if (distanceFellPerSecond.size() < timeFallen)
    {
        cout << "Time error. Bridge is not that high." << endl;
    }
}

void calculateDistanceFell(vector<float> &distanceFellPerSecond,
                        const float GRAVITY, float bridgeHeight, float timeFallen)
{
    int time = 0;
    float distance = 0;

    while (time <= timeFallen)
    {
        distance = 0.5 * GRAVITY * (time * time);
        // Only append possible data values, I.E. values less than bridge height.
        if (distance <= bridgeHeight)
        {
            distanceFellPerSecond.push_back(distance);
        }
        time++;
    }
    return;

}


float getInput(string prompt, string errorMessage, int _min)
{
    float userInput = 0;

    do {
    cout << prompt;
    cin >> userInput;
    } while(!isValidNum(errorMessage, userInput, _min));

    return userInput;
}

bool isValidNum(string errorMessage, int userInput, int _min)
{
    if (userInput > _min)
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
