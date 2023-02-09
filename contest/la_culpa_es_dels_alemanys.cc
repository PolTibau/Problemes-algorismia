#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


bool es_quadrat(int n){
	double x = sqrt(n);
	return x == int(x);
}


int main(){
	for(int i = 1; i < 10; ++i){
		for(int j = 1; j < 10; ++j){
			for(int k = 1; k < 10; ++k){
				if(i+j+k < 18 and es_quadrat(i*j*k) and not es_quadrat(k) and i > k+1 and j < k-1) cout << k << endl;
			}
		}
	}
}
