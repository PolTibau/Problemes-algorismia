#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
using VB = vector<bool>;
using VVB = vector<VB>;
using VI = vector<int>;
struct roca{
	double x, y, r;
};
using VR = vector<roca>;
int n;
double m;


void entra(queue<int>& Q, VI& D, int i, int dist){
	if(D[i] == -1){
		Q.push(i);
		D[i] = dist;
	}
}


int salta(queue<int>& Q, VI& D, VVB& C){
	if(Q.empty()) return 0;
	int act = Q.front();
	Q.pop();
	if(act == n-1)return D[act];
	for(int k = 0; k < n; ++k){
		if(C[act][k]) entra(Q, D, k, D[act]+1);
	}
	return salta(Q, D, C);
}

int main(){
	while(cin >> n >> m){
		VR R(n);
		VVB C(n, VB(n, false));
		VI D(n, -1);
		for(int i = 0; i < n; ++i)cin >> R[i].x >> R[i].y >> R[i].r;
		for(int i = 0; i < n; ++i) for(int j = 0; j < i; ++j){
			if(sqrt((R[j].x - R[i].x)*(R[j].x - R[i].x) + (R[j].y - R[i].y)*(R[j].y - R[i].y)) - (R[i].r + R[j].r) <= m) C[i][j] = C[j][i] = true;
		}
		queue<int> Q;
		entra(Q, D, 0, 0);
		int minim = salta(Q, D, C);
		if(minim == 0) cout << "Xof!" << endl;
		else cout << minim << endl;
	}
}
