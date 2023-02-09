#include<iostream>
#include<vector>
using namespace std;

using Taulell = vector<vector<char> >;
using lletres = vector<bool>;

int n, m;
char c = 'a';
Taulell T;

void print(){
	for(int t = 0; t < n; ++t){
		for(int s = 0; s < m; ++s){
			cout << T[t][s];
		}
		cout << endl;
	}
	cout << endl;
}

void omple(int i, int j, char c){
	if(i == n){
		print();
		return;
	}
	if(j == m) return omple(i+1, 0, c);
	if(T[i][j] != '.') return omple(i, j+1, c);
	else{
		if(j+1 < m and T[i][j+1] == '.'){
			T[i][j] = T[i][j+1] = c;
			omple(i, j+2, c+1);
			T[i][j] = T[i][j+1] = '.';
		}
		if(i+1 < n){
			T[i][j] = T[i+1][j] = c;
			omple(i, j+1, c+1);
			T[i][j] = T[i+1][j] = '.';
		}
	}
}


int main(){
	cin >> n >> m;
	T = Taulell(n, vector<char>(m, '.'));
	omple(0, 0, 'a');
}
