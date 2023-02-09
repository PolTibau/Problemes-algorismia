#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using Catalan_numbers = vector<ll>;
int n;
Catalan_numbers C;

void calcula_catalan(int m, Catalan_numbers& C){
	ll x = 0;
	for(int i = 0; i < m; ++i){
		x += C[i]*C[m-1-i];
	}
	C[m] = x;
}


int main(){
	C = Catalan_numbers(34, 0);
	C[0] = C[1] = 1;
	while(cin >> n){
		if(n%2 == 1) cout << 0 << endl;
		else{
			if(C[n/2] != 0) cout << C[n/2] << endl;
			else{
				ll x = 0;
				for(int i = 0; i < n/2; ++i){
					if(C[i] == 0){
						calcula_catalan(i, C);
					}
				}
				for(int i = 0; i < n/2; ++i){
					x += C[i]*C[n/2-1-i];
				}
				C[n/2] = x;
				cout << C[n/2] << endl;
			}
		}
	}
}
