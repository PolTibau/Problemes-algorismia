#include<iostream>
#include<vector>
using namespace std;

using conjunt = vector<int>;
using control = vector<bool>;


int s, n;
conjunt C;
control candidat;


void print(){
	cout << "{";
	string coma = "";
	for(int i = 0; i < n; ++i){
		if(candidat[i] == true){
			cout << coma << C[i];
			coma = ",";
		}
	}
	cout << "}" << endl;
}

void f(int m, int suma){
	if(m == n){
		if(suma == s) print();
		return;
	}
	candidat[m] = false;
	f(m+1, suma);
	candidat[m] = true;
	f(m+1, suma + C[m]);
}


int main(){
	cin >> s >> n;
	C = conjunt(n);
	candidat = control(n);
	for(int i = 0; i < n; ++i) cin >> C[i];
	f(0, 0);
}
