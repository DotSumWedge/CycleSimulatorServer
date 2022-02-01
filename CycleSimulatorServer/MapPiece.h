#pragma once
#include <string>
#include <vector>

class MapPiece {
public:

    MapPiece(std::vector<std::string> inputTerrain, 
            std::vector<std::string> inputCondition,
            std::vector<std::string> inputSpecialEvents
    );

    /*
        Terrain Types:

    1. Flat
    2. Hill
    3. Mountain
    4. Downhill

        Condition Types:
    1. Wind
    2. Cobblestone
    3. Rain
    4. Thunderstorm
    5. Soapy

        Special Events:
    1. Unexpected condition change immediate - randomly add one condition to this tile, riders who discover the event are effected on the turn.
    2. Unexpected condition change delayed

    */

    // There are usually 3 pieces of terrain per MapPiece
    // but this is subject to change. Same with condition and specail events
    std::vector<std::string> terrain;
    // There are usually between 0 and 3 conditions
    std::vector<std::string> condition;
    // There are usually between 0 and 1 special events
    std::vector<std::string> specialEvents;



private:

};
