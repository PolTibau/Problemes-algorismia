#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
int n, m;
VVI M;
VVI memo;

//retorna el nombre maxim de monedes que podem aconseguir des de la casella i,j;
int recorrer(int i, int j){
	if(j < 0 or j == m)return 0;
	int& q = memo[i][j];
	if(q != -1)return q;
	if(i == n-1)return q = M[i][j];
	return q = M[i][j] + max(recorrer(i+1, j+1), max(recorrer(i+1, j-1), recorrer(i+1, j)));
}



int main(){
	while(cin >> n >> m){
		char c;
		M = VVI(n, VI(m, 0));
		memo = VVI(n, VI(m, -1));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> c;
				if(c != '.')M[i][j] = c - '0';
			}
		}
		int minim = 0;
		for(int i = 0; i < m; ++i){
			int t = recorrer(0, i);
			minim = max(t, minim);
		}
		cout << minim << endl;
	}
}
