#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;
VVC G;
VVI M;
int n, m;
struct punt{
		int fil, col;
};
queue<punt> Q;

void entra(int i, int j, int dist){
	if(i >= 0 and i < n and j < m and j >= 0 and M[i][j] == 0){
		M[i][j] = dist;
		punt p;
		p.fil = i;
		p.col = j;
		Q.push(p);
	}
}

int tresor(int& dist, int& act){
	if(Q.empty()) return act;
	punt p = Q.front();
	dist = M[p.fil][p.col];
	if(G[p.fil][p.col] == 't'){
		if(dist > act) act = dist;
	}
	Q.pop();
	entra(p.fil+1, p.col, dist+1);
	entra(p.fil-1, p.col, dist+1);
	entra(p.fil, p.col-1, dist+1);
	entra(p.fil, p.col+1, dist+1);
	return tresor(dist, act);
}

int main(){
	cin >> n >> m;
	G = VVC(n, VC(m, 'X'));
	M = VVI(n, VI(m, 0));
	for(int i = 0; i < n; ++i){
		for(int j = 0;j < m; ++j){
			cin >> G[i][j];
			if(G[i][j] == 'X')M[i][j] = -1;
		}
	}
	int f, c;
	cin >> f >> c;
	int dist;
	int act = -1;
	entra(f-1, c-1, 0);
	if(tresor(dist, act) != -1) cout << "distancia maxima: " << act << endl;
	else cout << "no es pot arribar a cap tresor" << endl;
}
