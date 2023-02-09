#include<vector>
#include<iostream>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;
VVC G;
VVB M1, M2;
int n, m;

int recull_alfil(int i, int j){
	if(i < 0 or i >= n or j < 0 or j >= m)return 0;
	if(M1[i][j]) return 0;
	M1[i][j] = true;
	int c = 0;
	if(G[i][j] != 'K' and G[i][j] != 'B' and G[i][j] != '.'){
		c+= G[i][j] - '0';
		G[i][j] = '.';
	}
	return c += recull_alfil(i+1, j+1) + recull_alfil(i+1, j-1) + recull_alfil(i-1, j-1) + recull_alfil(i-1,j+1);
}

int recull_cavall(int i, int j){
	if(i < 0 or i >= n or j < 0 or j >= m)return 0;
	if(M2[i][j]) return 0;
	M2[i][j] = true;
	int c = 0;
	if(G[i][j] != 'K' and G[i][j] != 'B' and G[i][j] != '.'){
		c+= G[i][j] - '0';
		G[i][j] = '.';
	}
	c += recull_cavall(i+2, j+1) + recull_cavall(i+2, j-1) + recull_cavall(i-2, j-1) + recull_cavall(i-2,j+1);
	c += recull_cavall(i+1, j+2) + recull_cavall(i+1, j-2) + recull_cavall(i-1, j+2) + recull_cavall(i-1,j-2);
	return c;
}


int main(){
	while(cin >> n >> m){
		G = VVC(n, VC(m, '.'));
		M1 = M2 = VVB(n, VB(m, false));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> G[i][j];
				if(G[i][j] == 'T')M1[i][j] = M2[i][j] = true;
			}
		}
		int monedes = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(G[i][j] == 'B'){
					monedes += recull_alfil(i, j);
				}
				if(G[i][j] == 'K'){
					monedes += recull_cavall(i, j);
				}
			}
		}
		cout << monedes << endl;
	}
}
