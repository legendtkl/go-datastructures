#include <iostream>
#include <vector>

using namespace std;

vector<string> ret;

void DFS(vector<int>& A, int pos, string s) {
	if(pos==A.size()) {
		ret.push_back(s);
		return;
	}
	if(A[pos]==0)
		return;
	DFS(A, pos+1, s+string(1,'a'+A[pos]-1));
	if(pos+1 != A.size() && A[pos]*10+A[pos+1]<=26) {
		DFS(A, pos+2, s+string(1,'a'+A[pos]*10+A[pos+1]-1));
	}
}

int main() {
	vector<int> A{9,1,8};
	DFS(A, 0, "");
	for(size_t i=0; i!=ret.size(); ++i)
		cout << ret[i] << '\n';
	return 0;
}
