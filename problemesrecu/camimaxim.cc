#include<iostream>
#include<vector>
using namespace std;

using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
VVI G;
VI dist, fills;
int n;
int m;

int cami(int i){
	int& act = dist[i];
	int& f = fills[i];
	if(act != -1)return act;
	act = 1;
	for(int y: G[i]){
		int a = cami(y);
		if(a+1 > act){
			act = a+1;
			f = y;
		}
		else if(1+a == act and y > f)f = y;
	}
	return act;
}




int main(){
	while(cin >> n >> m){
		G = VVI(n);
		dist = VI(n, -1);
		fills = VI(n, -1);
		for(int i = 0; i < m; ++i){
			int x, y;
			cin >> x >> y;
			if(x < y)G[x].push_back(y);
			else G[y].push_back(x);
		}
		int maxim = 0;
		int inici = -1;
		for(int i = 0; i < n; ++i){
			if(dist[i] == -1){
				dist[i] = cami(i);
				if(dist[i] >= maxim){
					maxim = dist[i];
					inici = i;
				}
			}
		}
		cout << maxim << " : " << inici;
		while(fills[inici] != -1){
			cout << ' ' << fills[inici];
			inici = fills[inici];
		}
		cout << endl;
	}
}
