#include "Player.h"

Player::Player(std::string inputName, Team* inputTeam)
{
    name = inputName;
    team = inputTeam;
    isReady = false;
}