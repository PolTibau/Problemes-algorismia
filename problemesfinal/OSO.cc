#include<iostream>
#include<vector>
#include<map>
using namespace std;

using D = pair<double, double>;
using VC = vector<char>;
using VVC = vector<VC>;
VVC M;

map<VVC, D> memo;

int o(VVC& M){
	int compt = 0;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(M[i][j] == '.') compt += 2;
		}
	}
	return compt;
}

bool acabat(VVC& M){
	for(int i = 0; i < 3; ++i){
		string s1;
		string s2;
		for(int j = 0; j < 3; ++j){
			s1.push_back(M[i][j]);
			s2.push_back(M[j][i]);
		}
		if(s1 == "OSO" or s2 == "OSO")return true;
	}
	return false;
}


D f(VVC& M){
	if(memo.count(M)) return memo[M];
	
	if(acabat(M)) return memo[M] = D(0,1);
	
	int opc = o(M);
	if(opc == 0) return memo[M] = D(0,0);
	
	double prob1 = 0;
	double prob2 = 0;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(M[i][j] == '.'){
				M[i][j] = 'O';
				D par = f(M);
				prob1 += par.second;
				prob2 += par.first;
				
				M[i][j] = 'S';
				par = f(M);
				prob1 += par.second;
				prob2 += par.first;
				
				M[i][j] = '.';
			}
		}
	}
	prob1 /= opc;
	prob2 /= opc;
	return memo[M] = D(prob1, prob2);
}



int main(){
	cout.setf(ios::fixed);
	cout.precision(4);
	int t;
	cin >> t;
	while(t--){
		M = VVC(3, VC(3));
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				cin >> M[i][j];
			}
		}
		D res = f(M);
		cout << res.first+1e-8 << ' ' << 1-res.first-res.second+1e-8 << ' ' << res.second+1e-8 << endl;
	}
}
