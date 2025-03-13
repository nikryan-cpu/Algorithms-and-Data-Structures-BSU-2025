#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		out << 1;
		return 0;
	}
	vector<int> sequence(n);
	for (int i = 0; i < n; i++) {
		in >> sequence[i];
	}
	vector<int> tempForward;
	vector<int> tempBackward;
	vector<int> left(n);
	vector<int> right(n);
	tempForward.push_back(sequence[0]);
	left[0] = tempForward.size();
	for (int i = 1; i < n; i++) {
		if (sequence[i] <= tempForward[tempForward.size() - 1]){
			auto it = std::lower_bound(tempForward.begin(), tempForward.end(), sequence[i]);
			*it = sequence[i];
			left[i] = std::distance(tempForward.begin(), it) + 1;
		}
		else {
			tempForward.push_back(sequence[i]);
			left[i] = tempForward.size();
		}
	}
	std::reverse(sequence.begin(), sequence.end());
	tempBackward.push_back(sequence[0]);
	right[0] = tempBackward.size();
	for (int i = 1; i < sequence.size(); i++) {
		if (sequence[i] >= tempBackward[tempBackward.size() - 1]) {
			auto it = std::lower_bound(tempBackward.begin(), tempBackward.end(), sequence[i], std::greater<int>());
			*(it) = sequence[i];
			right[i] = std::distance(tempBackward.begin(), it) + 1;
		}
		else{
			tempBackward.push_back(sequence[i]);
			right[i] = tempBackward.size();
		}
	}
	std::reverse(right.begin(), right.end());
	std::reverse(sequence.begin(), sequence.end());
	int max = tempForward.size();
	int max_i = sequence[0];
	if (left[0] + right[1] > max) {
		max = left[0] + right[1];
	}
	for (int i = 1; i < sequence.size() - 1; i++) {
		if (sequence[i] <= max_i)
			continue;
		else {
			for (int j = i; j < sequence.size() - 1; j++) {
				if (left[i] + right[j + 1] > max) {
					max = left[i] + right[j + 1];
				}
			}
			max_i = i;
		}
	}
	out << max;
}