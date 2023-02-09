// Algorisme de Dijkstra.


#include <iostream>
#include <queue>
#include <vector>
using namespace std;



using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;

const int INF = 1e9;

int main() {
  int n, m;
  while(cin >> n >> m){
	VVP G(n);
	while (m--) {
		int x, y, c;
		cin >> x >> y >> c;
		G[x].push_back(P(c, y));
	}
	int ini, fin;
	cin >> ini >> fin;

	VI dist(n, INF);
	VI pare(n);
	priority_queue<P> Q;
	dist[ini] = 0;
	Q.push(P(0, ini));
	while (not Q.empty()) {
		P p = Q.top(); Q.pop();
		int d = -p.first;
		int x = p.second;
		if (d == dist[x]) {
		for (P arc : G[x]) {
			int c = arc.first;
			int y = arc.second;
			int d2 = d + c;
			if (d2 < dist[y]) {
			dist[y] = d2;
			pare[y] = x;
			Q.push(P(-d2, y));
			}
		}
		}
	}
	if(dist[fin] != INF) cout << dist[fin] << endl;
	else cout << "no path from " << ini <<  " to " <<  fin << endl;
  }
}
  
