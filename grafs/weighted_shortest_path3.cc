#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using P = pair<int, int>;
using T = pair<P, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using PQ = priority_queue<T>;
VVP G;
VP v;
//v es un vector de pairs que ens guarda per cada noda la distancia de cost i en passos al vertex inicial;
//la cua PQ ens guarda el <cost, node, steps fins el node>
int n, m, ini, fin;
const int INF = 1e9;


void dijkstra(PQ& q){
	while(not q.empty()){
		T tupla = q.top();
		q.pop();
		int cost = -tupla.first.first;
		int node = tupla.second;
		int pas = -tupla.first.second;
		if(v[node] == make_pair(INF, -1)){
			v[node] = make_pair(cost, pas);
			for(P arc: G[node]){
				q.push(T(P(-arc.second-cost,-pas-1), arc.first));
			}
		}
	}
}



int main(){
	while(cin >> n >> m){
		G = VVP(n);
		int u, t, c;
		while(m--){
			 cin >> u >> t >> c;
			 G[u].push_back(make_pair(t,c));
		}
		cin >> ini >> fin;
		v = VP(n, P(INF, -1));
		PQ q;
		q.push(T(P(0, 0), ini));
		dijkstra(q);
		if(v[fin].first == INF) cout << "no path from " << ini << " to " << fin << endl;
		else cout << "cost " << v[fin].first << ", " << v[fin].second << " step(s)" << endl;
	}
}
