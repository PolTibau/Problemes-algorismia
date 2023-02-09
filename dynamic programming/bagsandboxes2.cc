#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;

VVI CB, SN;
int n, x, y;


ll stirling(int n, int x){
	if(n < x) return 0;
	ll& q = SN[n][x];
	if(q != 0) return q;
	if(n == x) return q = 1;
	if(n == 1) return q = 1;
	return q = stirling(n-1, x-1) + (x)*stirling(n-1, x);
}

ll coef(int n, int y){
	if(n < y) return 0;
	ll& p = CB[n][y];
	if(p != 0) return p;
	if(n == y) return p = 1;
	if(y == 0) return p = 1;
	return p = coef(n-1, y-1) + coef(n-1, y);
	
}

ll prod(int n, int x, int y){
	ll& q = SN[n-y][x];
	if(q == 0) q = stirling(n - y, x);
	ll& p = CB[n][y];
	if(p == 0) p = coef(n, y);
	return p*q;
}


int main(){
	CB = VVI(26, VI(26, 0));
	SN = VVI(27, VI(27, 0));
	SN[0][0] = 1;
	for(int i = 0; i < 26; ++i) SN[i+1][1] = SN[i+1][i+1] = CB[i][0] = CB[i][i] = 1;
	while(cin >> n >> x >> y){
		if(n < x+y) cout << 0 << endl;
		else if(x == 0 and n > y) cout << 0 << endl;
		else cout << prod(n, x, y) << endl;
	}
}
