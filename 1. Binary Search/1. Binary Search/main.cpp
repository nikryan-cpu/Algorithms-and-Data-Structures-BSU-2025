#include <iostream>
#include <vector>

int lower_bound(std::vector<int>& nums, int x, int left, int right) {
	if (nums.size() == 0)
		return nums.size();
	while (left < right) {
		int mid = (right + left) / 2;
		if (x <= nums[mid])
			right = mid;
		else if (x > nums[mid])
			left = mid + 1;
	}
	if (left == nums.size())
		return nums.size();
	else if (x != nums[left])
		return -1;
	else
		return left;
}


int upper_bound(std::vector<int>& nums, int x, int left, int right) {
	if (nums.size() == 0)
		return nums.size();
	while (left < right) {
		int mid = (right + left) / 2;
		if (x < nums[mid])
			right = mid;
		else if (x >= nums[mid])
			left = mid + 1;
	}
	if (left >= nums.size())
		return nums.size();
	return left;
}

int main() {
	int size;
	std::cin >> size;
	std::vector<int> nums(size);

	for (int i = 0; i < size; i++) {
		std::cin >> nums[i];
	}
	int amount;
	int x;
	std::cin >> amount;
	for (int i = 0; i < amount; i++) {
		std::cin >> x;
		int index_lower = lower_bound(nums, x, 0, size);
		int index_upper = upper_bound(nums, x, 0, size);
		
		if (index_lower == size) {
			std::cout << 0 << ' ' << nums.size() << ' ' << nums.size() << '\n';
			continue;
		}
		else if (index_lower == -1) {
			std::cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
			continue;
		}
		else
			std::cout << 1 << ' ';
		std::cout << index_lower << ' ' << index_upper << '\n';
	}

}