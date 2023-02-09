#include<iostream>
#include<vector>
using namespace std;

using rectangle = vector< vector<char> >;
using control = vector<bool>;

int f, c;
control C;
rectangle R;

void print(){
	for(int i = 0; i < f; ++i){
		for(int j = 0; j < c; ++j){
			cout << R[i][j];
		}
		cout << endl;
	}
	cout << endl;
}


void q(int x, int y){
	if(x == f)return print();
	for(int i = 0; i < c; ++i){
		if(C[i] == false){
			C[i] = true;
			R[x][i] = 'R';
			q(x+1, 0);
			C[i] = false;
			R[x][i] = '.';
		}
	}
}

int main(){
	cin >> f >> c;
	C = control(c, false);
	R = rectangle(f, vector<char>(c));
	for(int i = 0; i < f; ++i){
		for(int j = 0; j < c; ++j){
			R[i][j] = '.';
		}
	}
	q(0, 0);
}
