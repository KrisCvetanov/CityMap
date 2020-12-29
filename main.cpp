#include <iostream>
#include "CityMap.h"
using namespace std;


int main()
{
  

    CityMap sofiaMap;
    sofiaMap.printCity();
    cout << "--------------------------------" << endl;
    sofiaMap.printReverseLinks();
    cout << "path between A and D? : " << sofiaMap.existsPath("Crossroad_A", "Crossroad_D") << endl << endl;
    std::unordered_set<std::string> closedRoads;
    std::list<WeighedPath> shortestPaths = sofiaMap.find3ShortestPaths("Crossroad_A", "Crossroad_D", closedRoads);
    for (const auto& elem : shortestPaths) {
        cout << elem << endl;
    }
    closedRoads.insert("Crossroad_B");
    shortestPaths = sofiaMap.find3ShortestPaths("Crossroad_A", "Crossroad_D", closedRoads);
    for (const auto& elem : shortestPaths) {
        cout << elem << endl;
    }
    cout << endl;
    cout << "B part of cycle? : " << sofiaMap.isVertexPartOfCycle("Crossroad_B") << endl;
    cout << "E part of cycle? : " << sofiaMap.isVertexPartOfCycle("Crossroad_E") << endl;
    optional<Path> tour = sofiaMap.findEulerPath();
    if (tour.has_value()) cout << tour.value() << endl;
    else cout << "No Euler path exists." << endl;
    cout << endl;

    cout << "Has paths to all others A? : " << sofiaMap.HasPathsToAllOthers("Crossroad_A") << endl;
    cout << "Has paths to all others E? : " << sofiaMap.HasPathsToAllOthers("Crossroad_E") << endl;
    cout << endl;
    std::list<Edge> deadEnds = sofiaMap.findAllDeadEnds();
    cout << "All dead ends : ";
    for (const auto& elem : deadEnds) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "The end!" << endl;
    return 0;
}

