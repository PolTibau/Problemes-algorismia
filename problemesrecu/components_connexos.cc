#include<iostream>
#include<vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
VI pare;

int repre(int u){
	if(pare[u] == u)return u;
	return pare[u] = repre(pare[u]);
}

bool sondifs(int u, int v){
	if(repre(u) == repre(v))return false;
	pare[repre(u)] = repre(v);
	return true;
}


int main(){
	int n, m;
	while(cin >> n >> m){
		pare = VI(n, -1);
		int ini = n;
		for(int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			if(pare[u] == -1 and pare[v] == -1){
				pare[u] = u; //es representa a ell mateix;
				pare[v] = u;
				ini -= 1;
			}
			else if(pare[u] == -1){
				pare[u] = pare[v];
				ini -= 1;
			}
			else if(pare[v] == -1){
				pare[v] = pare[u];
				ini -= 1;
			}
			else if(sondifs(u,v))--ini;
			cout << ini;
			if(i == m-1)cout << endl;
			else cout << ' ';
		}
	}
}
