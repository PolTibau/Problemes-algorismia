#include<iostream>
#include<vector>
using namespace std;


int g, n;
using VI = vector<int>;
using VVI = vector<VI>;
VI E;
VVI memo1, memo2;


int f1(int i, int j);


int f2(int i, int j){
	if(j == -1) return 0;
	int& q = memo2[i][j];
	if(i == 0) return q = 0;
	if(q != -1) return q;
	int x = 1;
	if(j == n-1) x = 0;
	return q = max(f1(i-1, j-1) + E[j] + x*E[j+1]/2, f2(i, j-1));
}


int f1(int i, int j){
	if(j == -1) return 0;
	int& q = memo1[i][j];
	if(q != -1) return q;
	if(i == 0) return q = E[j]/2;
	return q = max(f1(i-1,j-1) + E[j], f2(i, j-1) + E[j]/2);
}

int main(){
	while(cin >> g >> n){
		E = VI(n);
		memo1 = memo2 = VVI(g+1, VI(n, -1));
		for(int i = 0; i < n; ++i) cin >> E[i];
		cout << f2(g, n-1) << endl;
		/*
		for(int i = 0; i < g+1; ++i){
			for(int j= 0; j < n; ++j){
				cout << memo1[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		for(int i = 0; i < g+1; ++i){
			for(int j= 0; j < n; ++j){
				cout << memo2[i][j] << ' ';
			}
			cout << endl;
		}
		*/
	}
}
