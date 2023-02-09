#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;

int n, m, k;
VVC M;
VVI R;

int costmin(int x, int y, int z){
	if(x < 0) x = 1e9;
	if(y < 0) y = 1e9;
	if(z < 0) z = 1e9;
	return min(x, min(y,z));
}


int minkeys(int i, int j){
	if(i == m-1){
		if(M[i][j] == 'T') R[i][j] = 3;
		else if(M[i][j] == '.') R[i][j] = 0;
		return R[i][j];
	}
	int& q = R[i][j];
	if(q != -1) return q;
	q = 0;
	if(M[i][j] == 'T') q = 3;
	int op1, op2, op3;
	op1 = op2 = op3 = -10;
	if(M[i+1][j] != '*') op1 = minkeys(i+1, j);
	if(M[i+1][j+1] != '*' and j+1 < n) op2 = minkeys(i+1, j+1);
	if(M[i+1][j-1] != '*' and j-1 >= 0)op3 = minkeys(i+1, j-1);
	return q += costmin(op1, op2+1, op3+1);
}


int main(){
	cin >> n >> m;
	M = VVC(m, VC(n));
	R = VVI(m, VI(n, -1));
	int ii, ij;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cin >> M[i][j];
			if(M[i][j] == 'M'){
				ii = i;
				ij = j;
			}
			
		}
	}
	int cost = minkeys(ii, ij);
	if(cost > 1e8) cout << "IMPOSSIBLE" << endl;
	else cout << cost << endl;
}
