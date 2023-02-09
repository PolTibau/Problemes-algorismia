#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using VI = vector<int>;
VI M, memo;
int c, n;

int canvi(int c){
	if(c == 0) return 0;
	if(c < memo[0]){
		if(c >= 1) return memo[c] = 10001;
		else return 10001;
	}
	int& q = memo[c];
	if(q == -1) return 10001;
	if(q != 0) return q;
	
	for(int i = n-1; i >= 0; --i){
		if(i == n-1) q = 1 + canvi(c-M[i]);
		else q = min(q, 1 + canvi(c-M[i]));
	}
	return q;
}

int main(){
	while(cin >> c >> n){
		M = VI(n);
		for(int i = 0; i < M.size(); ++i)cin >> M[i];
		sort(M.begin(), M.end());
		int p = c+1;
		memo = VI(p);
		if(canvi(c) >= 10001) cout << "no" << endl;
		else cout << canvi(c) << endl;
	}
}
