#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e8+7;
int n, a, b, c;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VVVVI = vector<VVVI>;
VVVVI memo;


int f(int n, int a, int b, int c){
	if(a < 0 or b < 0 or c < 0) return 0;
	if(n == 0) return 1;
	int& q = memo[n][a][b][c];
	if(q != -1) return q;
	return q = (f(n-1, a, b, c-1)%MOD + f(n-1, a, b-1, c)%MOD + f(n-1, a-1, b, c)%MOD)%MOD;
}


int main(){
	memo = VVVVI(51, (VVVI(51, VVI(51, VI(51, -1)))));
	for(int i = 0; i < 51; ++i){
		memo[i][0][0][i] = memo[i][i][0][0] = memo[i][0][i][0] = 1;
	}
	while(cin >> n >> a >> b >> c){
		cout << f(n, a, b, c) << endl;
	}
}
