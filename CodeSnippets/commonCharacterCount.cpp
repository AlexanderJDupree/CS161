#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

int commonCharacterCount(std::string s1, std::string s2) {
    int returnInt = 0;

    std::map<char, int> LetterSeen;

    for (char Letter : s1) LetterSeen[Letter] += 1;

    for (char Letter : s2)
    {
        if (LetterSeen[Letter])
        {
            returnInt++;
            LetterSeen[Letter] -= 1;
        }
    }
    return returnInt;
}



int main() {
    std::string s1 = "aabcc";
    std::string s2 = "adcaa";
    commonCharacterCount(s1, s2);
    return 0;
}


