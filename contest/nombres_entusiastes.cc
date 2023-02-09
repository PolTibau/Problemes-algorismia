#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VB = vector<bool>;
VI E;
VB divo;

bool divi(int n, int m){
	if(m == 0)return false;
	if(m < 0) return false;
	if(n == 1) return true;
	bool res = divi(n, m-1);
	if(divo[m] and n%E[m] == 0) res = (res or divi(n/E[m], m));
	return res;
}



int main(){
	int n;
	E = VI(13);
	E[0] = 1;
	for(int i = 1; i < 13; ++i)E[i] = E[i-1]*i;
	while(cin >> n){
		divo = VB(13, false);
		int m = -1;
		for(int j = 2; j < 13; ++j){
			if(n%E[j] == 0){
				divo[j] = true;
				m = j;
			}
		}
		if(divi(n, m) or n <= 2) cout << "SI!" << endl;
		else cout << "NO!" << endl;
	}
}
