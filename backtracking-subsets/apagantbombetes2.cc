#include<iostream>
using namespace std;
#include<vector>

using sala = vector<vector<char> >;
int n, m;
sala S;
bool trobat = false;
int prem = -1;

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

void apaga_encen(int i, int j, int& suma){
	if(trobat and suma >= prem) return;
	if(fosc()){
		trobat = true;
		prem = suma;
	}
	if((i > 0 and j > 1 and S[i-1][j-2] == '*') or (i == n-1 and j > 1 and S[i][j-2] == '*'))return;
	else if(i < n){
		if(j < m){
			canvia_interruptors(i,j);
			suma++;
			apaga_encen(i, j+1, suma);
			suma--;
			canvia_interruptors(i,j);
			apaga_encen(i,j+1, suma);
		}
		else{
			j = 0;
			++i;
			apaga_encen(i,j,suma);
		}
	}
}


int main(){
	while(cin >> n >> m){
		S = sala(n, vector<char>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; ++j){
				cin >> S[i][j];
			}
		}
		int suma = 0;
		apaga_encen(0,0,suma);
		if(prem == -1) cout << "no" << endl;
		else cout << prem << endl;
		prem = -1;
		trobat = false;
	}
}
