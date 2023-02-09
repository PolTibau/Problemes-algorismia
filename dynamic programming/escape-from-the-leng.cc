#include<iostream>
#include<vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
int L, R, C;
int fi, fj, ii, ij;
VVI M;





int escape(int i, int j, int l, bool esq, bool dret){
	if(i >= R or j >= C or j < 0 or l > L) return 0;
	if(i == R-1 and j == fi) return 1;
	int& q = M[i][j];
	if(q == -2) return 0;
	if(q != -1) return q;
	if(dret) return q = escape(i, j+1, l, false, true) + escape(i+1, j, l, false, false);
	if(esq) return q = escape(i, j-1, l, true, false) + escape(i+1, j, l, false, false);
	return q = escape(i+1, j, l, false, false) + escape(i, j-1, l+1, true, false) + escape(i, j+1, l+1, false, true);
}


int main(){
	while(cin >> R >> C >> L){
		M = VVI(R, VI(C, -1));
		char c;
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				cin >> c;
				if(c == 'O'){
					M[i][j] = -2;
					marca_perill(i, j);
				}
				else if(c == 'D'){
					ij = j;
				}
				else if(c == 'P'){
					fi = j;
				}
			}
		}
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				cout << M[i][j] << ' ';
			}
			cout << endl;
		}
		int maneres = escape(0, ij, 0, false, false);
		if(maneres == 0) cout << "Good bye, Professor Dyer!" << endl;
		else cout << maneres << endl;
				for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				cout << M[i][j] << ' ';
			}
			cout << endl;
		}
		cout << ij << endl;
	}
}
