#include<iostream>
#include<vector>
using namespace std;

int n;
using VI = vector<int>;
using VB = vector<bool>;
int inici;
VI P;
VB C, Pos;

void print(){
	cout << '(';
	string coma = "";
	for(int i = 0; i < n; ++i){
		cout << (P[i]+1);
		if(i != n-1) cout << ",";
	}
	cout << ')' << endl;
}



void one_cicle(int i, int compte){
	if(compte > n) return;
	if(i == inici and compte == n){
		return print();
	}
	if(P[i] != -1){
		if(Pos[i])return one_cicle(P[i], compte+1);
		return;
	}
	for(int j = 0; j < n; ++j){
		if(not C[j]){
			C[j] = true;
			P[i] = j;
			one_cicle(P[i], compte+1);
			P[i] = -1;
			C[j] = false;
		}
	}
}

int main(){
	cin >> n;
	P = VI(n);
	C = Pos = VB(n, false);
	int valor;
	inici = -1;
	for(int i = 0; i < n; ++i){
		cin >> valor;
		if(valor == 0 and inici == -1) inici = i;
		P[i] = valor-1;
		if(P[i] >= 0){
			C[P[i]] = true;
			Pos[i] = true;
		}
	}
	for(int i = 0; i < n; ++i){
		if(not C[i]){
			C[i] = true;
			P[inici] = i;
			one_cicle(P[inici], 1);
			P[inici] = -1;
			C[i] = false;
		}
	}
	if(inici == -1){
		print();
	}
}
