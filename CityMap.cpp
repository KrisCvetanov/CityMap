#include "CityMap.h"

CityMap::CityMap() {
	loadCity("citymap.txt");
}

CityMap::CityMap(const std::string& dir) {
	loadCity(dir);
}

void CityMap::loadCity(const std::string& dir) {
	std::ifstream iFile(dir, std::ios::in);
	if (!iFile) {
		throw std::invalid_argument("No such file was found.");
	}
	while (!iFile.eof()) {
		std::string line;
		std::getline(iFile, line);
		loadCurrCrossroad(line);
	}
	makeReverseLinks();
}
void CityMap::loadCurrCrossroad(std::string& line) {
	int index_start = 0, index_end = 0, lineSize = line.size();
	while (line[index_end] != ' ' && index_end < lineSize) ++index_end;
	std::string crossroad = line.substr(index_start, index_end);
	index_start = ++index_end;
	std::unordered_map<std::string, double> adj;
	while (index_end < lineSize) {
		// read string
		while (line[index_end] != ' ') ++index_end;
		std::string currRoad = line.substr(index_start, index_end - index_start);
		index_start = ++index_end;
		// read int
		while (line[index_end] != ' ' && index_end < lineSize) ++index_end;
		int distance = std::stoi(line.substr(index_start, index_end - index_start));
		index_start = ++index_end;

		if (crossroads.find(currRoad) == crossroads.end()) {
			std::unordered_map<std::string, double> emptyMap;
			crossroads[currRoad] = emptyMap;
		}

		adj[currRoad] = distance;
	}
	crossroads[crossroad] = adj;
}

void CityMap::makeReverseLinks() {
	for (const auto& v : crossroads) {
		std::unordered_set<std::string> reverseAdj;
		reverseLinks[v.first] = reverseAdj;
	}
	for (const auto& v : crossroads) {
		for (const auto& link : v.second) {
			reverseLinks.at(link.first).insert(v.first);
		}
	}
}

void CityMap::printCity() const {
	for (const auto& road : crossroads) {
		std::cout << "key: " << road.first << std::endl;
		std::cout << "values: ";
		for (const auto& currRoad : road.second) {
			std::cout << currRoad.first << " " << currRoad.second << " | ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

void CityMap::printReverseLinks() const {
	for (const auto& road : reverseLinks) {
		std::cout << "key: " << road.first << std::endl;
		std::cout << "values: ";
		for (const auto& currRoad : road.second) {
			std::cout << currRoad << " | ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

void CityMap::markAllAsFalse(std::unordered_map<std::string, bool>& marked) const {
	for (const auto& v : crossroads) {
		marked[v.first] = false;
	}
}

bool CityMap::existsPath(const std::string& u, const std::string& v) const {
	if (crossroads.find(u) == crossroads.end()
		|| crossroads.find(v) == crossroads.end()) {
		throw std::invalid_argument("Invalid crossroad given as an argument.");
	}
	if (u == v) return true;
	std::queue<std::string> q;
	std::unordered_map<std::string, bool> marked;
	markAllAsFalse(marked);
	marked[u] = true;
	q.push(u);
	while (!q.empty()) {
		std::string curr = q.front();
		q.pop();
		const std::unordered_map<std::string, double>& currAdj = crossroads.at(curr);
		for (const auto& neighbour : currAdj) {
			if (marked.at(neighbour.first)) continue;
			if (neighbour.first == v) return true;
			marked[neighbour.first] = true;
			q.push(neighbour.first);
		}
	}
	return false;
}

bool CityMap::HasPathsToAllOthers(const std::string& u) const {
	if (crossroads.find(u) == crossroads.end()) {
		throw std::invalid_argument("Invalid crossroad given as an argument.");
	}
	std::queue<std::string> q;
	std::unordered_map<std::string, bool> marked;
	markAllAsFalse(marked);
	marked[u] = true;
	q.push(u);
	while (!q.empty()) {
		std::string curr = q.front();
		q.pop();
		const std::unordered_map<std::string, double>& currAdj = crossroads.at(curr);
		for (const auto& neighbour : currAdj) {
			if (!marked.at(neighbour.first)) {
				marked[neighbour.first] = true;
				q.push(neighbour.first);
			}
		}
	}
	for (const auto& cond : marked) {
		if (!cond.second) return false;
	}
	return true;
}

std::list<Edge> CityMap::findAllDeadEnds() const {
	std::list<Edge> deadEnds;
	for (const auto& v : crossroads) {
		if (v.second.size() == 0) {
			for (const auto& u : reverseLinks.at(v.first)) {
				Edge e(u, v.first);
				deadEnds.push_back(e);
			}
		}
	}
	return deadEnds;
}

bool CityMap::isVertexPartOfCycle(const std::string& u) const {
	if (crossroads.find(u) == crossroads.end()) {
		throw std::invalid_argument("Invalid crossroad given as an argument.");
	}
	std::unordered_map<std::string, bool> marked;
	markAllAsFalse(marked);
	bool inCycle = false;
	dfs(u, u, marked, 0, inCycle);
	return inCycle;
}

void CityMap::dfs(const std::string& start,
	const std::string& u,
	std::unordered_map<std::string, bool>& marked,
	int level,
	bool& inCycle) const {

	if (level == crossroads.size()) return;

	marked[u] = true;
	for (const auto& v : crossroads.at(u)) {
		if (v.first == start) inCycle = true;
		if (!marked[v.first]) dfs(start, v.first, marked, level + 1, inCycle);
	}
}

std::list<Path> CityMap::find3ShortestPaths(const std::string& start, 
											const std::string& end,
											const std::unordered_set<std::string>& closedRoads) const {
	if (crossroads.find(start) == crossroads.end()
		|| crossroads.find(end) == crossroads.end()) {
		throw std::invalid_argument("Invalid crossroad given as an argument.");
	}
	const int k = 3;
	std::priority_queue <Path, std::vector<Path>, std::greater<Path> > heap;
	std::list<Path> shortestPaths;
	if (closedRoads.find(start) != closedRoads.end()
		|| closedRoads.find(end) != closedRoads.end()) {
		return shortestPaths;
	}
	std::unordered_map<std::string, int> pathsToVertex;
	for (const auto& v : crossroads) {
		pathsToVertex[v.first] = 0;
	}

	Path ps;
	ps.add(start, 0);
	heap.push(ps);
	while (!heap.empty() && pathsToVertex.at(end) < k) {
		Path pu = heap.top();
		std::string u = pu.getLastVertex();
		heap.pop();
		pathsToVertex[u]++;
		if (u == end) shortestPaths.push_back(pu);
		if (pathsToVertex.at(u) <= k) {
			for (const auto& v : crossroads.at(u)) {
				if (closedRoads.find(v.first) != closedRoads.end()) continue;
				Path pv = pu;
				pv.add(v.first, v.second);
				heap.push(pv);
			}
		}
	}
	return shortestPaths;
}

std::optional<Path> CityMap::findEulerPath() const {
	std::string start, end;
	Path cityTour;
	std::unordered_map<std::string, std::unordered_set<std::string> > markedEdges;
	createAllEdges(markedEdges);
	bool pathIsCircuit = true;
	if (checkConditionsForEulerPath(start, end)) {
		// add edge end -> start
		markedEdges.at(end).insert(start);
		pathIsCircuit = false;
	}
	// else, if graph isn't eulerian, then there is no euler path
	else if (!inEqualsOutForAllVertecies(start, end)) return {};

	// hierholzer algorithm
	cityTour = hierholzerAlgorithm(start, markedEdges);

	// remake cylcle to path if needed
	if (!pathIsCircuit) {
		cityTour.removeLastVertex();
	}
	return cityTour;
}

bool CityMap::checkConditionsForEulerPath(std::string& start, std::string& end) const {
	// check if there is a vertex 'start', that has in == out + 1
	// check if there is a vertex 'end', that has in + 1 == out	
	// check if all other vertecies have in == out
	bool flagStart = false, flagEnd = false;
	for (const auto& v : crossroads) {
		bool conditionOther = (v.second.size() == reverseLinks.at(v.first).size());
		bool conditionStart = (v.second.size() == reverseLinks.at(v.first).size() + 1);
		bool conditionEnd = (v.second.size() + 1 == reverseLinks.at(v.first).size());
		
		if (conditionOther) continue;
		else if (!flagStart && conditionStart) { 
			flagStart = true;
			start = v.first;
		}
		else if (!flagEnd && conditionEnd) {
			flagEnd = true;
			end = v.first;
		}
		else return false;
	}
	return flagStart && flagEnd;
}

bool CityMap::inEqualsOutForAllVertecies(std::string& start, std::string& end) const {
	for (const auto& v : crossroads) {
		if (v.second.size() != reverseLinks.at(v.first).size()) return false;
	}

	// since there will be an Euler cicuit, we take a random vertex as start/end
	start = end = crossroads.begin()->first;
	
	return true;
}

void CityMap::createAllEdges(std::unordered_map<std::string, std::unordered_set<std::string> >& edges) const {
	for (const auto& v : crossroads) {
		std::unordered_set<std::string> ends;
		for (const auto& link : v.second) {
			ends.insert(link.first);
		}
		edges[v.first] = ends;
	}
}

Path CityMap::hierholzerAlgorithm(const std::string& start, 
								  std::unordered_map<std::string, std::unordered_set<std::string> >& edges) const {
	Path cityTour;
	std::stack<std::string> st;
	st.push(start);
	while (!st.empty()) {
		std::string v = st.top();
		if (edges.at(v).empty()) {
			cityTour.add_front(v);
			st.pop();
			continue;
		}
		std::string u = *edges.at(v).begin();
		st.push(u);
		edges.at(v).erase(u);
	}

	return cityTour;
}
