#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using P = pair<int, int>;
using T = pair<int, P>;
VVI G;
VVB vist;
int n;

int dijkstra(priority_queue<T>& Q){
	while(not Q.empty()){
		int cost = -Q.top().first;
		int i = Q.top().second.first;
		int j = Q.top().second.second;
		Q.pop();
		if(i == n/2 and j == n/2)return cost;
		if(i+1 < n and not vist[i+1][j]){
			Q.push(T(-cost-G[i+1][j], P(i+1,j)));
			vist[i+1][j] = true;
		}
		if(j+1 < n and not vist[i][j+1]){
			Q.push(T(-cost-G[i][j+1], P(i,j+1)));
			vist[i][j+1] = true;
		}
		if(i-1 >= 0 and not vist[i-1][j]){
			Q.push(T(-cost-G[i-1][j], P(i-1,j)));
			vist[i-1][j] = true;
		}
		if(j-1 >= 0 and not vist[i][j-1]){
			Q.push(T(-cost-G[i][j-1], P(i,j-1)));
			vist[i][j-1] = true;
		}
	}
	return -1;
}


int main(){
	while(cin >> n){
		priority_queue<T> Q;
		vist = VVB(n, VB(n, false));
		G = VVI(n, VI(n));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> G[i][j];
				if(j == 0 or i == 0 or j == n-1 or i == n-1){
					Q.push(T(-G[i][j],P(i,j)));
					vist[i][j] = true;
				}
			}
		}
		cout << dijkstra(Q) << endl;
	}
}
