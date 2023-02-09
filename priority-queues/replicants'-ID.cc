#include<iostream>
#include<queue>
using namespace std;

int main(){
	int m, n;
	priority_queue<int> P;
	cin >> m >> n;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		P.push(x);
	}
	priority_queue<int> prod;
	prod = P;
	while(prod.size() < m){
		
	}
}
