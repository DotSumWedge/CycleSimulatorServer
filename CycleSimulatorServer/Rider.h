#pragma once
#include <tuple>
#include <string>
#include "MapPiece.h"

class Rider {
public:
    Rider(std::string inputName, std::string inputRace, 
        int inputFlat,
        int inputHill,
        int inputMountain,
        int inputDownhill,
        int inputSprint,
        int inputBreakaway,
        int inputCobblestone,
        int inputWind
    );

    // Current location of the rider
    std::tuple<MapPiece*,std::string*> location;
    std::string name;
    std::string race;

    // If a rider reaches 0 energy they drop out of the race
    int energy = 5;

    // return a random number between 1 and 20
    int rollD20();

    // returns result of a skill check
    int rollFlatCheck(int modifier);
    int rollHillCheck(int modifier);
    int rollMountainCheck(int modifier);
    int rollDownhillCheck(int modifier);
    int rollSprintCheck(int modifier);
    int rollBreakawayCheck(int modifier);
    int rollCobblestoneCheck(int modifier);
    int rollWindCheck(int modifier);

    void printLocation();

private:
    // modifiers for skill checks
    int flat, hill, mountain, downhill, sprint, breakaway, cobblestone, wind;
};