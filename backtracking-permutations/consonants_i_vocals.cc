#include<iostream>
#include<vector>
using namespace std;

using paraula = vector<char>;
using control = vector<bool>;

int n;
paraula V, C, P;
control VF, CF;


void print(){
	for(int i = 0; i < 2*n; ++i)cout << P[i];
	cout << endl;
}


void f(int m){
	if(m == 2*n) return print();
	if(m%2 == 0){
		for(int i = 0; i < n; ++i){
			if(CF[i] == false){
				CF[i] = true;
				P[m] = C[i];
				f(m+1);
				CF[i] = false;
			}
		}
	}
	else{
		for(int j = 0; j < n; ++j){
			if(VF[j] == false){
				VF[j] = true;
				P[m] = V[j];
				f(m+1);
				VF[j] = false;
			}
		}
	}
}



int main(){
	cin >> n;
	VF = control(n, false);
	CF = control(n, false);
	C = paraula(n);
	for(int i = 0; i < n; ++i)cin >> C[i];
	V = paraula(n);
	for(int i = 0; i < n; ++i)cin >> V[i];
	P = paraula(2*n);
	f(0);
}
