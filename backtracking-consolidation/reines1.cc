#include<iostream>
#include<vector>
using namespace std;

using control = vector<bool>;


int n, compte;
control C, DD, DI;


void f(int m, int& compte){
	if(m == n){
		compte++;
		return;
	}
	for(int i = 0; i < n; ++i){
		if(C[i] == false and DD[i+m] == false and DI[m+n-1-i] == false){
			C[i] = DD[i+m] = DI[m+n-1-i] = true;
			f(m+1, compte);
			C[i] = DD[i+m] = DI[m+n-1-i] = false;
		}
	}
}


int main(){
	cin >> n;
	compte = 0;
	C = control(n);
	DD = control(2*n-1);
	DI = control(2*n-1);
	f(0,compte);
	cout << compte << endl;
}


