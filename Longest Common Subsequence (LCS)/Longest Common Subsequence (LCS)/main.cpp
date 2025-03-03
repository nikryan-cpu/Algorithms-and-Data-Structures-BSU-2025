#include <iostream>
#include <vector>

void dp(std::vector<int>& str1, std::vector<int>& str2, std::vector<int>& result1, std::vector<int>& result2) {
	std::vector<std::vector<int>> result_matrix(str1.size() + 1);
	for (int i = 0; i < str1.size() + 1; i++) {
		result_matrix[i].resize(str1.size() + 1);
	}
	for (int i = 0; i < str1.size() + 1; i++) {
		result_matrix[i][0] = 0;
	}
	for (int j = 0; j < str1.size() + 1; j++) {
		result_matrix[0][j] = 0;
	}

	for (int i = 1; i < str1.size(); i++) {
		for (int j = 1; j < str1.size(); j++) {
			if (str1[i] == str2[j]) {
				result_matrix[i][j] = result_matrix[i - 1][j - 1] + 1;
			}
			else {
				result_matrix[i][j] = std::max(result_matrix[i - 1][j], result_matrix[i][j - 1]);
			}	
		}
	}
	std::cout << result_matrix[str1.size() - 1][str1.size() - 1] << '\n';
	int i = str1.size() - 1;
	int j = str1.size() - 1;
	while (i > 0 and j > 0) {
		if (str1[i] == str2[j]) {
			result1.push_back(i - 1);
			result2.push_back(j - 1);
			i--;
			j--;
		}
		else if (result_matrix[i - 1][j] >= result_matrix[i][j - 1]){
			i--;
		}
		else {
			j--;
		}
	}
}



int main() {
	int n;
	std::cin >> n;
	if (n == 0)
		return 0;
	std::vector<int> str1(n + 1);
	std::vector<int> str2(n + 1);
	std::vector<int> result1;
	std::vector<int> result2;
	str1[0] = 0;
	str2[0] = 0;
	for (int i = 1; i < n + 1; i++)
		std::cin >> str1[i];
	for (int i = 1; i < n + 1; i++)
		std::cin >> str2[i];
	dp(str1, str2, result1, result2);
	for (int i = result1.size() - 1; i >= 0; i--)
		std::cout << result1[i] << ' ';
	std::cout << '\n';
	for (int i = result1.size() - 1; i >= 0; i--)
		std::cout << result2[i] << ' ';
}