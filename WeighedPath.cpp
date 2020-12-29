#include "WeighedPath.h"

WeighedPath::WeighedPath() : Path() {
	cost = 0;
}

double WeighedPath::getCost() const {
	return cost;
}

bool WeighedPath::operator>(const WeighedPath& other) const {
	return cost > other.cost;
}

void WeighedPath::add(const std::string& vertex, double cost) {
	path.push_back(vertex);
	this->cost += cost;
}