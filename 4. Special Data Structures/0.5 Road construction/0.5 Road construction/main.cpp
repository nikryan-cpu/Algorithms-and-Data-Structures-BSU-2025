#include <fstream>
#include <vector>

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
		int xSet = FindSet(x);
		int ySet = FindSet(y);
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
	int towns, requests;
	in >> towns >> requests;
	DSU dsu(towns);
	for (int i = 0; i < towns; i++) {
		dsu.add();
	}
	for (int i = 0; i < requests; i++) {
		int tmp1, tmp2;
		in >> tmp1 >> tmp2;
		dsu.Union(tmp1 - 1, tmp2 - 1);
		out << dsu.getNumberOfSets() << '\n';
	}
}

