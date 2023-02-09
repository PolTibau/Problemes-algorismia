#include<iostream>
#include<vector>
using namespace std;

using VB = vector<bool>;
using VI = vector<int>;
using VVI = vector<VI>;
int n, m;
int maxim;
VVI P;
VB C;

int evalua(int x){
	int suma = 0;
	while(x/10 > 0){
		int y = x%10;
		x/=10;
		int t = x%10;
		suma += P[t-1][y-1];
	}
	return suma;
}


void premi(int x, int i){
	if(x % m == 0)return;
	if(i == n-1){
		maxim = max(evalua(x), maxim);
		return;
	}
	for(int y = 1; y <= n; ++y){
		if(not C[y]){
			C[y] = true;
			premi(x*10 + y, i+1);
			C[y] = false;
		}
	}
}


int main(){
	while(cin >> m >> n){
		P = VVI(n, VI(n));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> P[i][j];
			}
		}
		C = VB(n+1, false);
		maxim = 0;
		for(int k = 1; k <= n; ++k){
			C[k] = true;
			premi(k, 0);
			C[k] = false;
		}
		cout << maxim << endl;
	}
}
