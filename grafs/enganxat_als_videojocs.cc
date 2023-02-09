#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VI = vector<int>;
using VVI = vector<VI>;
using P = pair<pair<int, int>, pair<int,int>>;
int n, m;
VVI G;

int main(){
	int t;
	cin >> t;
	for(int l = 1; l <= t; ++l){
		cout << "#" << l << ": ";
		cin >> n >> m;
		G = VVI(n, VI(m, -1));
		int inii, inij;
		char c;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> c;
				if(c == 'I'){
					inii = i;
					inij = j;
					G[i][j] = 0;
				}
				else if(c == 'F')G[i][j] = -2;
				else if(c == 'W')G[i][j] = 3;
				else if(c == 'S')G[i][j] = 2;
				else if(c == 'N')G[i][j] = 0;
				else if(c == 'E')G[i][j] = 1;
			}
		}
		queue<P> Q;
		int temps = 0;
		Q.push({{inii, inij}, {0,0}}); //guardem la posicio, el temps, i l'espera;
		VVVB vist(n, VVB(m, VB(4, false)));
		while(not Q.empty() and not temps){
			int x = Q.front().first.first;
			int y = Q.front().first.second;
			int t = Q.front().second.first;
			int w = Q.front().second.second;
			Q.pop();
			if(not vist[x][y][t%4]){
				vist[x][y][t%4] = true;
				if(G[x][y] != -2){
					if(w < 3)Q.push({{x,y},{t+1, w+1}});
					if(x-1 >= 0 and (G[x][y]+t%4)%4 == 0 and G[x-1][y] != -1)Q.push({{x-1,y},{t+1, 0}});
					if(x+1 < n and (G[x][y]+t%4)%4 == 2 and G[x+1][y] != -1)Q.push({{x+1,y},{t+1, 0}});
					if(y-1 >= 0 and (G[x][y]+t%4)%4 == 3 and G[x][y-1] != -1)Q.push({{x,y-1},{t+1, 0}});
					if(y+1 < m and (G[x][y]+t%4)%4 == 1 and G[x][y+1] != -1)Q.push({{x,y+1},{t+1, 0}});
				}
				else temps = t;
			}
		}
		if(temps == 0)cout << "impossible" << endl;
		else cout << temps << endl;
	}
}
