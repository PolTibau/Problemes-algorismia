#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using P = pair<int,int>;
using VP = vector<P>;
using VB = vector<bool>;
queue<P> Q;
VVI G;
VI deg;
VP dist;
VB vist;
int n;


int troba_minim(){
	while(not Q.empty()){
		int act = Q.front().first;
		int d = Q.front().second;
		Q.pop();
		if(not vist[act]){
			vist[act] = true;
			for(int u: G[act]){
					if(dist[u].second == -1){
						dist[u].first = d;
						dist[u].second = act;
						Q.push(P(u, d));
					}
					else if(dist[u].second != act){
						return d+dist[u].first+1;
					}
			}
		}
	}
	return -1;
}



int main(){
	while(cin >> n){
		deg = VI(n, 0);
		G = VVI(n);
		vist = VB(n, false);
		dist = VP(n, make_pair(-1, -1));
		int x, y;
		for(int i = 0; i < n-1; ++i){
			cin >> x >> y;
			deg[x]++;
			deg[y]++;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		//for(int i = 0; i < n; ++i)cout << deg[i] << ' ';
		cout << endl;
		for(int i = 0; i < n; ++i){
			if(deg[i] == 1){
				dist[i] = make_pair(i, 0);
				Q.push(P(i, 0));
			}
		}
		cout << troba_minim() << endl;
	}
}
