#include<iostream>
#include<vector>
using namespace std;


int n, m, c;
using ll = long long;
using VB = vector<bool>;
using VVB = vector<VB>;
VVB T;
int total;

void fent_de_paleta(int i, int j){
	if(j > m or i > n) return;
	if(i == n){
		total++;
		return;
	}
	if(j == m) return fent_de_paleta(i+1, 0);
	if(T[i][j]) return fent_de_paleta(i, j+1);
	if(j+1 < m and not T[i][j+1]){
		T[i][j] = T[i][j+1] = true;
		fent_de_paleta(i,j+2);
		T[i][j] = T[i][j+1] = false;
	}
	if(i+1 < n and not T[i+1][j]){
		T[i][j] = T[i+1][j] = true;
		fent_de_paleta(i, j+1);
		T[i][j] = T[i+1][j] = false;
	}
}


int main(){
	while(cin >> n >> m >> c){
		T = VVB(n, VB(m, false));
		int posx, posy;
		for(int i = 0; i < c; ++i){
			cin >> posx >> posy;
			T[posx][posy] = true;
		}
		total = 0;
		fent_de_paleta(0, 0);
		cout << total << endl;
	}
}
