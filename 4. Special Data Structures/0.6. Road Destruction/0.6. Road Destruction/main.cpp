#include <fstream>
#include <vector>
#include <map>
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
			return FindSet(elements[x]);
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


/*We add only those roads that will remain after earthquakes,
and then we add roads that were removed one by one and save the number of sets in the DSU*/

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int towns, roads, amountEarthquakes;
	in >> towns >> roads >> amountEarthquakes;
	vector<pair<int, int>> roadsAfter(roads);
	vector<int> earthquakes;
	earthquakes.reserve(amountEarthquakes);
	int tmp, tmp1, tmp2;
	for (int i = 0; i < roadsAfter.size(); i++) {
		in >> tmp1 >> tmp2;
		roadsAfter[i].first = tmp1;
		roadsAfter[i].second = tmp2;
	}
	std::vector<int> indicesToDelete;
	vector<pair<int, int>> roadsBefore(roadsAfter);
	for (int i = 0; i < amountEarthquakes; i++) {
        int tmp;
        in >> tmp; 
        earthquakes.push_back(tmp);
        indicesToDelete.push_back(tmp - 1);
    }
	vector<int>result;
	std::sort(indicesToDelete.begin(), indicesToDelete.end(), std::greater<int>());
	for (int idx : indicesToDelete) {
		if (idx >= 0 && idx < static_cast<int>(roadsAfter.size())) {
			roadsAfter.erase(roadsAfter.begin() + idx);
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