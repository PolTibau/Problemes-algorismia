#include<iostream>
#include<vector>
using namespace std;

int n, k, m;
using VI = vector<int>;
using VB = vector<bool>;
VI P;
VB C;

void print(){
	string coma = "";
	for(int i = 0; i < n; ++i){
		cout << coma << P[i];
		coma = " ";
	}
	cout << endl;
}


void busca_les_lletges(int i, int p){
	if(i == n and p == k)return print();
	if(p > k or p + (n-i) < k)return;
	if(P[i] != -1){
		if(i != 0 and (P[i] - P[i-1] == 1 or P[i] - P[i-1] == -1)) return busca_les_lletges(i+1, p+1);
		return busca_les_lletges(i+1, p);
	}
	for(int k = 0; k < n; ++k){
		if(not C[k]){
			C[k] = true;
			P[i] = k;
			if(i != 0 and (P[i] - P[i-1] == 1 or P[i] - P[i-1] == -1))busca_les_lletges(i+1, p+1);
			else busca_les_lletges(i+1, p);
			C[k] = false;
			P[i] = -1;
		}
	}
}



int main(){
	while(cin >> n >> k >> m){
		P = VI(n, -1);
		C = VB(n, false);
		int pos, valor;
		for(int i = 0; i < m; ++i){
			cin >> pos >> valor;
			P[pos] = valor;
			C[valor] = true;
		}
		busca_les_lletges(0, 0);
		cout << "********************" << endl;
	}
}
