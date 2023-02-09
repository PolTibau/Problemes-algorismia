#include<iostream>
#include<vector>
using namespace std;

int n, r;
using VB = vector<bool>;
using VI = vector<int>;
using VVI = vector<VI>;
int total;
VVI R;
VI C;


void valor(int i, int suma, int prohibit){
	if(i == n){
		if(suma == 0)total++;
		return;
	}
	if(C[i] != -1) return valor(i+1, (suma*10+C[i])%7, C[i]);
	for(int k = 0; k < 10; ++k){
		if(k != prohibit and (i+1 >= n or C[i+1] != k)){
			C[i] = k;
			valor(i+1, (suma*10+k)%7,  k);
			C[i] = -1;
		}
	}
}



//C1 ens marca per quins digits tenim restriccions

int main(){
	while(cin >> n >> r){
		total = 0;
		C = VI(n , -1);
		for(int i = 0; i < r; ++i){
			int pos, valor;
			cin >> pos >> valor;
			C[pos] = valor;
		}
		valor(0, 0, -1);
		cout << total << endl;
	}
}
