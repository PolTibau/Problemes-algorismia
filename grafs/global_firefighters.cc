#include<iostream>
#include<vector>
#include<queue>
using namespace std;


using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;
int k,n,m;
VVP G;
VP O;
priority_queue<pair<P, int>> I;


int main(){
	int t;
	cin >> t;
	for(int w = 0; w < t; ++w){
		cin >> n >> m;
		G = VVP(n);
		for(int i = 0; i < m; ++i){
			int u, v, d;
			cin >> u >> v >> d;
			G[u].push_back(P(v,d));
			G[v].push_back(P(u,d));
		}
		cin >> k;
		for(int i = 0; i < k; ++i){
			int c;
			cin >> c;
			I.push(make_pair(P(0, -c), c));
		}
		O = VP(n, P(-1, -1));
		while(not I.empty()){
			int pas = -I.top().first.first;
			int origen = -I.top().first.second;
			int city = I.top().second;
			I.pop();
			if(O[city].first == -1){
				O[city].first = pas;
				O[city].second = origen;
				for(auto x: G[city]){
					I.push(make_pair(P(-pas-x.second, -origen), x.first));
				}
			}
		}
		int q;
		cin >> q;
		if(w != 0)cout << endl;
		cout << "Case #" << w+1 << endl;
		for(int i = 0; i < q; ++i){
			int l;
			cin >> l;
			cout << "To get to " << l << ", distance " << O[l].first << ", from city " << O[l].second <<  '.' << endl;
		}
	}
}
