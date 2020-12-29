#include <iostream>
#include "CityMap.h"
using namespace std;


int main()
{
  

    CityMap sofiaMap;
    sofiaMap.printCity();
    optional<Path> tour = sofiaMap.findEulerPath();
    if (tour.has_value()) cout << tour.value() << endl;
    else cout << "No Euler path exists." << endl;
    return 0;
}

