#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
string s;
string paraula;
using VB = vector<bool>;
VB C;




void f(int i){
	if(i == n/2){
		cout << paraula << endl;
		return;
	}
	for(int k = 0; k < n; ++k){
		if(not C[k]){
			C[k] = true;
			paraula.push_back(s[k]);
			f(i+1);
			C[k] = false;
			paraula.pop_back();
		}
	}
}



int main(){
	while(cin >> n >> s){
		sort(s.begin(), s.end());
		C = VB(n, false);
		f(0);
		cout << "----------" << endl;
	}
}
