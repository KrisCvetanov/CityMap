#include "Edge.h"

Edge::Edge(const std::string& begin, const std::string& end) {
	this->begin = begin;
	this->end = end;
}

std::ostream& operator<<(std::ostream& os, const Edge& e) {
	os << e.begin << " -> " << e.end << std::endl;
	return os;
}