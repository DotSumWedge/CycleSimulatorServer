#pragma once
#include <string>
#include <vector>
#include "Rider.h"

class Team {
public:
    Team(std::string inputName) { name = inputName; };
    std::string name;
    std::vector<Rider*> riders;
private:
};
