#include "rider.h"
#include <random>
#include <iostream>

Rider::Rider(std::string inputName, std::string inputRace,
    int inputFlat,
    int inputHill,
    int inputMountain,
    int inputDownhill,
    int inputSprint,
    int inputBreakaway,
    int inputCobblestone,
    int inputWind
) {
    name = inputName;
    race = inputRace;
    flat = inputFlat;
    hill = inputHill;
    mountain = inputMountain;
    downhill = inputDownhill;
    sprint = inputSprint;
    breakaway = inputBreakaway;
    cobblestone = inputCobblestone;
    wind = inputWind;
}

int Rider::rollD20() {
    std::random_device rand;
    std::mt19937 gen(rand());

    return gen() % 20 + 1;
}

int Rider::rollFlatCheck(int modifier) {
    return rollD20() + flat + modifier;
}

int Rider::rollHillCheck(int modifier) {
    return rollD20() + hill + modifier;
}

int Rider::rollMountainCheck(int modifier) {
    return rollD20() + mountain + modifier;
}

int Rider::rollDownhillCheck(int modifier) {
    return rollD20() + downhill + modifier;
}

int Rider::rollSprintCheck(int modifier) {
    return rollD20() + sprint + modifier;
}

int Rider::rollBreakawayCheck(int modifier) {
    return rollD20() + breakaway + modifier;
}

int Rider::rollCobblestoneCheck(int modifier) {
    return rollD20() + cobblestone + modifier;
}

int Rider::rollWindCheck(int modifier) {
    return rollD20() + wind + modifier;
}

void Rider::printLocation() {
    //std::cout << name << "'s location : " << location<0> << ", " << &location<0> << std::endl;
}