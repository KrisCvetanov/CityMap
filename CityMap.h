#ifndef _CITY_MAP
#define _CITY_MAP
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <optional>
#include <exception>
#include <fstream>
#include "Edge.h"
#include "Path.h"

/// <summary>
/// The main class in the project
/// !!! NOTE: This class uses the library <optional>, which is included after C++17. !!!
/// </summary>

class CityMap {
private:
	// the graph, representing the crossroads and their links
	std::unordered_map<std::string, std::unordered_map<std::string, double> > crossroads;

	// we need to keep the reversed links in the graph for some algorithms
	std::unordered_map<std::string, std::unordered_set<std::string> > reverseLinks;
	
	// loads the information for the crossroads from a file
	void loadCity(const std::string&);

	// method is used in loadCity(). Loads the links of the current crossroad from the file
	void loadCurrCrossroad(std::string&);

	// when the information from the file is loaded, creates the reverse links of the graph
	void makeReverseLinks();

	// a helper method, marks all crossroads as unchecked. Used in some algorithms
	void markAllAsFalse(std::unordered_map<std::string, bool>& marked) const;

	// a helper method, marks all streets as untraversed. Used in the Euler path algorithm
	void createAllEdges(std::unordered_map<std::string, std::unordered_set<std::string> >&) const;

	// standart dfs with additional bool parameter
	void dfs(const std::string&, const std::string&, std::unordered_map<std::string, bool>&, int, bool&) const;

	// hierholzer algorithm, used in finding Euler path
	Path hierholzerAlgorithm(const std::string&, 
							 std::unordered_map<std::string, std::unordered_set<std::string> >&) const;

	// checks certain conditions for the existance of Euler path
	bool checkConditionsForEulerPath(std::string&, std::string&) const;

	// checks if the graph is Eulerian (if there is Euler circuit)
	bool inEqualsOutForAllVertecies(std::string&, std::string&) const;

public:
	CityMap();
	CityMap(const std::string&);

	void printCity() const; // for local testing
	void printReverseLinks() const; // for local testing

	// task 1.
	bool existsPath(const std::string&, const std::string&) const;

	// task 2. and 3.
	std::list<Path> find3ShortestPaths(const std::string&, 
										const std::string&,
										const std::unordered_set<std::string>&) const;

	// task 4.
	bool isVertexPartOfCycle(const std::string&) const;

	// task 5.
	std::optional<Path> findEulerPath() const;

	// task 6.
	bool HasPathsToAllOthers(const std::string&) const;

	// task 7.
	std::list<Edge> findAllDeadEnds() const;
	
};


#endif // !_CITY_MAP

