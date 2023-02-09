#include<iostream>
#include<vector>
using namespace std;

using control = vector<bool>;
using conjunt = vector<int>;

int n, k;
control cicle;
conjunt C;

void print(){
	cout << '(';
	string coma = "";
	for(int i = 0; i < n; ++i){
		cout << coma << C[i]+1;
		coma = ",";
	}
	cout << ')' << endl;
}


void f(int m, int inv){
	if(m == n) return print();
	int inv_loc = 0;
	for(int i = 0; i < n; ++i){
		if(cicle[i] == false){
			int sum = ((n-m-1)*(n-m-2))/2;
			if(inv + inv_loc <= k and inv + inv_loc + sum >= k){
				cicle[i] = true;
				C[m] = i;
				f(m+1, inv+inv_loc);
				cicle[i] = false;
			}
			++inv_loc;
		}
	}		
}



int main(){
	cin >> n >> k;
	C = conjunt(n);
	cicle = control(n, false);
	f(0, 0);
}
