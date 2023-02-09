#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using fibonacci_numbers = vector<ll>;

int n, m;
fibonacci_numbers F;

ll fibonacci(int n){
	if(F[n] != -1) return F[n];
	ll& q = F[n];
	if(n == 1) return F[1] = 1;
	if(n == 0) return F[0] = 0;
	q = (fibonacci(n-1) + fibonacci(n-2))%m;
	return q;
}


int main(){
	while(cin >> n >> m){
		F = fibonacci_numbers(1001, -1);
		F[n] = fibonacci(n);
		cout << F[n] << endl;
	}
}
