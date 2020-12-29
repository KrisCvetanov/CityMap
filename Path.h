#ifndef _PATH
#define _PATH
#include <iostream>
#include <string>
#include <list>

/// <summary>
/// represents a series of crossroads and the cost(length) of the path
/// </summary>

class Path {
private :
	std::list<std::string> path;
	double cost;

public:
	Path();
	Path(const std::list<std::string>&);

	// adds a crossroad at the end of the path
	void add(const std::string&, double);

	// adds a crossroad at the front of the path(in this case no cost is needed)
	void add_front(const std::string&);

	// gets the last crossroad in the path
	const std::string& getLastVertex() const;

	// removes the last crossroad in the path
	void removeLastVertex();

	// gets the cost(length) of the path
	double getCost() const;

	// checks if *this is greater than some other path
	// comparison is by the cost of the paths
	bool operator>(const Path&) const;

	friend std::ostream& operator<<(std::ostream&, const Path&);
};

#endif // !_PATH
