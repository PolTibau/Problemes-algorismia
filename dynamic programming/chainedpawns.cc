#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;
VVI T;
int r, c;


ll chained_pawns(int i, int j){
	if(j == c or j == -1) return 0; 
	ll& q = T[i][j];
	if(q != -1) return q;
	if(i == r-1) return q = 1;
	return q = chained_pawns(i+1, j-1) + chained_pawns(i+1, j+1);
}


int main(){
	while(cin >> r >> c){
		T = VVI(r, VI(c, -1));
		ll suma = 0;
		for(int i = 0; i < c; ++i){
			suma += chained_pawns(0, i);
		}
		cout << suma << endl;
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				cout << T[i][j] << ' ';
			}
			cout << endl;
		}
	}
}
