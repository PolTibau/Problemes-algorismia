#include<iostream>
#include<vector>
using namespace std;


int fibonacci(int n, int m){
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
