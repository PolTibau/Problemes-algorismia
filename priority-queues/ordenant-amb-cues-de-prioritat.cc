#include<iostream>
#include<queue>
using namespace std;


int main(){
	int n;
	priority_queue<int> P, V;
	while(cin >> n){
		P.push(n);
		V.push(-n);
	}
	if(P.empty())cout << endl << endl;
	while(not V.empty()){
		if(V.size() == 1) cout << -V.top() << endl;
		else cout << -V.top() << ' ';
		V.pop();
	}
	while(not P.empty()){
		if(P.size() == 1) cout << P.top() << endl;
		else cout << P.top() << ' ';
		P.pop();
	}
}
