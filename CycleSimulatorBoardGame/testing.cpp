
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cstdlib>
#include "Rider.h"
#include "Team.h"
#include "Map.h"
#include "Player.h"

// usually only 2 riders can make it into a break away
// but if 2 riders follow the 2 riders that make it into
// the break away that allows up to 4 riders but is less likely.
// 
// elfs and dwarfs don't work well together and ork don't work well with anyone
// chaos will work well with the dark elves when they are released
//
// Cobble/wind break apart large groups of riders
//

std::vector<Rider> initializeRiders();

std::vector<Team> initializeTeams(std::vector<Rider> &riders);
Team initializeDwarfs(std::vector<Rider> &riders);
Team initializeElves(std::vector<Rider> &riders);
Team initializeHumans(std::vector<Rider> &riders);
Team initializeOrks(std::vector<Rider> &riders);

Map initializeMap(std::vector<Rider> &riders);
Group initializeStartingGroup(std::vector<Rider> &riders);
void initializeRidersToStartingLine(std::vector<Rider> &riders, Map &map);
void initializeActions();

bool getAllPlayerInputs(std::vector<Player> &players);
void resolveActions();

int main() {

    //Initialize the pieces
    std::vector<Rider> riders = initializeRiders();
    std::vector<Team> teams = initializeTeams(riders);

    Player TinkleDorf("TinkleDorf", &teams[0]);
    Player AI("AI", &teams[0]);
    std::vector<Player> players;
    players.push_back(TinkleDorf);
    players.push_back(AI);
    
    Map map = initializeMap(riders);
    initializeRidersToStartingLine(riders, map);
    initializeActions();

    map.printMap();

    unsigned int turnCounter = 0;

    while (true) {
        while (true) {
            if (getAllPlayerInputs(players)) {
                break;
            }
            std::cout.flush();
            Sleep(6000);
        }
        resolveActions();
        turnCounter++;
    }

    std::cout << "turnCounter: " << turnCounter << std::endl;

    //for (int i = 0; i < 50; i++) {
    //    std::cout << "Sprimli's sprint skill check : " << riders[0].rollSprintCheck(0) << std::endl;
    //}
    //std::cout << "hello world" << std::endl;
}

std::vector<Rider> initializeRiders() {

    std::cout << "Initializing riders..." << std::endl;

    std::vector<Rider> riders;

    Rider sprimli("Sprimli", "Dwarf", 13, 7, 0, 3, 25, 9, 11, 14);
    riders.push_back(sprimli);
    Rider hofbrow("Hofbrow", "Dwarf", 12, 17, 10, 7, 18, 8, 3, 13);
    riders.push_back(hofbrow);
    Rider ultstone("Ultstone", "Dwarf", 10, 11, 12, 4, 15, 11, 17, 9);
    riders.push_back(ultstone);
    Rider windorf("Windorf", "Dwarf", 14, 10, 4, 6, 14, 16, 5, 17);
    riders.push_back(windorf);

    Rider florfindailyan("Florfindailyan", "Elf", 17, 7, 3, 3, 16, 17, 12, 13);
    riders.push_back(florfindailyan);
    Rider imin("Imin", "Elf", 7, 11, 12, 12, 12, 15, 10, 15);
    riders.push_back(imin);
    Rider tata("Tata", "Elf", 8, 10, 17, 5, 12, 15, 6, 5);
    riders.push_back(tata);
    Rider enel("Enel", "Elf", 10, 15, 15, 10, 14, 10, 6, 8);
    riders.push_back(enel);

    Rider joe("Joe", "Human", 13, 12, 12, 12, 12, 11, 11, 11);
    riders.push_back(joe);
    Rider george("George", "Human", 10, 14, 11, 14, 15, 6, 10, 10);
    riders.push_back(george);
    Rider vander("Vander", "Human", 15, 10, 4, 4, 20, 12, 15, 10);
    riders.push_back(vander);
    Rider spear("Spear", "Human", 11, 12, 16, 10, 12, 8, 8, 9);
    riders.push_back(spear);

    Rider grazar("Grazar", "Ork", 15, 10, 5, 15, 14, 4, 18, 9);
    riders.push_back(grazar);
    Rider gork("Gork", "Ork", 10, 10, 10, 17, 10, 14, 13, 8);
    riders.push_back(gork);
    Rider mork("Mork", "Ork", 12, 15, 7, 18, 7, 7, 15, 11);
    riders.push_back(mork);
    Rider speedDok("Speed Dok", "Ork", 8, 11, 13, 21, 8, 5, 14, 8);
    riders.push_back(speedDok);

    return riders;
}

std::vector<Team> initializeTeams(std::vector<Rider> &riders){
    std::cout << "Initializing teams..." << std::endl;
    std::vector<Team> teams;

    teams.push_back(initializeDwarfs(riders));
    teams.push_back(initializeElves(riders));
    teams.push_back(initializeHumans(riders));
    teams.push_back(initializeOrks(riders));

    return teams;
}

Team initializeDwarfs(std::vector<Rider> &riders) {
    Team dwarf("GoldCycle Ale-ians");
    dwarf.riders.push_back(&riders[0]);
    dwarf.riders.push_back(&riders[1]);
    dwarf.riders.push_back(&riders[2]);
    dwarf.riders.push_back(&riders[3]);
    return dwarf;
}

Team initializeElves(std::vector<Rider> &riders) {
    Team elf("Rogue Riders");
    elf.riders.push_back(&riders[4]);
    elf.riders.push_back(&riders[5]);
    elf.riders.push_back(&riders[6]);
    elf.riders.push_back(&riders[7]);
    return elf;
}

Team initializeHumans(std::vector<Rider> &riders) {
    Team human("BroterCycle Bro's");
    human.riders.push_back(&riders[8]);
    human.riders.push_back(&riders[9]);
    human.riders.push_back(&riders[10]);
    human.riders.push_back(&riders[11]);
    return human;
}

Team initializeOrks(std::vector<Rider> &riders) {
    Team ork("Dakka Weelz");
    ork.riders.push_back(&riders[8]);
    ork.riders.push_back(&riders[9]);
    ork.riders.push_back(&riders[10]);
    ork.riders.push_back(&riders[11]);
    return ork;
}

Map initializeMap(std::vector<Rider> &riders){
    std::cout << "Initializing map..." << std::endl;

    std::vector<std::string> terrain{ "flat", "Hill", "flat" };
    std::vector<std::string> condition{ "wind" };
    std::vector<std::string> specialEvents{ };

    MapPiece defaultMapPiece1(terrain, condition, specialEvents);
    MapPiece defaultMapPiece2(terrain, condition, specialEvents);
    MapPiece defaultMapPiece3(terrain, condition, specialEvents);
    MapPiece defaultMapPiece4(terrain, condition, specialEvents);
    
    std::vector<MapPiece> mapPieces;
    mapPieces.push_back(defaultMapPiece1);
    mapPieces.push_back(defaultMapPiece2);
    mapPieces.push_back(defaultMapPiece3);
    mapPieces.push_back(defaultMapPiece4);

    Map returnMap(mapPieces, initializeStartingGroup(riders));


    return returnMap;
}

Group initializeStartingGroup(std::vector<Rider> &riders) {
    std::vector<Rider*> pointerRiders;

    for (unsigned int i = 0; i < riders.size(); i++) {
        pointerRiders.push_back(&riders[i]);
    }
    Group returnGroup(pointerRiders);
    return returnGroup;
}

// Returns true when all players have submited their inputs
bool getAllPlayerInputs(std::vector<Player> &players) {
    //std::cout << "waiting for player input..." << std::endl;

    /*
        Types of rider actions:

    1. Sprint - All gass no breaks
    2. Pace - Choo choo
    3. Breakaway - Drop them when they least expect it
    4. Take position - follow a specified rider in an attempt to follow thier move more effeciently
        - You can take position behind allies and enemies alike
        - If more than one rider follows any given rider, do random() % # players to determine who succeeds.
        - If a rider is unsuccessful in their action they will default to follow
    5. Follow - free ride

    
    */

    for (unsigned int i = 0; i < players.size(); i++) {
        if (players[i].isReady == false) {
            return false;
        }
    }

    return true;
}

void resolveActions() {
    std::cout << "resolving actions..." << std::endl;
}

void initializeRidersToStartingLine(std::vector<Rider> &riders, Map &map) {
    for (unsigned int i = 0; i < riders.size(); i++) {
        riders[i].location = std::make_tuple(&map.mapPieces[0], &map.mapPieces[0].terrain[0]);
    }
}

void initializeActions(){
    Action pace("pace");
    Action sprint("sprint");
    Action follow("follow");


    std::cout << pace.name << std::endl;
}