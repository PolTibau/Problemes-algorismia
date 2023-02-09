#include<iostream>
#include<stack>
using namespace std;

void escriu(int n){
	stack<int> C;
	for(int i = 0; i <= n; ++i)C.push(i);
	int k = 1;
	while(C.top() != 0){
		cout << ' ' << C.top();
		C.pop();
		for(int j = 0; j < k; ++j){
			if(C.top() == 1) cout << ' ' << C.top();
			cout << ' ' << C.top();
			C.pop();
			
		}
		k *= 2;
	}
	
}

int main(){
	int n;
	while (cin >> n) {
		escriu(n);
		cout << endl;
	}
}
