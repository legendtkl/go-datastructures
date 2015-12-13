#include <iostream>
#include <vector>

using namespace std;

int bitDifference(int a, int b) {
	int c = a^b;
	int ret = 0;
	while(c) {
		++ ret;
		c = c & (c-1);
	}
	return ret;
}

int bitDifference(vector<int> A) {
	int ret = 0, n = A.size();
	for(int i=0; i!=n; ++i){
		for(int j=0; j!=n; ++j)
			ret += bitDifference(A[i],A[j]);
	}
	return ret;
}

//way 2
int bitDifference2(vector<int> &A) {
	vector<int> counter(32);
	int n = A.size(), ret = 0;

	for(int i=0; i!=32; ++i){
		int onebit=0;
		for(int j=0; j!=n; ++j)
			if(A[j] & 1<<i)
				++onebit;
		ret += onebit*(n-onebit)*2;
	}
	return ret;
}

int main() {
	vector<int> A{1,3,5};
	cout << bitDifference(A) << '\n';
	return 0;
}
