#include<iostream>
#include<cmath>
using namespace std;


bool es_primer(int n){
	for(int i = 2; i <= sqrt(n); ++i){
		if(n%i == 0)return false;
	}
	return true;
}

bool aritmetic(double i,double j,double k){
	return k-j == j-i;
}

bool geometric(double i, double j, double k){
	return k/j == j/i;
}


int main(){
	for(double i = 1; i < 20; ++i){
		for(double j = i+1; j < 20; ++j){
			for(double k = j+1; k < 20; ++k){
				if(es_primer(i) and es_primer(j) and es_primer(k) and aritmetic(i,j+2,k-2) and geometric(i,j+1,k-1))cout << k << endl;
			}
		}
	}
}
