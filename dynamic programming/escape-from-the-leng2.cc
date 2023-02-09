#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
int L, R, C;
int fi, ij;

VVI mapa;
VVVI memo;

VI X = {-2,-2,-2,-2,-2, -1,-1,-1,-1,-1, 0,0,0,0,0, 1,1,1,1,1, 2,2,2,2,2};
VI Y = {-2,-1,0,1,2, -2,-1,0,1,2, -2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2};

// precondicio a x,y hi ha un O
void marca_perill(int x, int y){
	for (int i=0; i<25; i++) {
		int xn = x + X[i];
		int yn = y + Y[i];
		if (0 <= xn and xn < R and 0 <= yn and yn < C) {
			mapa[xn][yn] = 1;
		}
	}
}



int escape(int i, int j, int l){
	//cout << i << " " << j << " " << l << endl; 
	if(i >= R or j >= C or j < 0 or l > L) return 0;
	
	ll& q = memo[i][j][l];
	if(q != -1) return q;
	
	if(mapa[i][j] == 1) return q = 0;
	if(i == R-1 and j == fi) return q = 1;
	
	q = escape(i+1, j, l);
	bool acaba = false;
	for (int k=j+1;l < L and k < C; k++) {
		if (mapa[i][k] == 1) acaba = true;
		if (not acaba) {
			if (i == R-1 and k == fi) q += 1;
			q += escape(i+1, k, l+1);
		}
	}
	acaba = false;
	for (int k=j-1; l < L and k >= 0; k--) {
		if (mapa[i][k] == 1) acaba = true;
		if (not acaba) {
			if (i == R-1 and k == fi) q += 1;
			q += escape(i+1, k, l+1);
		}
	}
	return q;
}


int main(){
	while(cin >> R >> C >> L and (R != 0 or C != 0 or L != 0)){
		memo = VVVI(R, VVI(C, VI(L+1, -1)));
		mapa = VVI(R, VI(C, 0));

		char c;
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				cin >> c;
				if(c == 'O'){
					mapa[i][j] = 1;
					marca_perill(i, j);
				}
				else if(c == 'D'){
					ij = j;
				}
				else if(c == 'P'){
					fi = j;
				}
			}
		}
		/*for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				cout << mapa[i][j];
			}
			cout << endl;
		}
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				for (int l=0; l < L; l++) {
					cout << memo[i][j][l];
					cout << " ";
				}
				cout << ", ";
			}
			cout << endl;
		}*/
		int maneres = escape(0, ij, 0);
		if(maneres == 0) cout << "Good bye, Professor Dyer!" << endl;
		else cout << maneres << endl;
	}
}
