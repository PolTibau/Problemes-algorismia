#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
VVI G;
VI grau, comb;
int n;

void print(){
	string sp = "";
	for(int i = 0; i < n; ++i){
		cout << sp << comb[i];
		sp = " ";
	}
	cout << endl;
}

void f(int k){
	if(k == n) return print();
	for(int i = 0; i < n; ++i){
		if(grau[i] == 0){
			grau[i] = -1;
			comb[k] = i; 
			for(int y: G[i])--grau[y];
			f(k+1);
			grau[i] = 0;
			for(int y: G[i])++grau[y];
		}
	}
}


int main(){
    int m;
    cin >> n >> m;
	G = VVI(n);
	comb = grau = VI(n, 0);
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		++grau[y];
	}
	f(0);
}

