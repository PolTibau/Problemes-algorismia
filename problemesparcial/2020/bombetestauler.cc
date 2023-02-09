#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VC = vector<char>;
using VVC = vector<VC>;
int n, m;
VVC T;
VI F,C, VALF, VALC;

//turn_on_off conta les maneres de combinar les bombetes complint les restriccions
int turn_on_off(int i, int j){
	if(i == n) return 1;
	if(j == m)return turn_on_off(i+1, 0);
	int p = 0;
	if(T[i][j] != 'O' and  (m-j)+VALF[i] > F[i] and (n-i)+VALC[j] > C[j]){
		p += turn_on_off(i, j+1);
	}
	if(T[i][j] != 'X' and C[j] > VALC[j] and F[i] > VALF[i]){
		VALC[j]++;
		VALF[i]++;	
		p += turn_on_off(i, j+1);
		VALC[j]--;
		VALF[i]--;
	}
	return p;
	
}


int main(){
	while(cin >> n >> m){
		VALF = F = VI(n);
		VALC = C = VI(m);
		T = VVC(n, VC(m));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> T[i][j];
			}
		}
		for(int i = 0; i < n; ++i){
			cin >> F[i];
		}
		for(int j = 0; j < m; ++j){
			cin >> C[j];
		}
		cout << turn_on_off(0,0) << endl;
	}
}
