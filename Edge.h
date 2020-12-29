#ifndef _EDGE
#define _EDGE
#include <iostream>
#include <string>

/// <summary>
/// represents a street between two crossroads
/// </summary>

class Edge {
private:
	std::string begin;
	std::string end;

public:
	Edge(const std::string&, const std::string&);

	friend std::ostream& operator<<(std::ostream&, const Edge&);
};

#endif // !_EDGE

