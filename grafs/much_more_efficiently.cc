#include<iostream>
#include<vector>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


typedef vector<int> VI;
typedef vector<VI> VVI;
using VB = vector<bool>;


int n, m;
VVI G;
VI V;
VB Vist;
bool bi;


void dfs(int u) {
  if(Vist[u])return;
	Vist[u] = true;
	for(int v: G[u]){
		dfs(v);
	}
}

bool connex(){
	Vist = VB(n, false);
	dfs(0);
	for(bool b: Vist){
		if(not b)return false;
	}
  return true;
}

void verifica(int i, int sub){
	for(int u: G[i]){
		if(V[u] == -1){
			V[u] = sub^1;
			verifica(u, (sub^1));
		}
		else if(V[u] != (sub^1))bi = false;
	}
}


bool bipartit() {
  V = VI(n, -1);
	V[0] = 1;
	bi = true;
	verifica(0, 1);
  return bi;
}


int main() {
  while (cin >> n >> m) {
    G = VVI(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
			G[y].push_back(x);
    }
    if (not connex()) cout << "NC" << endl;
    else if (bipartit()) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
