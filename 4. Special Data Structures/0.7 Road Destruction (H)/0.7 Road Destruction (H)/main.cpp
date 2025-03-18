#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


class DSU {
private:
	vector<int> elements;
	int numberOfSets = 0;
public:
	DSU(int size) {
		elements.reserve(size);
	}
	int getNumberOfSets() {
		return numberOfSets;
	}
	void add() {
		elements.push_back(-1);
		numberOfSets++;
	}
	int FindSet(int x) {
		if (elements[x] < 0) {
			return x;
		}
		else {
			return elements[x] = FindSet(elements[x]);
		}
	}
	void Union(int x, int y) {
		int xSet = FindSet(x - 1);
		int ySet = FindSet(y - 1);
		if (xSet != ySet) {
			if (elements[xSet] < elements[ySet]) { //Negative numbers
				RealUnion(xSet, ySet);
			}
			else {
				RealUnion(ySet, xSet);
			}
			numberOfSets--;
		}
	}
private:
	void RealUnion(int set1, int set2) {
		elements[set1] += elements[set2];
		elements[set2] = set1;
	}
};

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int towns, roads, amountEarthquakes;
	in >> towns >> roads >> amountEarthquakes;
	vector<pair<int, int>> roadsBefore(roads);
	vector<int> earthquakes;
	earthquakes.reserve(amountEarthquakes);
	int tmp, tmp1, tmp2;
	for (int i = 0; i < roadsBefore.size(); i++) {
		in >> tmp1 >> tmp2;
		roadsBefore[i].first = tmp1;
		roadsBefore[i].second = tmp2;
	}
	vector<pair<int, int>> roadsAfter;
	vector<bool> del(roadsBefore.size(), 1);
	for (int i = 0; i < amountEarthquakes; i++) {
		int tmp;
		in >> tmp;
		earthquakes.push_back(tmp);
		del[earthquakes[i] - 1] = 0;
	}
	vector<int>result;
	result.reserve(amountEarthquakes);
	for (int i = 0; i < roadsBefore.size(); i++) {
		if (del[i] == 1) {
			roadsAfter.push_back(roadsBefore[i]);
		}
	}
	DSU dsu(towns);
	for (int i = 0; i < towns; i++) {
		dsu.add();
	}
	for (const auto& i : roadsAfter) {
		dsu.Union(i.first, i.second);
	}
	result.push_back(dsu.getNumberOfSets());
	for (int i = earthquakes.size() - 1; i > 0; i--) {
		dsu.Union(roadsBefore[earthquakes[i] - 1].first, roadsBefore[earthquakes[i] - 1].second);
		result.push_back(dsu.getNumberOfSets());
	}
	std::reverse(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		if (result[i] == 1)
			out << 1;
		else
			out << 0;
	}

}