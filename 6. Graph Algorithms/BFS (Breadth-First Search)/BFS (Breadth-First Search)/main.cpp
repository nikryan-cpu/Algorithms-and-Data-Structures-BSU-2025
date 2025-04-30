#include <fstream>
#include <vector>
#include <queue>

using namespace std;


int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	queue<int> queue;
	int n, tmp, node, count = 0;
	in >> n;
	vector<bool> visited(n, false);
	vector<int> result(n);
	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> tmp;
			matrix[i].push_back(tmp);
		}
	}
	for (int k = 0; k < n; k++) {
		if (visited[k] != true) {
			queue.push(k + 1);
			visited[k] = true;
			while (!queue.empty()) {
				node = queue.front();
				queue.pop();
				count++;
				result[node - 1] = count;
				for (int i = 0; i < matrix[node - 1].size(); i++) {
					if (matrix[node - 1][i] == 1 and visited[i] == false) {
						queue.push(i + 1);
						visited[i] = true;
					}
				}
			}
		}
	}
	for (auto& i : result)
		out << i << ' ';
}