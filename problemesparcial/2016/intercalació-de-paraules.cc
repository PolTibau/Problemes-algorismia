#include<iostream>
#include<vector>
#include<string>
using namespace std;

string s, t, u;
using VI = vector<int>;
using VVI = vector<VI>;
VVI M;

bool fusio_de_paraules(int i, int j){
	if(i+j > u.size()) return true;
	if(i >= s.size()){
		if(t[j] == u[i+j])return fusio_de_paraules(i, j+1);
		return false;
	}
	if(j >= t.size()){
		if(s[i] == u[i+j])return fusio_de_paraules(i+1, j);
		return false;
	}
	int& q = M[i][j];
	if(q != -1) return q;
	if(s[i] == u[i+j] and fusio_de_paraules(i+1, j))return q = 1;
	if(t[j] == u[i+j] and fusio_de_paraules(i, j+1))return q = 1;
	return q = 0;
}

int main(){
	while(cin >> s >> t >> u){
		M = VVI(s.size(), VI(t.size(), -1));
		if(fusio_de_paraules(0, 0)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
