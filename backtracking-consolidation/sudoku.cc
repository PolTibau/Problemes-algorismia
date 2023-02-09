#include<iostream>
#include<vector>
using namespace std;

using control = vector<vector<bool> >;
using sudoku = vector<vector<char> >;

int n;
bool trobat = false;
control C, F, Q; 
sudoku S;

void print(){
	string coma = "";
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			cout  << coma << S[i][j];
			coma = " ";
		}
		coma = "";
		cout << endl;
	}
}


void f(int x, int y){
	if(not trobat){
		if(x == 9){
			trobat = true;
			return print();
		}
		if(y == 9)return f(x+1, 0);
		if(S[x][y] != '.')return f(x,y+1);
		for(int i = 1; i < 10; ++i){
			int q = 3*(x/3)+y/3;
			if(not C[y][i-1] and not F[x][i-1] and not Q[q][i-1]){
				S[x][y] = char(i + '0');
				C[y][i-1] = F[x][i-1] = Q[q][i-1] = true;
				f(x, y+1);
				S[x][y] = '.';
				C[y][i-1] = F[x][i-1] = Q[q][i-1] = false;
			}
		}
	}
}

int main(){
	cin >> n;
	cout << n << endl << endl;
	for(int a = 0; a < n; ++a){
		S = sudoku(9, vector<char>(9));
		C = F = Q = control(9, vector<bool>(9 ,false));
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				cin >> S[i][j];
				if(S[i][j] != '.'){
					C[j][int(S[i][j]- '0') -  1] = true;
					F[i][int(S[i][j]- '0') -  1] = true;
					Q[(i/3)*3 + j/3][int(S[i][j]- '0') -  1] = true;
				}
			}
		}
		f(0, 0);
		trobat = false;
		if(a < n-1)cout << endl;
	}
}

