#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
int z, u, k;
VVVI dp;
vector<ll> E;



// rec(k, i, j): el nombre de sequencies de Z-I 0s, U-J 1s i que son k mod 3
ll rec(int k, int i, int j){
	if(i > z or j > u) return 0;
	if(i == z){
		int par = u-j;
		if(par%2 == 1) k++;
		if(k%3 == 0) return 1;
		else return 0;
	}
	if(j == u){
		if(k%3 == 0) return 1;
		else return 0;
	}
	ll& q = dp[k][i][j];
	if(q == -1){
		q = rec((2*k + 1)%3, i, j+1);
		q += rec((2*k)%3, i+1, j);
	}
	return q;
}



int main(){
	dp = VVVI(3, VVI(31, VI(31, -1)));
	while(cin >> z >> u){
		dp = VVVI(3, VVI(31, VI(31, -1)));
		if(z == 0 and u == 0)cout << 1 << endl;
		else cout << rec(0, 1, 0) + rec(1 , 0, 1) << endl;
	}
}
