#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;
using VVI = vector<VI>;
using VVB = vector<VB>;
int n;
VVI S, T;
VVB C;

void print(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << T[i][j] << ' ';
		}
		cout << endl;
	}
}

bool adapta(int fila, int inv, int inv_inv){
	for(int i = 0; i <= fila; ++i){
		cout << fila << ' ' << inv << ' ' << inv_inv << endl;
		if(inv != S[i][2] or inv_inv != S[i][3])return false;
	}
	return true;
}

void completa(int i, int j, int r, int l){
	if(i == n)return print();
	if(j == n){
		for(int x = 0; x < n; ++x)cout << T[i][x] << ' ';
		cout << endl;
		if(not adapta(i, r, l))return;
		else return completa(i+1, 0, 0, 0);
	}
	int inv = 0;
	int inv_inv = n-1;
	for(int k = 1; k <= n; ++k){
		if(not C[i][k-1]){
				C[i][k-1] = true;
				C[k-1][i] = true;
				T[i][j] = k;
				completa(i, j+1, r+inv, l-inv_inv);
				C[i][k-1] = false;
				C[k-1][i] = false;
				++inv;
				--inv_inv;
		}
	}
}



int main(){
	cin >> n;
	C = VVB(n, VB(n, false));
	T = VVI(n, VI(n -1));
	S = VVI(n, VI(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 4; ++j)cin >> S[i][j];
	}
	completa(0, 0, 0, 0);
	cout << "--------------------" << endl;
}
