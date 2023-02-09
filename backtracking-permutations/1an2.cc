#include<iostream>
#include<vector>
using namespace std;

using control = vector<bool>;
using conjunt = vector<int>;


int n;
control cicle;
conjunt P;

void print(){
	cout << '(';
	string coma = "";
	for(int i = 0; i < n; ++i){
		cout << coma << P[i]+1;
		coma = ",";
	}
	cout << ')' << endl;
}



void f(int m, int compte){
	if(compte == n-1){
		P[m] = 0;
		return print();
	}
	for(int i = 0; i < n; ++i){
		if(cicle[i] == false and i != m){
			cicle[i] = true;
			P[m] = i;
			f(i, compte+1);
			cicle[i] = false;
		}
	}
}


int main(){
	cin >> n;
	cicle = control(n, false);
	cicle[0] = true;
	P = conjunt(n);
	f(0, 0);
}
