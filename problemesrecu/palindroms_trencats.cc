#include<iostream>
#include<vector>
using namespace std;

int n, t;
string s;
string def;
using VS = vector<string>;
using VB = vector<bool>;
VS par;
VB vist;
bool una;

void borra(int i){
	for(int x = 0; x < i; ++x){
		s.pop_back();
	}
}

bool espalindrom(){
	for(int i = 0; i < t/2; ++i){
		//cout << s[i] << ' ' << s[t-1-i] << endl;
		if(s[i] != s[t-1-i])return false;
	}
	return true;
}


void troba_la_mala_puta(int k){
	if(una)return;
	if(k == n){
		if(espalindrom()){
			def = s;
			una = true;
			return;
		}
	}
	for(int i = 0; i < n; ++i){
		if(not vist[i]){
			vist[i] = true;
			s += par[i];
			troba_la_mala_puta(k+1);
			borra(par[i].size());
			vist[i] = false;
		}
	}
}




int main(){
	while(cin >> n){
		s = "";
		t = 0;
		def = "";
		una = false;
		par = VS(n);
		vist = VB(n, false);
		for(int i = 0; i < n; ++i){
			cin >> par[i];
			t += par[i].size();
		}
		troba_la_mala_puta(0);
		cout << def << endl;
	}
}
