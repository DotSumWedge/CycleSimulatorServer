#include "MapPiece.h"

MapPiece::MapPiece(
    std::vector<std::string> inputTerrain,
    std::vector<std::string> inputCondition,
    std::vector<std::string> inputSpecialEvents
) {
    terrain = inputTerrain;
    condition  = inputCondition;
    specialEvents = inputSpecialEvents;
}