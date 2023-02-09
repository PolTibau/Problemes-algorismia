#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;


using PQ = priority_queue<pair<int, pair<int, int>>>;
using P = pair<int, pair<int,int>>;
// P ens guarda per cada node el cost fins ell i el darrer node que el porta a ell
using D = pair<int, int>;
using VP = vector<D>;
using VVP = vector<VP>;

const int INF = 1e9;
int ini, fin;
VVP G;
VP v;
bool trobat;

void dijkstra(PQ& q){
	while(not q.empty()){
		P tupla = q.top();
		q.pop();
		int cost = -tupla.first;
		int node = tupla.second.first;
		int ultim = tupla.second.second;
		if(v[node] == make_pair(INF, -1)){
			v[node] = make_pair(cost, ultim);
			if(node == fin){
				return;
			}
			for(D arc: G[node]){
				q.push(make_pair(-arc.second-cost, make_pair(arc.first, node)));
			}
		}
	}
}




int main(){
  int n, m;
  while(cin >> n >> m){
	G = VVP(n);
	while (m--) {
		int x, y, c;
		cin >> x >> y >> c;
		G[x].push_back(make_pair(y, c));
	}
	cin >> ini >> fin;
	v = VP(n, make_pair(INF, -1));
	PQ q;
	trobat = false;
	q.push(make_pair(0, make_pair(ini,ini)));
	dijkstra(q);
	if(v[fin].first == INF)cout << "no path from " << ini <<  " to " <<  fin << endl;
	else{
		stack<int> pila;
		int aux = fin;
		while(aux != ini){
			pila.push(aux);
			aux = v[aux].second;
		}
		cout << ini;
		while(not pila.empty()){
			cout << ' ' << pila.top();
			pila.pop();
		}
		cout << endl;
	}
  }
}
  
