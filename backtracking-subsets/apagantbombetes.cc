#include<iostream>
using namespace std;
#include<vector>

using sala = vector<vector<char> >;
int n, m;
sala S;
bool trobat = false;

bool fosc(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(S[i][j] == '*') return false;
		}
	}
	return true;
}

void canvia_interruptors(int i, int j){
	if(S[i][j] == '*') S[i][j] = '.';
	else S[i][j] = '*';
	if(i > 0){
		if(S[i-1][j] == '*') S[i-1][j] = '.';
		else S[i-1][j] = '*';
		if(j > 0){
			if(S[i-1][j-1] == '*') S[i-1][j-1] = '.';
			else S[i-1][j-1] = '*';
		}
	}
	if(j > 0){
		if(S[i][j-1] == '*') S[i][j-1] = '.';
		else S[i][j-1] = '*';
		if(i < n-1){
			if(S[i+1][j-1] == '*') S[i+1][j-1] = '.';
			else S[i+1][j-1] = '*';	
		}
	}
	if(i < n-1){
		if(S[i+1][j] == '*') S[i+1][j] = '.';
		else S[i+1][j] = '*';	
		if(j < m-1){
			if(S[i+1][j+1] == '*') S[i+1][j+1] = '.';
			else S[i+1][j+1] = '*';
		}
	}
	if(j < m-1){
		if(S[i][j+1] == '*') S[i][j+1] = '.';
		else S[i][j+1] = '*';
		if(i > 0){
			if(S[i-1][j+1] == '*') S[i-1][j+1] = '.';
			else S[i-1][j+1] = '*';
		}
	}
}


int apaga_encen(int i, int j, int& suma){
	cout << i << ' ' << j << ' ' << suma << endl;
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; ++y){
			cout << S[x][y];
		}
		cout << endl;
	}
	if(fosc()){
		trobat = true;
		return suma;
	}
	else {
		if(i < n){
			if(j < m){
				if(not trobat){
					canvia_interruptors(i,j);
					++suma;
				}
				apaga_encen(i,j+1,suma);
				
				if(not trobat){
					--suma;
					canvia_interruptors(i,j);
				}
				apaga_encen(i, j+1, suma);
			}
			else{
				++i;
				j = 0;
				apaga_encen(i,j,suma);
			}
		}
	}
	if(trobat) return suma;
	return -1;
}





int main(){
	while(cin >> n >> m){
		int suma  = 0;
		S = sala(n, vector<char>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; ++j){
				cin >> S[i][j];
			}
		}
		int res = apaga_encen(0,0,suma); 
		if(res == -1) cout << "no" << endl;
		else cout << res << endl;
		trobat = false;
	}
}

