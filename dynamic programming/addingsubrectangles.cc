#include<iostream>
#include<vector>
using namespace std;

using rectangle = vector<vector<int> >;

string n;
rectangle R;
int col = 0;
int fila = 0;

bool dins(int i, int j){
	return (i >= 0 and j >= 0 and j < col and i <= fila);
}


int PIE(int fila, int col){
	int sum = 0;
	if(dins(fila-1, col)) sum += R[fila-1][col];
	if(dins(fila, col-1)) sum += R[fila][col-1];
	if(dins(fila-1, col-1)) sum -= R[fila-1][col-1];
	return sum;
}


int assigna_valor(char c){
	int n = c - 'A' + 1;
	return ((n)*(n+1))/2;
	
}

int main(){
	R = rectangle(0, vector<int>(n.size(), 0));
	while(cin >> n){
		if(R.size() == 0){
			col = n.size();
			R = rectangle(500, vector<int>(col, 0));
		}
		int y = 0;
		for(char c: n){
			R[fila][y] = assigna_valor(c);
			R[fila][y] += PIE(fila, y);
			++y;
		}
		++fila;
	}
	for(int i = 0; i < fila; ++i){
		for(int j = 0; j < n.size(); ++j){
			if(j != n.size()-1)cout << R[i][j] << ' ';
			else cout << R[i][j];
		}
		cout << endl;
	}
}
