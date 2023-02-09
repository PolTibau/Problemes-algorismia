#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
int n, m;
int comp;
int sumcomp;
VVI G;

int donam_un_putu_enter(string c){
	int x = 0;
	for(int i = 0; i < c.size(); ++i){
		x *= 10;
		x += c[i] - '0';
	}
	return x;
}


void dfs(int x, int y) {
    if (0 > x or x >= G.size()) return;
    if (0 > y or y >= G[0].size()) return;
    if (G[x][y] == -1) return;
    comp++;
    sumcomp += G[x][y];
    
    G[x][y] = -1;
    dfs(x+1, y+1);
    dfs(x-1, y+1);
    dfs(x+1, y-1);
    dfs(x-1, y-1);
}


int main(){
	int t;
	cin >> t;
	int i = 1;
	while(i != t+1){
		cin >> n >> m;
		G = VVI(n, VI(m));
		string c;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> c;
				G[i][j] = -1;
				if(c != "X")G[i][j] = donam_un_putu_enter(c);
			}
		}
		int ans = -1;
		bool res = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				sumcomp = 0;
				comp = 0;
				if(G[i][j] != -1){
					dfs(i, j);
					if (ans == -1) {
						if(sumcomp%comp != 0)res = 0;
						else ans = sumcomp/comp;
					}
					else if (sumcomp%comp != 0 or sumcomp/comp != ans) res = 0;
				}
			}
		}
		cout << "Case " << i << ": " << (res ? "yes" : "no") << endl;
		++i;
	}
}
