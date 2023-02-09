#include<iostream>
using namespace std;




int divisors(int n){
	int compte = 0;
	for(int i = 1; i <= n; ++i){
		if(n%i == 0)++compte;
	}
	return compte;
}


int main(){
	for(int i = 10; i < 100; ++i){
		for(int j = i+1; j < 100; ++j){
			if(i+j == 10*(j-i) and (j-i) == divisors(j))cout << j << endl << i << endl;
		}
	}
}
