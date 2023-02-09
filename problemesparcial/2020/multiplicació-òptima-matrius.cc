#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
int n, m;
VVL memo;
VI M;


ll f(int i, int d){
    if(i == d) return memo[i][d] = 0;
	ll& q = memo[i][d];
	if(q != -1) return q;
	for(int k = i; k < d; ++k){
		if(q == -1) q = f(i,k) + f(k+1,d) + M[i]*M[k+1]*M[d+1];
		q = min(q, f(i,k) + f(k+1, d) + M[i]*M[k+1]*M[d+1]);
	}
	return q;
}


int main(){
	while(cin >> n){
		memo = VVL(n, VL(n, -1));
		M = VI(n+1);
		for(int i = 0; i < n+1; ++i)cin >> M[i];
		cout << f(0,n-1) << endl;
	}
}
