#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using P = pair<int, int>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VI = vector<int>;
using VVI = vector<VI>;
VVI G;
VVB Vist;
int n, m;


bool lliure(int x, int y){
	queue<P> Q;
	Q.push(P(x,y));
	while(not Q.empty()){
		int i = Q.front().first;
		int j = Q.front().second;
		Q.pop();
		if(G[i][j] == 1)return true;
		if(i+1 < n and not Vist[i+1][j] and G[i+1][j] >= 0){
			Vist[i+1][j] = true;
			Q.push(P(i+1, j));
		}
		if(i-1 > -1 and not Vist[i-1][j] and G[i-1][j] >= 0){
			Vist[i-1][j] = true;
			Q.push(P(i-1, j));
		}
		if(j+1 < m and not Vist[i][j+1] and G[i][j+1] >= 0){
			Vist[i][j+1] = true;
			Q.push(P(i, j+1));
		}
		if(j-1 > -1 and not Vist[i][j-1] and G[i][j-1] >= 0){
			Vist[i][j-1] = true;
			Q.push(P(i,j-1));
		}
	}
	return false;
}


int main(){
	while(cin >> n >> m){
		G = VVI(n, VI(m, 0));
		char c;
		int inii, inij;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> c;
				if(c == 'B'){
					inii = i;
					inij = j;
				}
				else if(c == 'C')G[i][j] = -1;
				else if(c == 'Q')G[i][j] = 1;
			}
		}
		Vist = VVB(n, VB(m, false));
		if(lliure(inii, inij))cout << "aquesta nit hi haura passio" << endl;
		else cout << "aquesta nit hi haura pau" << endl;
	}
}
