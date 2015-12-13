#include <iostream>
#include <vector>

using namespace std;

int min_val(vector<int> &array) {
	size_t min_index = 0;
	for(size_t i = 0; i != array.size(); ++i)
		min_index = array[min_index] < array[i] ? min_index : i;
	return min_index;
}

int max_val(vector<int> &array) {
	size_t max_index = 0;
	for(size_t i = 0; i != array.size(); ++i)
		max_index = array[max_index] > array[i] ? max_index : i;
	return max_index;
}

vector<int> closest(vector<vector<int>>& array) {
	size_t n = array.size();
	vector<int> index(n);
	vector<int> select(n);
	for(size_t i=0; i!=n; ++i)
		select[i] = array[i][index[i]];
	int max_ret = INT_MAX;
	vector<int> ret;
	while(1) {
		int min_index = min_val(select);
		int max_index = max_val(select);
		if(select[max_index] - select[min_index] < max_ret) {
			max_ret = select[max_index] - select[min_index];
			ret = select;
		}
		index[min_index] ++;
		if(index[min_index] >= array[min_index].size())
			break;
		select[min_index] = array[min_index][index[min_index]];
	}
	return ret;
}

int main() {
	vector<vector<int>> A{{1,4,10},{2,15,20},{10,12}};
	vector<int> ret = closest(A);
	for(size_t i=0; i!=ret.size(); ++i)
		cout << ret[i] << '\n';
	return 0;
}
