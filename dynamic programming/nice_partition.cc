#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;

int n;
const int N = 30001;
const int M = 1e8+7;

VI P;

int main(){
	P = VI(N, 0);
	P[0] = 1;
	for(int x = 2; x < N; ++x){
		for(int i = x; i < N; ++i){
			P[i] += P[i-x];
			if(P[i] >= M) P[i] -= M;
		}
	}
	while(cin >> n){
		if(n == 1) cout << 0 << endl;
		else cout << P[n]-1 << endl;
	}
}
