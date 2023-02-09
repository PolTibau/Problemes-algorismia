#include<iostream>
#include<vector>
using namespace std;

using paraula = vector<char>;
paraula P, X;
int n, v, x;

bool es_vocal(char c){
	if(c == 'a' or c == 'e' or c == 'o' or c == 'i' or c == 'u') return true;
	return false;
}

void print(){
	for(int i = 0; i < n; ++i){
		cout << P[i];
	}
	cout << endl;
}

void biblio(int llarg, int vocals){
	if(n - llarg - (v - vocals) > v - vocals + 1) return;
	else if(v - vocals > n - llarg) return;
	else if(llarg == n and vocals == v){
		print();
		return;
	}
	else{
		for(int i = 0; i < x; ++i){
			if(es_vocal(X[i]) and vocals < v){
				P[llarg] = X[i];
				biblio(llarg+1, vocals+1);
			}
			else if(not es_vocal(X[i]) and (llarg == 0 or es_vocal(P[llarg-1]))){
				P[llarg] = X[i];
				biblio(llarg+1, vocals);
			}
		}
	}
}

int main(){
	cin >> n >> v >> x; 
	P = paraula(n, '.');
	X = paraula(x);
	for(int i = 0; i < x; ++i){
		X[i] = 'a' + i;
	}
	int vocals = 0;
	if(v >= n/2) biblio(0, vocals);
}
