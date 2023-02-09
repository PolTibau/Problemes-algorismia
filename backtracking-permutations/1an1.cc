#include<iostream>
#include<vector>
using namespace std;

using control = vector<bool>;
using conjunt = vector<int>;

int n;
control C;
conjunt P;

void print(){
	cout << '(';
	string coma = "";
	for(int i = 0; i < n; ++i){
		cout << coma << P[i]+1;
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
	C = control(n, false);
	P = conjunt(n);
	f(0);
}
