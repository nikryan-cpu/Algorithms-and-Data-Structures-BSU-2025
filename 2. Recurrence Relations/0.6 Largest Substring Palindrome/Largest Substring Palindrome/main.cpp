#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

int dp(std::string str1, std::string str2, std::vector<std::string>& result) {
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
	int i = str1.size() - 1;
	int j = str1.size() - 1;
	while (i > 0 and j > 0) {
		if (str1[i] == str2[j]) {
			std::string s{ str1[i] };
			result.push_back(s);
			i--;
			j--;
		}
		else if (result_matrix[i - 1][j] >= result_matrix[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}
	return result_matrix[str1.size() - 1][str1.size() - 1];
}


int main() {
	std::ifstream in("input.txt"); 
	std::string str;
	std::string str1;
	in >> str1;
	std::reverse(str1.begin(), str1.end());
	std::string reverse_str = "0" + str1;
	std::reverse(str1.begin(), str1.end());
	str = "0" + str1;
	std::vector<std::string> result;
	std::ofstream out;
	out.open("output.txt");
	int res = dp(str, reverse_str, result);
	out << res << '\n';
	for (int i = result.size() - 1; i >= 0; i--)
		out << result[i];
}