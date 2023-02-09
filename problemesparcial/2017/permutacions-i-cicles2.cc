#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e8+7;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
VVL memo;
int n, c;


int main(){
	memo = VVL(1001, VL(1001, 0));
	memo[1][1] = 1;
	for(int i = 2; i < 1001; ++i){
		memo[i][1] = ((i-1)*memo[i-1][1])%MOD;
		for(int j = 2; j <= i; ++j){
			memo[i][j] = (memo[i-1][j-1] + (memo[i-1][j]*(i-1)))%MOD;
		}
	}
	while(cin >> n >> c){
		cout << memo[n][c] << endl;
	}
}
