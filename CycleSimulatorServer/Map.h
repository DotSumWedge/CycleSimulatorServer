#pragma once
#include "MapPiece.h"
#include "Rider.h"
#include "Group.h"
#include <vector>

class Map {
public:
    Map(std::vector<MapPiece> inputMapPieces, Group inputGroup);
    std::vector<MapPiece> mapPieces;
    std::vector<Group> groups;

    void printMap();
    void printGroup(unsigned int i, unsigned int j);
private:
};