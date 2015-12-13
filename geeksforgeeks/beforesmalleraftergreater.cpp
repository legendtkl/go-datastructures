#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int foo(vector<int>& nums) {
	bool exist = true;
	int candidate = 0, leftmax = nums[0];

	for(size_t i=1; i!=nums.size(); ++i) {
		leftmax = max(leftmax, nums[i-1]);
		if(exist == false && nums[i] > leftmax) {
			exist = true;
			candidate = i;
		}
		else if(exist == true && nums[i] <= nums[candidate]) {
			exist = false;
		}
	}

	return exist == true ? candidate : -1;
}

int main() {
	vector<int> nums{5,1,3,6,2,10,15,-2,12,13,14,16,17};
	vector<int> num{5,1,4,4};
	cout << foo(nums) << "\n";
	return 0;
}
