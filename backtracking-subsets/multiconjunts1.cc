#include<iostream>
#include<vector>
using namespace std; 

using multiconjunt = vector<int>;

int n;
int x;
multiconjunt M;

void print(){
	string coma = "";
	cout << "{";
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < M[i]; ++j){
			cout << coma << i+1;
			coma = ",";
		}
	}
	cout << "}" << endl;
}


void f(int m){
	if(m == n) return print();
	for(int i = 0; i <= x; ++i){
		M[m] += i;
		f(m+1);
		M[m] = 0;
	}
}



int main(){
	cin >> n >> x;
	M = multiconjunt(n);
	f(0);
}
