#pragma once
#include "Rider.h"
#include <vector>

class Group {
public:
    Group(std::vector<Rider*> inputRiders);
    std::vector<Rider*> riders;
private:
};
