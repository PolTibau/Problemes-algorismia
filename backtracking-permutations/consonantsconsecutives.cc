#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
using lletres = vector<char>;
using control = vector<bool>;
using crea = vector<int>;
lletres L;
control C;
crea Paraula;

bool es_vocal(char c){
	if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') return true;
	return false;
}

void escriu(){
	for(int i = 0; i < n; ++i){
		cout << L[Paraula[i]];
	}
	cout << endl;
}



void f(int i){
	if(i == n){
		escriu();
		return;
	}
	for(int x = 0; x < n; ++x){
		if(C[x] == false){
			Paraula[i] = x;
			C[x] = true;
			if(es_vocal(L[Paraula[i]]))f(i+1);
			else if(i == 0 or es_vocal(L[Paraula[i-1]]))f(i+1);
			C[x] = false;
		}
	}
}

int main(){
	cin >> n;
	C = control(n, false);
	L = lletres(n);
	Paraula = crea(n);
	for(int i = 0; i < n; ++i) cin >> L[i];
	sort(L.begin(), L.end());
	f(0);
}
