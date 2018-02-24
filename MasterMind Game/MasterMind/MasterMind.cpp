
#include "MasterMind.h"

Game::Game()
{
    m_solution = "rggb"; // TODO create function to generate solution
    m_attempts = 0;
    m_isGameWon = false;
    m_solutionTable = createSolutionTable(m_solution);
}

std::map<char, bool> Game::createSolutionTable(std::string solution)
{
    std::map<char, bool> solutionTable;
    for (unsigned int i = 0; i < solution.length(); i++)
    {
        solutionTable[solution[i]] = true;
    };
    return solutionTable;
}

HitSummary Game::guessStatus(std::string guess)
{
    HitSummary results = {0, 0}; // instantiate HitSummary object

    for (unsigned int i = 0; i < m_solution.length(); i++)
    {
        if (guess[i] == m_solution[i])
        {
            results.hits += 1;
        }
        else
        {
            if (m_solutionTable[guess[i]])
            {
                results.nearHits += 1;
            }
        }
    }
    return results;
}
