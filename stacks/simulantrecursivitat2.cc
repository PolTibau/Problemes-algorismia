#include<iostream>
#include<stack>
using namespace std;

void escriu(int n){
	stack<int> A, B;
	for(int i = 1; i <= n; ++i){
		B = A;
		A.push(i);
		while(not B.empty()){
			A.push(B.top());
			B.pop();
		}
	}
	while(not A.empty()){
		cout << ' ' << A.top();
		A.pop();
	}
}



int main(){
	int n;
	while (cin >> n) {
		escriu(n);
		cout << endl;
	}
}  
