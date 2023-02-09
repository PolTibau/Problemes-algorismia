#include<iostream>
#include<vector>
using namespace std;

using control = vector<bool>;
using conjunt = vector<int>;
using llibreria = vector<string>;

int n;
control C;
conjunt P;
llibreria Q;

void print(){
	cout << '(';
	string coma = "";
	for(int i = 0; i < n; ++i){
		cout << coma << Q[P[i]];
		coma = ",";
	}
	cout << ')' << endl;
}


void f(int m){
	if(m == n) return print();
	for(int i = 0; i < n; ++i){
		if(C[i] == false){
			C[i] = true;
			P[m] = i;
			f(m+1);
			C[i] = false;
		}
	}
}

int main(){
	cin >> n;
	Q = llibreria(n);
	for(int i = 0; i < n; ++i) cin >> Q[i];
	C = control(n, false);
	P = conjunt(n);
	f(0);
}
