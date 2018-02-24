/******************************************************************************



******************************************************************************/
#ifndef GAME_H
#define GAME_H

#include <string>
#include <map>

struct HitSummary
{
    unsigned int hits;
    unsigned int nearHits;
};

class Game
{
public:

    Game(); // constructor

    HitSummary guessStatus(std::string guess);

    std::map<char, bool> createSolutionTable(std::string solution);

    //getters

    //setters
      // increment m_attempts;

private:

    static const int m_maxTries = 5;

    unsigned int m_attempts;

    std::string m_solution;

    std::map<char, bool> m_solutionTable;

    bool m_isGameWon;

};


#endif // GAME_H
