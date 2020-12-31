#include <iostream>
#include "CityMap.h"
using namespace std;


int main()
{
  
    /*cout << "--------------------------------------- Test citymap.txt ----------------------------------------------------------" << endl << endl;
    CityMap sofiaMap;
    cout << "task 1." << endl;
    cout << "path from A to D? : " << sofiaMap.existsPath("Crossroad_A", "Crossroad_D") << endl;
    cout << "path from E to C? : " << sofiaMap.existsPath("Crossroad_E", "Crossroad_C") << endl << endl;
    cout << "task 2." << endl;
    cout << "3 shortest paths between A and D (no closed roads) : " << endl;
    std::unordered_set<std::string> closedRoads;
    std::list<WeighedPath> shortestPaths = sofiaMap.find3ShortestPaths("Crossroad_A", "Crossroad_D", closedRoads);
    for (const auto& elem : shortestPaths) {
        cout << elem << endl;
    }
    cout << "task 3." << endl;
    closedRoads.insert("Crossroad_B");
    cout << "Closing road B..." << endl;
    cout << "3 shortest paths between A and D (road B is closed) : " << endl;
    shortestPaths = sofiaMap.find3ShortestPaths("Crossroad_A", "Crossroad_D", closedRoads);
    if (shortestPaths.empty()) cout << "No paths found." << endl;
    for (const auto& elem : shortestPaths) {
        cout << elem << endl;
    }
    cout << endl << endl;
    cout << "task 4." << endl;
    cout << "Is B part of cycle? : " << sofiaMap.isVertexPartOfCycle("Crossroad_B") << endl;
    cout << "Is E part of cycle? : " << sofiaMap.isVertexPartOfCycle("Crossroad_E") << endl << endl;
    cout << "task 5." << endl;
    cout << "Is there an Euler path in the graph?" << endl;
    optional<Path> tour = sofiaMap.findEulerPath();
    if (tour.has_value()) cout << "Yes, there is." << endl << tour.value() << endl;
    else cout << "No Euler path exists." << endl;
    cout << endl;
    cout << "task 6." << endl;
    cout << "Has paths to all others A? : " << sofiaMap.HasPathsToAllOthers("Crossroad_A") << endl;
    cout << "Has paths to all others E? : " << sofiaMap.HasPathsToAllOthers("Crossroad_E") << endl;
    cout << endl;
    cout << "task 7." << endl;
    std::list<Edge> deadEnds = sofiaMap.findAllDeadEnds();
    cout << "All dead ends : " << endl;
    for (const auto& elem : deadEnds) {
        cout << elem;
    }
    cout << endl;/**/


    /*cout << "--------------------------------------- Test citymap2.txt ----------------------------------------------------------" << endl;
    CityMap sofiaMap("citymap2.txt");
    cout << "task 1." << endl;
    cout << "path from A to D? : " << sofiaMap.existsPath("Crossroad_A", "Crossroad_D") << endl;
    cout << "path from E to C? : " << sofiaMap.existsPath("Crossroad_E", "Crossroad_C") << endl << endl;
    cout << "task 2." << endl;
    cout << "3 shortest paths between C and F (no closed roads) : " << endl;
    std::unordered_set<std::string> closedRoads;
    std::list<WeighedPath> shortestPaths = sofiaMap.find3ShortestPaths("Crossroad_C", "Crossroad_F", closedRoads);
    for (const auto& elem : shortestPaths) {
        cout << elem << endl;
    }
    cout << "task 3." << endl;
    closedRoads.insert("Crossroad_E");
    cout << "Closing road E..." << endl;
    cout << "3 shortest paths between C and F (road E is closed) : " << endl;
    shortestPaths = sofiaMap.find3ShortestPaths("Crossroad_C", "Crossroad_F", closedRoads);
    if (shortestPaths.empty()) cout << "No paths found." << endl;
    for (const auto& elem : shortestPaths) {
        cout << elem << endl;
    }
    cout << endl << endl;
    cout << "task 4." << endl;
    cout << "Is B part of cycle? : " << sofiaMap.isVertexPartOfCycle("Crossroad_B") << endl;
    cout << "Is E part of cycle? : " << sofiaMap.isVertexPartOfCycle("Crossroad_E") << endl << endl;
    cout << "task 5." << endl;
    cout << "Is there an Euler path in the graph?" << endl;
    optional<Path> tour = sofiaMap.findEulerPath();
    if (tour.has_value()) cout << "Yes, there is." << endl << tour.value() << endl;
    else cout << "No Euler path exists." << endl;
    cout << endl;
    cout << "task 6." << endl;
    cout << "Has paths to all others A? : " << sofiaMap.HasPathsToAllOthers("Crossroad_A") << endl;
    cout << "Has paths to all others E? : " << sofiaMap.HasPathsToAllOthers("Crossroad_E") << endl;
    cout << endl;
    cout << "task 7." << endl;
    std::list<Edge> deadEnds = sofiaMap.findAllDeadEnds();
    cout << "All dead ends : " << endl;
    for (const auto& elem : deadEnds) {
        cout << elem;
    }
    cout << endl;/**/

    
    /*cout << "--------------------------------------- Test citymap3.txt ----------------------------------------------------------" << endl;
    CityMap sofiaMap("citymap3.txt");
    cout << "task 1." << endl;
    cout << "path from A to D? : " << sofiaMap.existsPath("Crossroad_A", "Crossroad_D") << endl;
    cout << "path from B to E? : " << sofiaMap.existsPath("Crossroad_B", "Crossroad_E") << endl << endl;
    cout << "task 2." << endl;
    cout << "3 shortest paths between C and B (no closed roads) : " << endl;
    std::unordered_set<std::string> closedRoads;
    std::list<WeighedPath> shortestPaths = sofiaMap.find3ShortestPaths("Crossroad_C", "Crossroad_B", closedRoads);
    for (const auto& elem : shortestPaths) {
        cout << elem << endl;
    }
    cout << "task 3." << endl;
    closedRoads.insert("Crossroad_D");
    cout << "Closing road D..." << endl;
    cout << "3 shortest paths between C and B (road D is closed) : " << endl;
    shortestPaths = sofiaMap.find3ShortestPaths("Crossroad_C", "Crossroad_B", closedRoads);
    if (shortestPaths.empty()) cout << "No paths found." << endl;
    for (const auto& elem : shortestPaths) {
        cout << elem << endl;
    }
    cout << endl << endl;
    cout << "task 4." << endl;
    cout << "Is B part of cycle? : " << sofiaMap.isVertexPartOfCycle("Crossroad_B") << endl;
    cout << "Is E part of cycle? : " << sofiaMap.isVertexPartOfCycle("Crossroad_E") << endl << endl;
    cout << "task 5." << endl;
    cout << "Is there an Euler path in the graph?" << endl;
    optional<Path> tour = sofiaMap.findEulerPath();
    if (tour.has_value()) cout << "Yes, there is." << endl << tour.value() << endl;
    else cout << "No Euler path exists." << endl;
    cout << endl;
    cout << "task 6." << endl;
    cout << "Has paths to all others A? : " << sofiaMap.HasPathsToAllOthers("Crossroad_A") << endl;
    cout << "Has paths to all others E? : " << sofiaMap.HasPathsToAllOthers("Crossroad_E") << endl;
    cout << endl;
    cout << "task 7." << endl;
    std::list<Edge> deadEnds = sofiaMap.findAllDeadEnds();
    cout << "All dead ends : " << endl;
    for (const auto& elem : deadEnds) {
        cout << elem;
    }
    cout << endl;/**/

    return 0;
}

