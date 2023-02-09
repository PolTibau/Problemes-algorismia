#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
int maxim;
string maxs, a, b;
VI guarda;

bool es_mes_gran(string s, string maxs){
	for(int i = 0; i < s.size(); ++i){
		if(s[i] > maxs[i]) return false; 
	}
	return true;
}

string marca_s(int j){
	string s = "";
	for(int i = 0; i < j; ++i){
		s.push_back(b[j - guarda[j] + i]);
	}
	return s;
}


int main(){
	while(cin >> a >> b){
		guarda = VI(500, 0);
		maxim = 0;
		maxs = "";
		int pos = -1;
		for(int i = 0; i < a.size(); ++i){
			for(int j = 0; j < b.size(); ++j){
				if(b[j] == a[i]){
					guarda[j] = 1;
					guarda[j] += guarda[j-1];
					if(maxim < guarda[j]){
						maxim = guarda[j];
						pos = j;
						maxs = marca_s(j);
					}
					else if(maxim == guarda[j]){
						string s = marca_s(j);
						if(es_mes_gran(s, maxs)){
							maxs = s;
						}
					}
				}
			}
		}
		cout << maxs << endl;
	}
}
