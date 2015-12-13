#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.first > b.second;
}

int main() {
	vector<pair<int,int>> A{pair<int,int>(3,1), pair<int,int>(4,0), pair<int,int>(1,2)};
	make_heap(A.begin(), A.end(), cmp);
	for(int i=0; i!=A.size(); i++) {
		cout << A[i].first << '\t' << A[i].second << '\n';
	}

	pop_heap(A.begin(), A.end());
	A.pop_back();
	for(int i=0; i!=A.size(); i++) {
		cout << A[i].first << '\t' << A[i].second << '\n';
	}
	return 0;
}
