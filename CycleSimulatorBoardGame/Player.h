#pragma once
#include <string>
#include <vector>
#include "Team.h"
#include "Action.h"

class Player {
public:
    Player(std::string inputName, Team* inputTeam);
    std::string name;
    Team* team;

    /*
    * 
    * 
    * 
    */
    std::vector<Action> actions;
    bool isReady;

private:
};