#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;

VVI CB, SN;
int n, x, y;

CB = SN = VVI(26, VI(26, -1));


int main(){
	CB = SN = VVI(26, VI(26, -1));
	for(int i = 0; i < 26; ++i) SN[i][0] = SN[i][i] = CB[i][0] = CB[i][i] = 1;
	for(int i = 1; i < 26; ++i){
		for(int j = 1; j < i; ++j){
			SN[i][j] = SN[i-1][j-1] + (j+1)*SN[i-1][j];
			CB[i][j] = CB[i-1][j] + CB[i-1][j-1];
		}
	}
	for(int i = 0; i < 26; ++i){
		for(int j = 0; j < i+1; ++j){
			cout << SN[i][j] << ' ';		
		}
		cout << endl;
	}
	while(cin >> n >> x >> y){
		if(y == 0) cout << SN[n-1][x-1] << endl;
		else if(x == 0) cout << CB[n-1][y-1] << endl;
		else cout << CB[n-1][y-1] * SN[n-1-y][x-1] << endl;
	}
}
