#include<vector>
#include<iostream>
using namespace std;

int n, m, f;
using VI = vector<int>;
using VVI = vector<VI>;
VI llum;
VVI interrump;

bool res_ences(){
	for(int i = 0; i < n; ++i){
		if(llum[i] == 1)return false;
	}
	return true;
}


void apaga_encen(int k, int& compte){
	if(k == m){
		if(res_ences())compte++;
		return;
	}
	for(int i = 0; i < interrump[k].size(); ++i){
		if(llum[interrump[k][i]] == 0) llum[interrump[k][i]] = 1;
		else llum[interrump[k][i]] = 0;
	}
	apaga_encen(k+1, compte);
	for(int i = 0; i < interrump[k].size(); ++i){
		if(llum[interrump[k][i]] == 0) llum[interrump[k][i]] = 1;
		else llum[interrump[k][i]] = 0;
	}
	apaga_encen(k+1, compte);
}


int main(){
	while(cin >> n){
		llum = VI(n);
		for(int i = 0; i < n; ++i)cin >> llum[i];
		cin >> m;
		interrump = VVI(m);
		for(int i = 0; i < m; ++i){
			cin >> f;
			for(int j = 0; j < f; ++j){
				int q;
				cin >> q;
				interrump[i].push_back(q);
			}
		}
		int compte = 0;
		apaga_encen(0, compte);
		cout << compte << endl;
	}
}
