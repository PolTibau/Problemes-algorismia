#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
int m, n;
VI B, A, CS;


int common_scores(int k){
	int res = 0;
	for(int i = n-1; i > -1; --i){
		if(A[i] == B[k]){
			CS[i] = 1;
			int t = 0;
			for(int s = i-1; s >= 0; --s){
				t = max(CS[s], t);
			}
			CS[i] += t;
			res = max(CS[i], res);
		}
	}
	return res;
}



int main(){
	while(cin >> m >> n){
		B = VI(m);
		A = VI(n);
		CS = VI(n, 0);
		for(int i = 0; i < m; ++i){
			cin >> B[i];
		}
		for(int j = 0; j < n; ++j){
			cin >> A[j];
		}
		int  t = 0;
		for(int k = 0; k < m; ++k){
			t = max(t, common_scores(k));
		}
		cout << t << endl;
		
	}
}
