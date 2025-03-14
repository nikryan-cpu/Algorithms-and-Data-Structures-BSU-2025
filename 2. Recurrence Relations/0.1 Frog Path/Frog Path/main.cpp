#include <iostream>
#include <vector>

std::vector<int> getPath(std::vector<int>& answer, std::vector<int>& flowers) {
	answer[1] = -1;
	answer[2] = answer[0] + answer[2];
	for (int i = 3; i < answer.size(); i++) {
		answer[i] = std::max(answer[i - 2], answer[i - 3]) + answer[i];
	}
	std::vector<int> path;
	int i = answer.size() - 1;
	path.push_back(answer.size() - 1 + 1);
	while (i >= 2) {
		int prev_answer = answer[i] - flowers[i];
		if (answer[i - 2] == prev_answer) {
			i -= 2;
		}
		else if (answer[i - 3] == prev_answer) {
			i -= 3;
		}
		path.push_back(i + 1);
	}
	return path;
}


int main() {
	int n;
	std::cin >> n;
	std::vector<int> answer(n);
	for (int i = 0; i < n; i++) {
		std::cin >> answer[i];
	}
	if(answer.size() == 2 || answer.size() == 0) {
		std::cout << -1;
		return 0;
	}
	if (answer.size() == 1) {
		std::cout << answer[0] << '\n' << '1';
		return 0;
	}
	std::vector<int> flowers(answer);
	std::vector<int> path = getPath(answer, flowers);
	std::cout << answer[n - 1] << '\n';
		for (int i = path.size() - 1; i >= 0; i--)
			std::cout << path[i] << ' ';
}