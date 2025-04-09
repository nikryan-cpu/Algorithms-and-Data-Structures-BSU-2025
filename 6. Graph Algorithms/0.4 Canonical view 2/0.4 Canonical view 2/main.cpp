#include <fstream>
#include <vector>

using namespace std;


int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	bool notARoot = false;
	int n, nSquare, tmp;
	in >> n;
	vector<int> nodes(n + 1);
	vector<vector<int>> matrix(n + 1);
	for (int i = 1; i < n + 1; i++) {
		matrix[i].push_back(0);
		for (int j = 1; j < n + 1; j++) {
			in >> tmp;
			matrix[i].push_back(tmp);
		}
	}


	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (matrix[j][i]) {
				notARoot = true;
				nodes[i] = j;
			}
		}
		if (!notARoot)
			nodes[i] = 0;
		notARoot = false;
	}
	for (int i = 1; i < n + 1; i++)
		out << nodes[i] << ' ';
}