#include<iostream>
#include<vector>
using namespace std;

int n, m, k;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
VVI T,
VVVI V;


//retorna el cost minim d'anar fins la fila i;
int f(int i, int j, int cav){
	if(i == n-1) return T[i][j];
	int& q = V[i][j][k];
	if(q != -1) return q;
	q = 1e8;
	if(j+1 < m) q = min(q, f(i+1,j+1, cav) + T[i+1][j+1]);
	if(j-1 >= 0) q = min(q, f(i+1,j-1, cav) + T[i+1][j-1]);
	if(i+2 < n and j+1 < m and cav > 0) q = min(q, f(i+2, j+1, cav-1) + T[i+2][j+1]);
	if(i+2 < n and j-1 >= 0 and cav > 0) q = min(q, f(i+2, j-1, cav-1) + T[i+2][j-1]);
	if(j+2 < m and cav > 0) q = min(q, f(i+1, j+2, cav-1) + T[i+1][j+2]);
	if(j-2 >= 0 and cav > 0) q = min(q, f(i+1,j-2,cav-1) + T[i+1][j-2]);
	return q = min(q, f(i+1, j, cav) + T[i+1][j]);
}



int main(){
	while(cin >> n >> m >> k){
		T =  VVI(n, VI(m));
		V = VVVI(n, VVI(m, VI(k, -1)));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> T[i][j];
				V[i][j] = -1;
			}
		}
		int minim = 1e8;
		for(int i = 0; i < m; ++i){
			minim = min(minim, (f(0, i, k) + T[0][i]));
			
		}
		cout << minim << endl;
	}
}
