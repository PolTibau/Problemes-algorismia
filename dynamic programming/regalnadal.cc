#include<iostream>
#include<vector>
using namespace std;

using bolets = vector<int>;

int n, q;
bolets B, C, P, M;


int main(){
	int compte = 1;
	while(cin >> n){
		M = B = bolets(n);
		int suma = 0;
		for(int i = 0; i < n; ++i){
			cin >> B[i];
			suma += B[i];
			M[i] = suma;
		} 
		cin >> q;
		C = P = bolets(q);
		for(int i = 0; i < q; ++i){
			cin >> P[i];
			cin >> C[i];
		}
		cout << "#" << compte << endl;
		for(int i = 0; i < q; ++i){
			if(P[i] > C[i]){
				int aux = P[i];
				P[i] = C[i];
				C[i] = aux;
			}
			cout << M[C[i]-1] - M[P[i]-1] + B[P[i]-1] << endl;
		} 
		++compte;
	}
}
