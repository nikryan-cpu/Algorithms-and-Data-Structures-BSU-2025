#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;



int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m, node1, node2;
	pair<long long, int> nodeDist;
	short weight;
	in >> n >> m;
	vector<vector<pair<int, short>>> graph(n);
	vector<long long> result(n, INT_MAX);
	vector<bool> visited(n);
	priority_queue<pair<long long,int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> dist;
	for (int i = 0; i < m; i++) {
		in >> node1 >> node2 >> weight;
		graph[node1 - 1].push_back({ node2, weight });
		graph[node2 - 1].push_back({ node1, weight });
	}

	dist.push({ 0, 1 });
	while (!dist.empty()) {
		nodeDist = dist.top();
		if (visited[nodeDist.second - 1]) {
			dist.pop();
			continue;
		}
		visited[nodeDist.second - 1] = true;
		dist.pop();
		result[nodeDist.second - 1] = nodeDist.first;
		for (int i = 0; i < graph[nodeDist.second - 1].size(); i++) {
			dist.push({ nodeDist.first + graph[nodeDist.second - 1][i].second, graph[nodeDist.second - 1][i].first });
		}
	}
	out << result[result.size() - 1];
}