#include <vector>
#include <fstream>

using namespace std;


int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	vector<int> nums;
	in >> n;
	nums.reserve(n);
	int in_tmp;
	while (in >> in_tmp)
		nums.push_back(in_tmp);

	for (int i = nums.size() - 1; i >= 1; i--) {
		if (nums[i] < nums[i / 2 + (i % 2 ? 0 : -1)]) {
			out << "NO";
			return 0;
		}
	}
	out << "YES";
}