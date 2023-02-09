#include<iostream>
#include<vector>
using namespace std;

using VB = vector<bool>;
using VI = vector<int>;
using VVI = vector<VI>;
VVI M;
VI P;
VB Vist;
int n;

void print(){
	cout << '(';
	string coma = "";
	for(int i = 0; i < P.size(); ++i){
		cout << coma << P[i]+1;
		coma = ", ";
	}
	cout << ')' << endl;
}

void crema_cotxes(int i){
	bool trobat = false;
	for(int j = 0; j < n; ++j){
		if(M[i][j] == 1 and not Vist[j]){
			trobat  = true;
			Vist[i] = true;
			P.push_back(i);
			crema_cotxes(j);
			P.pop_back();
			Vist[i] = false;
		}
	}
	if(not trobat){
		P.push_back(i);
		print();
		P.pop_back();
	}
}


int main(){
	while(cin >> n){
		M = VVI(n, VI(n));
		P = VI(0);
		Vist = VB(n, false);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> M[i][j];
			}
		}
		crema_cotxes(0);
		cout << "--------------------" << endl;
	}
}
