#include<iostream>
#include<vector>
using namespace std;

using peses = vector<int>;
using control = vector<bool> ;

int n;
int maneres = 0;
peses P;
control C;

void repartiment(int x, int esquerra, int dreta){
	if(dreta > esquerra) return;
	else if(x == n){
		maneres++;
		return;
	}
	for(int i = 0; i < n; ++i){
		if(not C[i] and dreta+P[i] <= esquerra){
			C[i] = true;
			repartiment(x+1, esquerra, dreta+P[i]);
			C[i] = false;
		}
		if(not C[i]){
			C[i] = true;
			repartiment(x+1, esquerra+P[i], dreta);
			C[i] = false;
		}
	}
}


int main(){
	while(cin >> n){
		P = peses(n);
		for(int i = 0; i < n; ++i) cin >> P[i];
		C = control(n);
		int dreta = 0;
		int esquerra = 0;
		repartiment(0, esquerra, dreta);
		cout << maneres << endl;
		maneres = 0;
	}
}
