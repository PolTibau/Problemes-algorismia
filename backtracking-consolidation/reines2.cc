#include<iostream>
#include<vector>
using namespace std;

using control = vector<bool>;
using tauler = vector<vector<char> >;

int n, compte;
tauler T;
control C, DD, DI;

void print(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << T[i][j];
		}
		cout << endl;
	}
	cout << endl;
}




void f(int m){
	if(m == n)return print();
	for(int i = 0; i < n; ++i){
		if(C[i] == false and DD[i+m] == false and DI[m+n-1-i] == false){
			C[i] = DD[i+m] = DI[m+n-1-i] = true;
			T[m][i] = 'Q';
			f(m+1);
			T[m][i] = '.';
			C[i] = DD[i+m] = DI[m+n-1-i] = false;
		}
	}
}


int main(){
	cin >> n;
	T = tauler(n,vector<char>(n, '.'));
	C = control(n);
	DD = control(2*n-1);
	DI = control(2*n-1);
	f(0);
}


