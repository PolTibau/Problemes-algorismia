#include<iostream>
#include<vector>
using namespace std;

string s;
string cons;


char abecedari(int i){
	char marge = 'A'-1;
	char bo = marge + i;
	return bo;
}

void descodifica(int i){
	if(i > s.size())return;
	if(i == s.size()){
		cout << cons << endl;
		return;
	}
	if(s[i] == '0')return;
	cons.push_back(abecedari(s[i] - '0'));
	descodifica(i+1);
	cons.pop_back();
	if(i < s.size()-1){
		if(10*(s[i] - '0') + s[i+1] - '0' <= 26){
			cons.push_back(abecedari(10*(s[i] - '0') + s[i+1] - '0'));
			descodifica(i+2);
			cons.pop_back();
		}
	}
}


int main(){
	while(cin >> s){
		cons = "";
		descodifica(0);
		cout << "----------" << endl;
	}
}
