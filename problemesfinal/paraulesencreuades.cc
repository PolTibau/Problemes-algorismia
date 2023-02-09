#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

using VB = vector<bool>;
using VS = vector<string>;
VS V;
int n;





void combina(VB& vist, VS& T, int t){
	VB vist2 = vist;
	for(int i = 0; i < n; ++i){
		int co = -1;
		for(int j = 0; j < 2*n; ++j){
			if(not vist2[j]){
				bool compleix = true;
				for(int k = 0; k < t; ++k)if(T[i][k] != V[j][k])compleix = false;
				if(compleix) co = j;
			}
		}
		if(co == -1)return;
		else vist2[co] = true;
	}
	if(t == n){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cout << T[j][i];
			}
			cout << endl;
		}
		cout << endl;
	}
	for(int i = 0; i < 2*n; ++i){
		if(not vist[i]){
			vist[i] = true;
			for(int j = 0; j < n; ++j)T[j][t] = V[i][j];
			combina(vist,T,t+1);
			vist[i] = false;
		}
	}
}


int main(){
	while(cin >> n){
		V = VS(2*n);
		for(auto& x: V)cin >> x;
		sort(V.begin(), V.end());
		
		VB vist(2*n, false);
		VS T(n, string(n,'?'));
		combina(vist, T, 0);
		cout << "----------" << endl;
	}
}
