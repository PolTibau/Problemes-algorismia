#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;
VVI T;

int main(){
	T = VVI(51, VI(51, 0));
	for(int i = 0; i < 51; ++i) T[50][i] = 1;
	for(int i = 0; i < 51; ++i) T[i][0] = 1;
	for(int i = 49; i >= 0; --i){
		for(int j = 0; j < 51; ++j){
			if(j == 0) T[i][j] = T[i+1][j+1];
			else if(j == 50) T[i][j] = T[i+1][j-1];
			else T[i][j] = T[i+1][j+1] + T[i+1][j-1];
		}
	}
	int r, c;
	while(cin >> r >> c){
			ll suma = 0;
			if(r == 1) cout << c << endl;
			else if(c == 1) cout << 0 << endl;
			else if(c == 2) cout << 2 << endl;
			else{
				for(int x = 0; x < c/2; ++x){
					suma += T[51-r][x] + T[51-r][50-x];
				}
				if(c%2 == 1) suma += 2*T[51-r+1][c/2-1];
				cout << suma << endl;
			}
	}
}
