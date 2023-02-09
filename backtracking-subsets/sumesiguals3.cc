#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using conjunt = vector<int>;
using control = vector<bool>;


int s, n;
conjunt C;
control candidat;


void print(){
	cout << "{";
	string coma = "";
	for(int i = n-1; i > -1; --i){
		if(candidat[i] == true){
			cout << coma << C[i];
			coma = ",";
		}
	}
	cout << "}" << endl;
}

void f(int m, int suma, int falta, bool trobat){
	if(trobat == 1)return;
	if(m == -1){
		if(suma == s)print();
		return;
	}
	candidat[m] = true;
	if(suma+C[m] > s) trobat = 1;
	else if(falta < s-suma) trobat = 1;
	f(m-1, suma+C[m], falta - C[m], trobat);
	trobat = 0;
	candidat[m] = false;
	if(falta < s-suma) trobat = 1;
	f(m-1, suma, falta-C[m], trobat);
}


int main(){
	cin >> s >> n;
	C = conjunt(n);
	candidat = control(n);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> C[i];
		sum += C[i];
	}
	sort(C.begin(), C.end());
	bool trobat = 0;
	f(n-1, 0, sum, trobat);
}
