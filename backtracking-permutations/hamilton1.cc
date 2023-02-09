#include<iostream>
#include<vector>
using namespace std;

int n;
using permutacio = vector<int>;
using graf = vector<permutacio>;
using control = vector<bool>;
control C;
permutacio P;
graf G;

void escriu(int suma){
	for(int i = 0; i < n; ++i){
		cout << P[i] << ' ';
	}
	cout << 0 << " (" << suma << ")" << endl;	
}


void cicle(int i, int suma){
	if(i == n){
		escriu(suma);
		return;
	}
	for(int x = 1; x < n; ++x){
		if(not C[x]){
			if(i < n-1 and G[P[i-1]][x] != 0){
				P[i] = x;
				C[x] = true;
				cicle(i+1, suma+G[P[i-1]][x]);
				C[x] = false;
			}
			if(i == n-1 and G[P[i-1]][x] != 0 and G[x][0] != 0){
				P[i] = x;
				C[x] = true;
				cicle(i+1, suma+G[P[i-1]][x]+G[x][0]);
				C[x] = false;
			}
		}
	}
}


int main(){
	while(cin >> n){
		G = graf(n, permutacio(n));
		P = permutacio(n);
		P[0] = 0;
		C = control(n, false);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> G[i][j];
			}
		}
		int suma = 0;
		cicle(1, suma);		
		cout << "--------------------" << endl;
	}

}
