#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VVVVI = vector<VVVI>;
VVVVI dp;
int z, u;
bool ultim;


ll rec(bool ultim, int k, int i, int j){
	if(i < 0 or j < 0){
		return 0;
	}
	if(i == 0 and j == 0){
		return 1;
	}
	ll& q = dp[ultim][k][i][j];
	if(q == -1){
		if(ultim == 1){
			q = rec(not ultim, 1, i-1, j);
			if(k == 1) q += rec(ultim, k+1, i, j-1);
		}
		else q = rec(not ultim, 1, i, j-1);
	}
	return q;
}


int main(){
	dp = VVVVI(2, VVVI(3, VVI(91, VI(91, -1))));
	while(cin >> z >> u){
		if(z == 0 and u == 0) cout << 1 << endl;
		else cout << rec(0, 1, z-1, u) + rec(1, 1, z, u-1) << endl;
	}
}
