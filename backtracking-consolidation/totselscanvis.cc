#include<iostream>
#include<vector>
using namespace std;

using combinacio = vector<int>;
using control = vector<bool>;

int n, ultim;
control Q;
combinacio M,C;
bool primer = false;


void print(){
	string coma = "";
	for(int i = 5; i >= 0; --i){
		int imp = 0;
		while(imp < C[i]){
			cout << coma << M[i];
			coma = " ";
			++imp;
		}
	}
	cout << endl;
}



void f(int m, int ultim){
	if(m == 0){
		primer = true;
		return print();
	} 
	if(m >= 50 and ultim >= 50){
		C[5]++;
		f(m-50, 50);
		Q[5] = true;
		C[5]--;
	}
	if(m >= 20 and ultim >= 20){
		C[4]++;
		f(m-20, 20);
		Q[4] = true;
		C[4]--;
	}
	if(m >= 10 and ultim >= 10){
		C[3]++;
		f(m-10, 10);
		Q[3] = true;
		C[3]--;
	}
	if(m >= 5 and ultim >= 5){
		C[2]++;
		f(m-5, 5);
		Q[2] = true;
		C[2]--;
	}
	if(m >= 2 and ultim >= 2){
		C[1]++;
		f(m-2, 2);
		Q[1] = true;
		C[1]--;
	}
	if(m >= 1 and ultim >= 1){
		C[0]++;
		f(m-1, 1);
		Q[0] = true;
		C[0]--;
	}	
}



int main(){
	while(cin >> n){
		Q = control(6);
		C = M =combinacio(6, 0);
		M[0] = 1;
		M[1] = 2;
		M[2] = 5;
		M[3] = 10;
		M[4] = 20;
		M[5] = 50;
		f(n, n);
		cout << endl;
	}
}
