#ifndef _PATH
#define _PATH
#include <iostream>
#include <string>
#include <list>
#include <exception>

/// <summary>
/// represents a series of crossroads 
/// </summary>

class Path {
protected :
	std::list<std::string> path;

public:
	Path();
	Path(const std::list<std::string>&);

	// adds a crossroad at the end of the path
	void add(const std::string&);

	// adds a crossroad at the front of the path
	void add_front(const std::string&);

	// gets the last crossroad in the path
	const std::string& getLastVertex() const;

	// removes the last crossroad in the path
	void removeLastVertex();

	friend std::ostream& operator<<(std::ostream&, const Path&);
};

#endif // !_PATH
