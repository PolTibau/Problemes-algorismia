#include<iostream>
#include<vector>
#include<string>
using namespace std;

using permutacio = vector<int>;


long long n;
int numxifres;
string m;
bool existeix = false;
permutacio P;

void print(){
	string coma = "";
	cout << n << " = ";
	for(int i = 0; i < m.size(); ++i){
		if(P[i] == 0) cout << m[i];
		else if(P[i] == 1) cout << " + " << m[i];
		coma = " ";
	}
	cout << endl;
}

void f(int k, int suma, int terme){
	if(k == numxifres){
		if(suma+terme == n){
			print();
			existeix = true;
		}
		return;
	}
	int xifra = m[k] - '0';
	if(suma+terme > n)return;
	P[k] = 1;
	f(k+1, suma + terme, xifra);
	P[k] = 0;
	f(k+1, suma, (terme*10)+xifra);
}




int main(){
	while(cin >> n >> m){
		existeix = false;
		numxifres = m.size();
		P = permutacio(numxifres);
		f(1, 0, m[0]- '0');
		if(not existeix) cout << "No solution for " << n << ' ' << m << '.' << endl;
	}
}
