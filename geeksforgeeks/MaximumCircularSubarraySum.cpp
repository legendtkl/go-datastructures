/* Discription: Given n numbers (both positve and negative), arranged in a 
 * circle, find the maximum sum of consecutive number.
 *
 * Examples:
 * Input: a[] = {8,-8,9,-9,10,-11,12}
 * Output: 22 (12+8-8+9-9+10)
 *
 * Input: a[] = {10, -3,-4, 7, 6, 5, -4, -1}
 * Output: 23 (7+6+5-4-1+10)
 *
 * Solution: think reverse. Namely, from end to start, compute a max value
 * and from start to end, compute a max value, add them.
 *
 * reference: http://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
 */
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int maximum_circular_subarray_sum(vector<int>& nums){
	int n = nums.size();
	vector<int> sum(n), resum(n);

	int pre = nums[0], max_val = nums[0];
	for(int i=1; i!=n; ++i){
		if(pre+nums[i] < nums[i]){
			pre = nums[i];
		}else{
			pre = pre+nums[i];
		}
		max_val = max(max_val, pre);
	}

	int ret = nums[0];
	pre = nums[0];
	sum[0] = nums[0];
	for(int i=1; i!=n; ++i){
		pre = pre+nums[i];
		ret = max(ret, pre);
		sum[i] = ret;
	}
	ret = nums[n-1];
	pre = nums[n-1];
	resum[n-1] = nums[n-1];
	for(int i=n-2; i>=0; --i){
		pre = pre+nums[i];
		ret = max(ret, pre);
		resum[i] = ret;
	}
	/*
	for(int i=0; i<n; ++i)
		printf("%d\t", sum[i]);
	printf("\n");
	for(int i=0; i<n; ++i)
		printf("%d\t", start_pos[i]);
	printf("\n");
	pre = 0;
	*/
	max_val = max(max_val, max(sum[n-1], resum[0]));
	for(int i=0; i<n-1; i++){
		max_val = max(max_val, sum[i]+resum[i+1]);
	}
	return max_val;
}

int main(){
	vector<int> nums{-1,40,-14,7,6,5,-4,-1};
	int ret = maximum_circular_subarray_sum(nums);
	printf("%d\n", ret);
	return 0;
}
