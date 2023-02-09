#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, c, m;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
VB amo;
VVI G, I;
VI vertex, repre, vist, numrepre, vi; 
int ind = 0;

void drink(int i){
	if(vi[i])return;
	vi[i] = true;
	for(int u: I[i])drink(u);
}


void dfs1(int i){
	if(vist[i])return;
	vist[i] = true;
	for(int u: I[i])dfs1(u);
	vertex[ind++] = i;
}


void dfs2(int x, int r){
	if(repre[x] != -1)return;
	repre[x] = r;
	numrepre[r]++;
	for(int y: G[x])dfs2(y,r);
}

int main(){
	int t = 0;
	while(cin >> n >> c){
		cout << "Case #" << ++t << ": ";
		I = G = VVI(n);
		amo = VB(n, false);
		int a;
		for(int i = 0; i < c; ++i){
			cin >> a;
			amo[a] = true;
		}
		cin >> m;
		int u,v;
		for(int i = 0; i < m; ++i){
			cin >> u >> v;
			G[u].push_back(v);
			I[v].push_back(u);
		}
		vi = VI(n, false);
		for(int i = 0; i < n; ++i){
			if(amo[i])drink(i);
		}
		numrepre = vist = vertex = VI(n);
		for(int x = 0; x < n; ++x)dfs1(x);
		repre = VI(n, -1);
		int compte = 0;
		for(int i = n-1; i >= 0; --i){
			int k = vertex[i];
			if(repre[k] == -1 and not vi[k]){
				dfs2(k, k);
				compte+=(numrepre[k]*(numrepre[k]-1));
			}
		}
		cout << compte << endl;
		ind = 0;
	}
}
