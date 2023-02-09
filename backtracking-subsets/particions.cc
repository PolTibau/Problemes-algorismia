#include<iostream>
#include<vector>
using namespace std;

using conjunt = vector<string>;
using particio = vector<int>;

int n;
int m;
conjunt C;
particio P;

void print(){
	string coma = "";
	for(int i = 1; i <= m; ++i){
		cout << "subconjunt " << i << ": {";
		for(int j = 0; j < n; ++j){
			if(P[j] == i){
				cout << coma << C[j];
				coma = ",";
			}
		}
		cout << "}" << endl;
		coma = "";
	}
	cout << endl;
}


void f(int x){
	if(x == n) return print();
	for(int i = 1; i <= m; ++i){
		P[x] = i;
		f(x+1);
	}
}



int main(){
	cin >> n;
	C = conjunt(n);
	for(int i = 0; i < n; ++i)cin >> C[i];
	cin >> m;
	P = particio(n);
	f(0);
}
