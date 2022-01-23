#include "Map.h"
#include <iostream>

Map::Map(std::vector<MapPiece> inputMapPieces, Group inputGroup)
{
    mapPieces = inputMapPieces;
    groups.push_back(inputGroup);
}

// groupds not working yet
void Map::printMap() 
{
    std::cout << "Map:" << std::endl;

    std::cout << std::endl;
    
    for (unsigned int i = 0; i < mapPieces.size(); i++)
    {
        for (unsigned int j = 0; j < mapPieces[i].terrain.size(); j++)
        {
            std::cout << mapPieces[i].terrain[j];
            printGroup(i,j);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void Map::printGroup(unsigned int i, unsigned int j) {
// grab the location from any rider
    for (unsigned int k = 0; k < groups.size(); k++) {
        if (std::get<0>(groups[k].riders[0]->location) == &mapPieces[i]
            && std::get<1>(groups[k].riders[0]->location) == &mapPieces[i].terrain[j]
            ) {
            std::cout << " G" << k ;
        }
    }
}