#include<iostream>
#include<vector>
using namespace std;

using control = vector<vector<bool> >;
using sudoku = vector<vector<int> >;

int n;
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


void f(int x, int y){
	if(x == 9){
		existeix = true;
		return print();
	}
	if(y == 9)return f(x+1, 0);
	if(S[x][y] != 0)return f(x,y+1);
	for(int i = 1; i < 10; ++i){
		int q = 3*(x/3)+y/3;
		if(not C[y][i-1] and not F[x][i-1] and not Q[q][i-1]){
			S[x][y] = i;
			C[y][i-1] = F[x][i-1] = Q[q][i-1] = true;
			f(x, y+1);
			S[x][y] = 0;
			C[y][i-1] = F[x][i-1] = Q[q][i-1] = false;
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
		x = y = 0;
		int i = 0;
		while(i < 81){
			cin >> c;
			if(c != '|' and c != '-' and c != '+'){
				++i;
				S[x][y] = int(c - '0');
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
		f(0, 0);
		if(not existeix) cout << "no solution" << endl;
		existeix = false;
		cout << "******************************" << endl;
	}
}
