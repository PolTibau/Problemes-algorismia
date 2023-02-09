#include<iostream>
#include<vector>
using namespace std;

using multiconjunt = vector<int>;


int n, x, y, t;
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
	if(contador + (n-m)*x > t) return;
	if(t-contador > (n-m)*y) return;
	if(m == n) return print();
	else{
		for(int i = x; i <= y; ++i){
			M[m] = i;
			f(m+1, contador+i);
		}
	}
	M[m] = 0;
}


int main(){
	cin >> n >> x >> y >> t;
	M = multiconjunt(n, 0);
	f(0, 0);
}
