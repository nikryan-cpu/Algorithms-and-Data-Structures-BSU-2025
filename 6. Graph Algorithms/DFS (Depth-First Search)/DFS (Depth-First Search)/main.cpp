#include <fstream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>>& matrix, vector<int>& result, int& count, vector<int>& visited) {
	visited[node - 1] = true;
	result[node - 1] = ++count;
	for (int i = 0; i < matrix[node - 1].size(); i++) {
		if (matrix[node - 1][i] == 1 and !visited[i])
			dfs(i + 1, matrix, result, count, visited);
	}
}


int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, tmp, count = 0;
	stack<int> stack;
	in >> n;
	vector<int> result(n);
	vector<int> visited(n, false);
	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> tmp;
			matrix[i].push_back(tmp);
		}
	}
	for (int i = 1; i < n + 1; i++) {
		if (!visited[i - 1])
			dfs(i, matrix, result, count, visited);
	}
	for (auto& i : result)
		out << i << ' ';
}