#include <fstream>
#include <vector>

using namespace std;


int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m, node1, node2;
	in >> n >> m;
	vector<vector<int>> adjacency(n);
	for (int i = 0; i < m; i++) {
		in >> node1 >> node2;
		adjacency[node1 - 1].push_back(node2);
		adjacency[node2 - 1].push_back(node1);
	}
	for (int i = 0; i < n; i++) {
		out << '\n' << adjacency[i].size() << ' ';
		for (int j = 0; j < adjacency[i].size(); j++) {
			out << adjacency[i][j] << ' ';
		}
	}
}