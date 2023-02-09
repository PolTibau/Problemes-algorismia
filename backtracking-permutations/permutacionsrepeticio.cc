#include<iostream>
#include<vector>
using namespace std;

using conjunt = vector<int>;
using llibreria = vector<string>;

int n;

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
		P[m] = i;
		f(m+1);
	}
}

int main(){
	cin >> n;
	Q = llibreria(n);
	for(int i = 0; i < n; ++i) cin >> Q[i];

	P = conjunt(n);
	f(0);
}
