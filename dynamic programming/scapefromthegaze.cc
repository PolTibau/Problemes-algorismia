#include<iostream>
#include<vector>
using namespace std;

int n, m;
using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;
VVC L;
VVI R;

int cerca_camins(int i, int j){
	if(i >= n or j >= m) return 0;
	if(L[i][j] == 'X') return R[i][j] = 0;
	if(i == n-1 and j == m-1) return 1;
	int& q = R[i][j];
	if(q != -1) return R[i][j];
	q = cerca_camins(i+1, j) + cerca_camins(i, j+1);
	if(q > 1e6) q = 1e7;
	return q;
}

int main(){
	while(cin >> n >> m and (n != 0 or m != 0)){
		L = VVC(n, VC(m));
		R = VVI(n, VI(m, -1));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> L[i][j];
			}
		}
		int t = cerca_camins(0, 0);
		if(t >= 1e6) cout << "!!!" << endl;
		else cout << t << endl;
	}
}
