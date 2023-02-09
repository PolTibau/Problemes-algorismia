#include<iostream>
#include<vector>
using namespace std;

using control = vector<vector<bool> >;
using sudoku = vector<vector<int> >;

int n, buits, possibles;
bool existeix = false;
control C, F, Q; 
sudoku S;

void print(){
	string coma = "";
	int i, j;
	j = i = 0;
	while (i < 9){
		while(j < 9){
			if((i == 3 or i == 6) and j == 0){
				cout <<"------+-------+------" << endl;
				cout << S[i][j] << " ";
				coma = "";
			}
			else if(j == 3 or j == 6){
				cout << " | ";
				cout << S[i][j];
			}
			else{
				cout  << coma << S[i][j];
				coma = " ";
				}
			++j;
		}
		j = 0;
		++i;
		coma = "";
		cout << endl;
	} 
    cout << endl;
}

void busca(int& xmin, int& ymin){
	int minim = 10;
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			if(S[i][j] == 0){
				possibles = 0;
				for(int x = 1; x < 10; ++x){
					if(not C[j][x-1] and not F[i][x-1] and not Q[3*(i/3)+j/3][x-1])possibles++;
				}
				if(possibles < minim){
					minim = possibles;
					xmin = i;
					ymin = j;
				}
			}
		}
	}
}


void f(int k){
	if(existeix == false){
		if(k == buits){
			existeix = true;
			return print();
		}
		int xmin, ymin;
		busca(xmin, ymin);
		for(int i = 1; i < 10; ++i){
			int q = 3*(xmin/3)+ymin/3;
			if(not C[ymin][i-1] and not F[xmin][i-1] and not Q[q][i-1]){
				S[xmin][ymin] = i;
				C[ymin][i-1] = F[xmin][i-1] = Q[q][i-1] = true;
				f(k+1);
				S[xmin][ymin] = 0;
				C[ymin][i-1] = F[xmin][i-1] = Q[q][i-1] = false;
			}
		}
	}

}

int main(){
	cin >> n;
	for(int a = 0; a < n; ++a){
		S = sudoku(9, vector<int>(9));
		C = F = Q = control(9, vector<bool>(9 ,false));
		char c;
		int x, y;
		buits = x = y = 0;
		int i = 0;
		while(i < 81){
			cin >> c;
			if(c != '|' and c != '-' and c != '+'){
				++i;
				S[x][y] = int(c - '0');
				if(S[x][y] == 0)++buits;
				if(S[x][y] != 0){
					C[y][S[x][y]-1] = true;
					F[x][S[x][y]-1] = true;
					Q[(x/3)*3 + y/3][S[x][y]-1] = true;
				}
				if(y == 8){
					++x;
					y = 0;
				}
				else ++y;
			}
		}
		f(0);
		existeix = false;
	}
}
