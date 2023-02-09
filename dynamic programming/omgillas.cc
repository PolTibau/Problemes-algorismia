#include<iostream>
#include<vector>
using namespace std;

int n, c, v;
const int N = 600;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
const VI V{2,3,5,7,11,13,17,19,23,29};
VVVI dp;



	


int main(){
	dp = VVVI(N, VVI(21, VI(10, 0)));
	for(int i = 0; i < 10; ++i) dp[V[i]][1][i] = 1;
	for(int i = 2; i < 21; ++i){
		for(int j = 0; j < N; ++j){
			for(int x = 0; x < 10; ++x){
				for(int y = 0; y <= x; ++y){
					if(j >= V[x]) dp[j][i][x] += dp[j - V[x]][i-1][y];	
				}
			}
		}
	}
	cin >> n;
	while(n--){
		cin >> c >> v;
		int t = 0;
		if(v > 585) cout << 0 << endl;
		else {
			for(int i = 0; i < 10; ++i){
				t += dp[v][c][i];
			}
			cout << t << endl;
		}
	}
}
