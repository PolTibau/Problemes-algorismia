#include<iostream>
#include<stack>
using namespace std;

void escriu(int n){
	stack<int> C;
	C.push(n);
	while(not C.empty()){
		int x = C.top();
		cout << ' ' << C.top();
		C.pop();
		if(x-1 > 0){
			C.push(x-1);
			C.push(x-1);
		}
	}
	
}

int main(){
	int n;
	while (cin >> n) {
		escriu(n);
		cout << endl;
	}
}
