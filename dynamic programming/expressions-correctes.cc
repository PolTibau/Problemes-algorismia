#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using espai = vector<ll>;

const int MIDA = 26;
espai V;
int n, m;


ll comb(int n){
	if(V[n] != 0) return V[n];
	if(n == 1){
		V[n] = m;
		return m;
	}
	if(n == 0) return 0;
	V[n] = comb(n-2);
	if(n - 5 > 0){
		int i = 1;
		int j = n-5-i;
		while(i < n-5 and j > 0){
			V[n] += comb(i)*comb(j);
			i += 2;
			j -= 2;
		}
	}
	return V[n];
}


int main(){
	while(cin >> n >> m){
		if(n %2 == 0) cout << 0 << endl;
		else {
			V = espai(MIDA, 0);
			cout << comb(n) << endl;
			
		}
	}
}
