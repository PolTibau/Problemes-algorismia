#include<iostream>
#include<vector>
using namespace std;

using multiconjunt = vector<int>;


int n, t;
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

void f(int m, int contador){
	if(contador == t) print();
	else if(m == n-1){
		M[m] = t-contador;
		print();
	}
	else{
		for(int i = 0; i <= t-contador; ++i){
			M[m] = i;
			f(m+1, contador + i);
		}
	}
	M[m] = 0;
	
	
}


int main(){
	cin >> n >> t;
	M = multiconjunt(n);
	f(0, 0);
}
