#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, inici;
using P = pair<int, int>;
using T = pair<int, P>;
using VI = vector<int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VB = vector<bool>;
VVP G;
VI Par, Dist;
queue<int> Q;

void BFS(){
	while(not Q.empty()){
		int act = Q.front();
		int parades = Par[act];
		int distancia = Dist[act];
		Q.pop();
		for(P carr: G[act]){
			if(Par[carr.first] == parades+1 and distancia+carr.second < Dist[carr.first])Dist[carr.first] = distancia+carr.second;
			else if(Par[carr.first] == -1){
				Par[carr.first] = parades+1;
				Dist[carr.first] = distancia+carr.second;
				Q.push(carr.first);
			}
		}
	}
}



int main(){
	while(cin >> n >> m){
		G = VVP(n);
		Par = Dist = VI(n, -1);
		int x, y, l;
		for(int i = 0; i < m; ++i){
			cin >> x >> y >> l;
			G[x].push_back(P(y, l));
			G[y].push_back(P(x, l));
		}
		cin >> inici;
		Q.push(inici);
		Par[inici] = Dist[inici] = 0;
		BFS();
		for(int i = 0; i < n; ++i){
			if(Par[i] != -1)cout << i << ": " << Par[i] << ' ' << Dist[i] << endl;
			else cout << i << ": no" << endl;
		}
		cout << "----------" << endl;
	}
}
