#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
int n, m;
VI deg;
VVI G, C;
VB vist;
VB nostres;

void separa_components(int i){
	if(vist[i])return;
	vist[i] = true;
	nostres[i] = true;
	for(int u: G[i]){
		separa_components(u);
	}
}

VI construeix(){
	VI comp(0);
	for(int i = 0; i < n; ++i){
		if(nostres[i])comp.push_back(deg[i]);
	}
	sort(comp.begin(), comp.end());
	return comp;
}

bool es_isomorf(VI& A, VI& B){
	if(A.size() != B.size())return false;
	for(int i = 0; i < A.size(); ++i){
		if(A[i] != B[i]) return false;
	}
	return true;
}



int main(){
	while(cin >> n >> m){
		G = VVI(n);
		deg = VI(n, 0);
		int u, v;
		while(m--){
			cin >> u >> v;
			deg[u]++;
			deg[v]++;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		C = VVI(0);
		vist = VB(n, false);
		for(int i = 0; i < n; ++i){
			if(not vist[i]){
				nostres = VB(n, false);
				separa_components(i);
				C.push_back(construeix());
			}
		}
		int compte = 0;
		for(int i = 0; i < C.size(); ++i){
			for(int j = i+1; j < C.size(); ++j){
				if(es_isomorf(C[i], C[j]))++compte;
			}
		}
		cout << compte << endl;
	}
}
