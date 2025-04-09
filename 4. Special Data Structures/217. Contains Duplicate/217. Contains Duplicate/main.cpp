#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


bool containsDuplicate(vector<int>& nums) {
	unordered_set<int> numsSet;
	for (int i = 0; i < nums.size(); i++) {
		if (numsSet.contains(nums[i]))
			return true;
		numsSet.insert(nums[i]);
	}
	return false;
}

int main() {
	vector<int> nums;
	int tmp;
	while (cin >> tmp)
		nums.push_back(tmp);
	cout << containsDuplicate(nums);
}