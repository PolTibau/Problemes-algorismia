#include<iostream>
#include<vector>
using namespace std;


using ll = long long;

ll pisano(ll m){
	ll a = 0;
	ll b = 1;
	ll c = a+b;
	ll res = 0;
	for(int i = 0; i < m*m; ++i){
		c = (a+b)%m;
		a = b;
		b = c;
		if(a == 0 && b == 1) return res = i+1;
	}
	return 1;
}

int fibonacci(int n, int m){
	n = n%pisano(m);
	int first = 0;
	int second = 1;
	int res;
	if(n == 0) return 0;
	if(n == 1) return 1;
	for(int i = 0; i < n-1; ++i){
		res = (first+second)%m;
		first = second;
		second = res;
	}
	return res%m;
}



int main(){
	int n, m;
	while(cin >> n >> m){
		cout << fibonacci(n, m) << endl;
	}
}
