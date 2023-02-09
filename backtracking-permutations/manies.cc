#include<iostream>
#include<vector>
#include<string>
using namespace std;

using manies = vector<vector<int> >;
using persones = vector<string>;
using usat = vector<bool>;


int n;
manies M, quadre;
vector<int> S;
persones P;
usat U;


void print(int& compteminim){
	cout << compteminim << endl;
	string coma = "";
	for(int i = 0; i < n; ++i){
		int pos = quadre[quadre.size()-1][i];
		cout << coma << P[pos];
		coma = " ";
	}
	cout << endl;
}


void f(int m, int compte, int& compteminim){
	if(m == n){
		if(compteminim == 0 or compte < compteminim){
			compteminim = compte;
			quadre.push_back(S);
		}
		return;
	}
	if(compteminim != 0 and compte > compteminim)return;
	for(int x = 1; x < n; ++x){
		if(U[x] == false){
			U[x] = true;
			S[m] = x;
			f(m+1, compte + M[S[m-1]][x], compteminim);
			U[x] = false;
		}
	}
}



int main(){
	while(cin >> n){
		P = persones(n);
		for(int i = 0; i < n; ++i){
			cin >> P[i];
		}
		M = manies(n, vector<int>(n));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> M[i][j];
			}
		}
		S = vector<int>(n, 0);
		U = usat(n, false);
		U[0] = true;
		int compteminim = 0;
		f(1, 0, compteminim);
		print(compteminim);
	}
}
