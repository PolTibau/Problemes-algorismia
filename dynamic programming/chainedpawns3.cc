#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
VVVI T;
int r, c;

int main(){
	T = VVVI(50, VVI(50, VI(50, 0)));
	for(int i = 0; i < 50; ++i){
		for(int j = 0; j < 50; ++j) T[0][j][i] = 1;
	}
	while(cin >> r >> c){
		if(T[r-1][c-1][c-1] == 0){
			int inici = -1;
			for(int k = r-2; inici == -1 and k >= 0; --k){
				if(T[k][c-1][c-1] != 0) inici = k;
			}
			for(int i = inici+1; i < r; ++i){
				for(int j = 0; j < c; ++j){
					if(j == 0) T[i][j][c-1] = T[i-1][j+1][c-1];
					else if(j == c-1) T[i][j][c-1] = T[i-1][j-1][c-1];
					else T[i][j][c-1] = T[i-1][j-1][c-1] + T[i-1][j+1][c-1];
				}
			}
		}
		if(r == 1) cout << c << endl;
		else if(c == 1) cout << 0 << endl;
		else{
			ll suma = 0;
			for(int i = 0; i < c; ++i){
				suma += T[r-1][i][c-1];
			}
			cout << suma << endl;
		}
	}
}
