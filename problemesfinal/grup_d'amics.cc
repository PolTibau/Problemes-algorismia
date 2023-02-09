#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

using VI = vector<int>;
VI amics;
VI pare;
map<string, int> M;

int repre(int i){
	if(pare[i] == i)return i;
	pare[i] = repre(pare[i]);
	return pare[i];
}

void uneix(int i, int j){
	if(repre(i) != repre(j)){
		amics[repre(i)] += amics[repre(j)];
		pare[repre(j)] = repre(i);
	}
}


int main(){
	char c;
	string s;
	while(cin >> c){
		if(c == 'F'){
			int n;
			cin >> n;
			string x;
			cin >> x;
			if(M.find(x) == M.end()){
				M[x] = pare.size();
				pare.push_back(pare.size());
				amics.push_back(1);
			}
			for(int i = 1; i < n; ++i){
				string y; 
				cin >> y;
				if(M.find(y) == M.end()){
					M[y] = pare.size();
					pare.push_back(pare.size());
					amics.push_back(1);
				}
				uneix(M[x], M[y]);
			}
		}
		else{
			cin >> s;
			if(not M.count(s))cout << s << ": error" << endl;
			else cout << s << ": " << amics[repre(M[s])] << endl;
		}
	}
}
