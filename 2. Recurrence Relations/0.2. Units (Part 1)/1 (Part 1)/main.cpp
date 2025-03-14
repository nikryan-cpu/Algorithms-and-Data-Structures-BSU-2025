#include <iostream>
#include <vector>
using namespace std;

int dp(vector<vector<int>>& result){
	for (int i = 0; i < result.size(); i++)
		result[i][0] = 1;
	int i1 = 0; int i2 = 0;
	while (i2 < result[0].size()) {
		result[i1][i2] = 1;
		i1++;
		i2++;
	}
	for (int i = 0; i < result.size(); i++) {
		for (int j = 1; j < result[0].size(); j++) {
			if (j >= i)
				break;
			else {
				result[i][j] = (result[i - 1][j - 1] % 1000000007 + result[i - 1][j] % 1000000007) % 1000000007;
			}
		}
	}
	return result[result.size() - 1][result[0].size() - 1];
}


int main() {
	int n, k; 
	cin >> n >> k;
	vector<vector<int>> result(n + 1);  
	for (int i = 0; i < n + 1; i++)
		result[i].resize(k + 1);
	int res = dp(result);
	cout << res;
}