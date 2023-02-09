#include<iostream>
#include<vector>
using namespace std;

string a, b;
int maxim;
string maxs;

bool es_mes_gran(string s, string maxs){
	for(int i = 0; i < s.size(); ++i){
		if(s[i] > maxs[i]) return false; 
		if(s[i] < maxs[i]) return true;
	}
	return true;
}

void guarda(int i, int& j){
	bool igual = true;
	string s = "";
	while(igual == true and j < b.size() and i < a.size()){
			if(b[j] == a[i]){
				s.push_back(b[j]);
				j++;
				i++;
			}
			else igual = false;
	}
	if(s.size() > maxim){
		maxim = s.size();
		maxs = s;
	}
	else if(s.size() == maxim and es_mes_gran(s, maxs)){
		maxs = s;
	}
	--j;
}



int main(){
	while(cin >> a >> b){
		maxs = "";
		maxim = 0;
		for(int i = 0; i < a.size(); ++i){
			for(int j = 0; j < b.size(); ++j){
				if(b[j] == a[i])guarda(i, j);
			}
		}
		cout << maxs << endl;
	}
}
