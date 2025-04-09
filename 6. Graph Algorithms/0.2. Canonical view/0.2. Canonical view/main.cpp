#include <fstream>
#include <vector>


using namespace std;


int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, node1, node2;
	in >> n;
	vector<int> nodes(n + 1, 0);
	for (int i = 0; i < n; i++) {
		in >> node1 >> node2;
		nodes[node2] = node1;
	}
	for (int i = 1; i < n + 1; i++) {
		out << nodes[i] << ' ';
	}
}