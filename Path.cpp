#include "Path.h"

Path::Path() {

}

Path::Path(const std::list<std::string>& l) {
	path = l;
}

void Path::add(const std::string& vertex) {
	path.push_back(vertex);
}

void Path::add_front(const std::string& vertex) {
	path.push_front(vertex);
}

const std::string& Path::getLastVertex() const {
	return path.back();
}

void Path::removeLastVertex() {
	if (path.empty()) return;
	
	path.pop_back();
}

std::ostream& operator<<(std::ostream& os, const Path& p) {
	std::list<std::string>::const_iterator it;
	for (it = p.path.begin(); it != p.path.end(); ++it) {
		std::list<std::string>::const_iterator temp = it;
		++temp;
		if (temp == p.path.end()) break;
		os << *it << " -> ";
	}
	if (it != p.path.end()) {
		os << *it << std::endl;
	}
	return os;
}