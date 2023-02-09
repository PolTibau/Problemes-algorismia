#include<iostream>
#include<vector>
using namespace std;

using control = vector<bool>;
using incompatibilitats = vector<control>;
using conjunt1 = vector<char>;
using conjunt2 = vector<int>;

int n, inc;
incompatibilitats I;
conjunt1 C;
conjunt2 P;
control Q;

void print(){
	for(int i = 0; i < n; ++i)cout << C[P[i]];
	cout << endl;
}


void f(int m){
	if(m == n) return print();
	for(int i = 0; i < n; ++i){
		if(not Q[i] and (m == 0 or I[i][P[m-1]])){
				P[m] = i;
				Q[i] = true;
				f(m+1);
				Q[i] = false;
		}
	}
}


void especies(char p, char q){
	int fila, columna;
	for(int i = 0; i < n; ++i){
		if(C[i] == p) fila = i;
		else if(C[i] == q) columna = i;
	}
	I[fila][columna] = false;
	I[columna][fila] = false;

}

int main(){
	cin >> n;
	C = conjunt1(n);
	for(int i = 0; i < n; ++i)cin >> C[i];
	I = incompatibilitats(n, control(n, true));
	cin >> inc;
	char p, q;
	for(int j = 0; j < inc; ++j){
		cin >> p >> q;
		especies(p, q);
	}
	Q = control(n, false);
	P = conjunt2(n);
	f(0);
}
