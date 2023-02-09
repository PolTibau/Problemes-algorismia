#include<iostream>
#include<vector>
using namespace std;

int n, c;
using VI = vector<int>;
using VB = vector<bool>;
VI C;
VB B;

void print(){
	cout << '(';
	for(int i = 0; i < n; ++i){
		cout << C[i]+1;
		if(i != n-1) cout << ", ";
	}
	cout << ')' << endl;
}


void f(int i, int ini, int caselles, int cicles){
	if(i == ini){
		int k = 0;
		while(k < n and C[k] != -1)++k;
		i = ini = k;
		cicles--;
	}
	if(cicles == 0 and caselles == 0) return print();
	if(caselles - cicles < 0)return;
	for(int m = 0; m < n; ++m){
		if(not B[m]){
			B[m] = true;
			C[i] = m;
			f(C[i], ini, caselles-1, cicles);
			C[i] = -1;
			B[m] = false;
		}
	}
}


int main(){
	cin >> n >> c;
	C = VI(n, -1);
	B = VB(n, false);
	for(int i = 0; i < n; ++i){
		B[i] = true;
		C[0] = i;
		f(i,0,n-1,c);
		C[0] = -1;
		B[i] = false;
	}
}
