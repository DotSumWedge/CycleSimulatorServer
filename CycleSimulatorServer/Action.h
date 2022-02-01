#pragma once
#include <string>
/*
    Every dice roll has a chance for an extreme success or extreme failure
*/

class Action {
public:
    Action(std::string inputName);
    std::string name;
private:
};