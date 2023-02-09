#include<iostream>
#include<vector>
using namespace std;

int n, m;
int ii, ij, fi, fj, cost;
using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;
VVB vist;
VVI C;
VVC M;
string s;



void paraulogic(int i, int j, int c){
	if(c > cost)return;
	if(i == fi and j == fj){
		cout << s << endl;
		return;
	}
	if(i+1 < n  and not vist[i+1][j]){
		vist[i+1][j] = true;
		s.push_back(M[i+1][j]);
		paraulogic(i+1, j, c+C[i+1][j]);
		s.pop_back();
		vist[i+1][j] = false;
	}
	if(i-1 >= 0  and not vist[i-1][j]){
		vist[i-1][j] = true;
		s.push_back(M[i-1][j]);
		paraulogic(i-1, j, c+C[i-1][j]);
		s.pop_back();
		vist[i-1][j] = false;
	}
	if(j+1 < m  and not vist[i][j+1]){
		vist[i][j+1] = true;
		s.push_back(M[i][j+1]);
		paraulogic(i, j+1, c+C[i][j+1]);
		s.pop_back();
		vist[i][j+1] = false;
	}
	if(j-1 >= 0  and not vist[i][j-1]){
		vist[i][j-1] = true;
		s.push_back(M[i][j-1]);
		paraulogic(i, j-1, c+C[i][j-1]);
		s.pop_back();
		vist[i][j-1] = false;
	}
}



int main(){
	while(cin >> n >> m){
		M = VVC(n, VC(m));
		C = VVI(n, VI(m));
		vist = VVB(n, VB(m, false));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> M[i][j];
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> C[i][j];
			}
		}
		cin >> ii >> ij >> fi >> fj >> cost;
		vist[ii][ij] = true;
		s = M[ii][ij];
		paraulogic(ii, ij, C[ii][ij]);
	}
}
