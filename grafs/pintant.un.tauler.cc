#include<iostream>
#include<vector>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;
VVC G;

bool pinta_franja(int i, int j, char c){
	if(G[i][j] == '#')return false;
	if(G[i][j] == '.'){
		G[i][j] = c;
		pinta_franja(i+1, j, c);
		pinta_franja(i-1, j, c);
		pinta_franja(i, j+1, c);
		pinta_franja(i, j-1, c);
	}
	return true;
}

int main(){
	int n, m;
	while(cin >> n >> m){
		G = VVC(n, VC(m));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> G[i][j];
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(G[i][j] != '.' and G[i][j] != '#'){
					char c = G[i][j];
					pinta_franja(i+1, j, c);
					pinta_franja(i-1, j, c);
					pinta_franja(i, j+1, c);
					pinta_franja(i, j-1, c);
				}
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cout << G[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}
