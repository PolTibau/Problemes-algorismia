#include<iostream>
#include<vector>
using namespace std;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
int n;
VVVL R;

ll rec(bool ultim, int k, int n){
	if(n == 0){
		return 1;
	}
	ll& q = R[ultim][k][n];
	if(q == -1){
		q = rec(not ultim, 1, n-1);
		if(k == 1 and ultim == true) q += rec(ultim, k+1, n-1);
	}
	return q;
}


int main(){
	R = VVVL(2, VVL(3, VL(151, -1)));
	while(cin >> n){
		if(n == 0) cout << 1 << endl;
		else if(n == 1) cout << 2 << endl;
		else cout << rec(false, 1, n) + rec(true, 2, n) << endl;
	}
}
