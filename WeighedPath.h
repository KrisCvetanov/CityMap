#ifndef _WEIGHED_PATH
#define _WEIGHED_PATH
#include "Path.h"

/// <summary>
/// A path with cost(length)
/// </summary>

class WeighedPath : public Path {
private:
	double cost;

public:
	WeighedPath();

	// overrides add() from parent with additional argument for cost
	void add(const std::string&, double);

	// returns the cost(length) of the path
	double getCost() const;

	// Tells if *this is greater than some other path
	// the comparison is made by the costs of the paths
	bool operator>(const WeighedPath& other) const;

};

#endif // !_WEIGHED_PATH

