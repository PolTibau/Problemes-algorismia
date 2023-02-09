#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

using VP = vector<pair<int,int>>;
using VVI = vector<vector<int> >;
VVI G;
VP C;


int main(){
	int n, m;
	while(cin >> n >> m){
		if(m == 0) cout << "yes" << endl;
		else{
			queue<pair<int, int> > Q;
			C = VP(n);
			for(int i = 0; i < n; ++i)C[i] = {i, -1};
			G = VVI(n);
			for(int i = 0; i < m; ++i){
				int x, y;
				cin >> x >> y;
				G[x].push_back(y);
				G[y].push_back(x);
			}
			C[0].second = 0;
			Q.push(C[0]);
			bool coloreja = true;
			while(coloreja and not Q.empty()){
				int x = Q.front().first;
				int y = Q.front().second;
				//cout << x << ' ' << y << endl;
				Q.pop();
				if(G[x].size() == 0){
					int seg = -1;
					for(int i = 0; i < n and seg == -1; ++i){
						if(C[i].second == -1)seg = i;
					}
					C[seg].second = 0;
					Q.push(C[seg]);
				}
				else{
					for(int k = 0; k < G[x].size(); ++k){
						if(C[G[x][k]].second == y){
							coloreja = false;
						}
						else if(C[G[x][k]].second == -1){
							if(y == 0) C[G[x][k]].second = 1;
							else C[G[x][k]].second = 0;
							Q.push(C[G[x][k]]);
						}
					}
				}
			}
			if(coloreja) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
}
