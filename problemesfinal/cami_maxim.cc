#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int cost, origen, dest;
using P = pair<int, int>;
using T = pair<int, P>;
using VT = vector<T>;
using VP = vector<P>;
using VVP = vector<VP>;
using VB = vector<bool>;
VVP G;
VT memo;

T f(int x){
	if(memo[x] != T(-1, P(-1,-1))) return memo[x];
	int cm = 0;
	int dm = x;
	for(auto u : G[x]){
		T aux = f(u.first);
		int costp = aux.first + u.second;
		//cout << aux.first << ' ' << aux.second.first << ' ' << aux.second.second << endl;
		if(costp > cm or (costp == cm and aux.second.second > dm)){
			cm = costp;
			dm = aux.second.second;
		}
	}
	return memo[x] = T(cm, P(x, dm));
}





int main(){
	while(cin >> n >> m){
		G = VVP(n);
		memo = VT(n, T(-1, P(-1, -1)));
		int x,y,c;
		for(int i = 0; i < m; ++i){
			cin >> x >> y >> c;
			G[x].push_back(P(y,c));
		}
		cost = origen = dest = -1;
		T bo = T(cost, P(origen, dest));
		for(int i = 0; i < n; ++i)bo = max(bo, f(i));
		cost = bo.first;
		origen = bo.second.first;
		dest = bo.second.second;
		if(cost < 0) cout << n-1 << ' ' << n-1 << ' ' << 0 << endl;
		else cout << origen << ' ' << dest << ' ' << cost << endl;
	}
}
