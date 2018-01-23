/*********************************************************************
* File: wk3_catering_adupree.cpp                                     *
* Description:                                                       *
* Author: Alexander DuPree                                           *
* Date: 1/16/2018                                                    *
* Compiler: GNU CC Compiler                                          *
* Modifications:                                                     *
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>

#define LOG(x) = std::cout << x << std::endl

using namespace std;

class SaintsCatering
{

public:
    SaintsCatering();

    pair<string, float> menu[];

};


SaintsCatering::SaintsCatering()
{
    menu[0] = make_pair("Hot Dogs", 1.25);
}

int main()
{
    // pair<string, float> menu[] = {make_pair("Hot Dogs", 1.25), make_pair("Hamburgers", 2.50)};
    SaintsCatering cateringOptions;

    return 0;
}

