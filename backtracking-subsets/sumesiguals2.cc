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

void f(int m, int suma, bool& trobat){
	if(trobat == 1)return;
	if(m == -1){
		if(suma == s){
			print();
			trobat = 1;
		}
		return;
	}
	candidat[m] = true;
	f(m-1, suma+C[m], trobat);
	candidat[m] = false;
	f(m-1, suma, trobat);
}


int main(){
	cin >> s >> n;
	C = conjunt(n);
	candidat = control(n);
	for(int i = 0; i < n; ++i) cin >> C[i];
	sort(C.begin(), C.end());
	bool trobat = 0;
	f(n-1, 0, trobat);
	if(not trobat) cout << "no solution" << endl;
}
