#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    if(nums.size() <= 1)
        return vector<int>(0);
        
    int n = nums.size();
    vector<int> rightNums, ret(n);
    for(int i=n-1; i>=0; --i) {
        if(rightNums.empty()) {
            rightNums.push_back(nums[i]);
            ret[i] = 0;
        } else {
            auto iter = lower_bound(rightNums.begin(), rightNums.end(), nums[i]);
            ret[i] = iter - rightNums.begin();
            
            if(*iter != nums[i]) {
                rightNums.push_back(0);
                for(int j=rightNums.size()-2; j>=ret[i]; --j)
                    rightNums[j+1] = rightNums[j];
                rightNums[ret[i]] = nums[i];
            }
        }
        for(int j=0; j!=rightNums.size(); j++)
        	cout << rightNums[j] << ' ';
        cout << '\n';
    }
    return ret;
}

int main() {
	vector<int> A{26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
	auto ret = countSmaller(A);
	for(int i=0; i!=ret.size(); ++i)
		cout << ret[i] << '\t';
	return 0;
}
