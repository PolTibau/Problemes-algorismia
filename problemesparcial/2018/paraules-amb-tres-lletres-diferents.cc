#include<iostream>
#include<vector>
using namespace std;

int a, b, c;
int n;
using VI = vector<int>;
using VC = vector<char>;
VI C;
VC S;

void print(){
	for(int i = 0; i < n; ++i){
		cout << S[i];
	}
	cout << endl;
}


void f(int i){
	if(i == n) return print();
	for(int j = 0; j < 3; ++j){
		if(C[j] > 0){
			C[j]--;
			S[i] = 'a' + j;
			f(i+1);
			C[j]++;
		}
	}
}


int main(){
	while(cin >> n){
		C = VI(3);
		S = VC(n, '.');
		for(int i = 0; i < C.size(); ++i) cin >> C[i];
		f(0);
		cout << "----------" << endl;
	}
}
